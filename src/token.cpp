#include "token.hpp"

using namespace std;

string Token::to_string() const {
    return "{type: " + type2str(this->type) + ", text: " + this->text
        + ", position: "+  this->file + " {"
        + ::to_string(get<0>(this->position)) + ", "
        + ::to_string(get<1>(this->position)) + "}}"; 
}

Type Token::get_type() {
    return this->type;
}

string Token::get_text() {
    return this->text;
}

string Token::get_file() {
    return this->file;
}

tuple<int, int> Token::get_position() {
    return this->position;
}

int Token::get_line() {
    return get<0>(this->position);
}

int Token::get_column() {
    return get<1>(this->position);
}

string type2str(Type type) {
    switch (type) {
        case Type::Module:
            return "Module";
        case Type::Keyword:
            return "Keyword";
        case Type::Identifier:
            return "Identifier";
        case Type::Operator:
            return "Operator";
        case Type::Parenthesis:
            return "Parenthesis";
        case Type::Bracket:
            return "Bracket";
        case Type::Int:
            return "Int";
        case Type::Float:
            return "Float";
        case Type::String:
            return "String";
        case Type::Boolean:
            return "Boolean";
        case Type::List:
            return "List";
        case Type::Eof:
            return "Eof";
        case Type::Unknown:
            return "Unknown";
    }
}
