#include "interpreter.hpp"
#include "lexer.hpp"

#include <iostream>
#include <string>

Interpreter::Interpreter(const char* source) {
    Lexer lexer(source);

    Token token = lexer.next_token();
    while(token.get_type() != Type::Eof) {
        this->tokens.push_back(token);
        token = lexer.next_token();
    }
}

void Interpreter::run() {
    for (; this->curr_tk < this->tokens.size(); this->curr_tk++) {
        Token token = this->tokens[this->curr_tk];

        if (token.get_type() == Type::Module) {
            this->import_module(token.get_text());
        }
    }

    for (
        Token token = this->tokens[this->curr_tk = 0];
        this->curr_tk < this->tokens.size();
        token = this->tokens[++this->curr_tk]
    ) {
        if (token.get_type() == Type::Keyword) {
            this->handle_keyword(token.get_text());
        }
    }
}

void Interpreter::import_module(const string& module_path) {
    Lexer lexer(
        module_path.substr(
            module_path.size() - 4, module_path.size()
        ) == ".gfy" ? module_path : module_path + ".gfy"
    );
    vector<Token> module_tokens;

    Token token = lexer.next_token();
    while(token.get_type() != Type::Eof) {
        module_tokens.push_back(token);
        token = lexer.next_token();
    }

    this->tokens.erase(next(this->tokens.begin(), this->curr_tk));
    
    this->tokens.insert(
         next(this->tokens.begin(), this->curr_tk),
         module_tokens.begin(),
         module_tokens.end()
    );
}

void Interpreter::handle_keyword(const string& keyword) {
    if (keyword == "set") {
        string var_name = this->tokens[++this->curr_tk].get_text();
        Token value_token = this->tokens[++this->curr_tk];

        // incapsulate the value of the variable inside the variable_t type
        switch (value_token.get_type()) {
            case Type::Int:
                this->memory.set_variable(
                    var_name, {stoi(value_token.get_text()), Type::Int}
                );
                break;

            case Type::Float:
                this->memory.set_variable(
                    var_name, {stof(value_token.get_text()), Type::Float}
                );
                break;

            case Type::String:
                this->memory.set_variable(
                    var_name, {value_token.get_text(), Type::String}
                );
                break;

            case Type::Boolean:
                this->memory.set_variable(
                    var_name, {value_token.get_text() == "true", Type::Boolean}
                );
                break;

            default:
                break;
        }

        Token token = this->tokens[++this->curr_tk];
        if (token.get_type() == Type::Operator) {
            token = this->tokens[++this->curr_tk];
            if (token.get_type() == value_token.get_type()) {
                auto var = this->memory.get_variable(var_name);
                this->memory.set_variable(
                    var_name,
                    {
                        var->value,
                        token.get_type(),
                        true
                    }
                );
            } else {
                throw "explicit type is different from the given value type: "
                    + type2str(token.get_type()) + " != "
                    + type2str(value_token.get_type()) + " ["
                    + token.get_file() + " " + ::to_string(token.get_line())
                    + ":" + ::to_string(token.get_column()) + "]";
            }
        } else {
            this->curr_tk--;
        }
    } else if (keyword == "print") {
        Token token = this->tokens[++this->curr_tk];

        if (token.get_type() == Type::Identifier) {
            auto var = this->memory.get_variable(token.get_text());

            switch (var->type) {
                case Type::Int:
                    cout << Memory::cast_int(var) << endl;
                    break;

                case Type::Float:
                    cout << Memory::cast_float(var) << endl;
                    break;

                case Type::String:
                    cout << Memory::cast_string(var) << endl;
                    break;

                case Type::Boolean:
                    cout << Memory::cast_boolean(var) << endl;
                    break;

                default:
                    break;
            }
        } else if (token.get_type() == Type::String) {
            cout << token.get_text() << endl;
        }else {
            throw "expected identifier, found '" + token.get_text() + "' ["
                + token.get_file() + " " + to_string(token.get_line())
                + ":" + to_string(token.get_column()) + "]";
        }
    }

}
