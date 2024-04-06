#include "lexer.hpp"

#include <iostream>
#include <codecvt>
#include <cctype>

using namespace std;

locale Lexer::loc = locale(locale(), new codecvt_utf8<wchar_t>);

Lexer::Lexer(const char* filename) {
    this->source.open(filename);

    if (!this->source.is_open()) {
        throw runtime_error("Could not open file");
    }

    this->line_buff = "";
    this->line = 0;
    this->column = 0;
}

Lexer::Lexer(const string& filename) {
    this->source.open(filename);

    if (!this->source.is_open()) {
        throw runtime_error("Could not open file");
    }

    this->line_buff = "";
    this->line = 1;
    this->column = 1;
}

Lexer::~Lexer() {
    this->source.close();
}

Token Lexer::next_token() {
    // Check if we have reached the end of the file
    if (this->source.eof()) {
        return Token(Type::Eof, "", make_tuple(this->line, this->column));
    }

    // Skip to the next line if the current line is empty
    if (this->line_buff.empty()) {
        getline(this->source, this->line_buff);
        this->line++;
        this->column = 1;
    }

    char current_char;
    string identifier = "";

    // Handle module imports
    if (this->is_import_line()) {
        current_char = this->skip_blanks();

        while (isalnum(current_char) || current_char == '/') {
            identifier += current_char;
            current_char = this->pop_char();
        }

        return Token(Type::Module, identifier,
                make_tuple(this->line, this->column-identifier.size()));
    } else {
        current_char = this->skip_blanks();
    }

    // Check for identifiers
    if (isalpha(current_char)) {
        while (isalnum(current_char)) {
            identifier += current_char;
            current_char = this->pop_char();
        }

        return Token(Type::Identifier, identifier,
                make_tuple(this->line, this->column-identifier.size()));
    } else if (isdigit(current_char)) {
        bool is_float = false;

        while (current_char == '.' || isdigit(current_char)) {
            if (current_char == '.') {
                if (is_float) {
                    break;
                }

                is_float = true;
            }

            identifier += current_char;
            current_char = this->pop_char();
        }

        return Token(is_float ? Type::Float : Type::Int, identifier,
                make_tuple(this->line, this->column-identifier.size()));
    } else if (current_char == '"') {
        current_char = this->line_buff[this->column];

        while (current_char != '"') {
            identifier += current_char;
            current_char = this->pop_char();
        }

        return Token(Type::String, identifier,
                make_tuple(this->line, this->column-identifier.size()));
    } else if (current_char == '(' || ')') {
        return Token(Type::Delimiter, string(1, current_char),
                make_tuple(this->line, this->column));
    } else if (current_char == '/') {
        current_char = this->line_buff.front();

        if (current_char == '/') {
            this->line_buff = "";
            return this->next_token();
        }
    }
    
    return Token(Type::Unknown, string(1, current_char),
            make_tuple(this->line, this->column));
}

char Lexer::skip_blanks() {
    char current_char = ' ';

    while (isblank(current_char)) {
        current_char = this->pop_char();
    }

    return current_char;
}

char Lexer::pop_char() {
    char current_char = this->line_buff.front();
    this->line_buff.erase(0, 1);
    this->column++;

    return current_char;
}

bool Lexer::is_import_line() {
    // I know, it's deprecated, but it's the only way to convert C++ string to
    // wstring. I HATE C++ WIDE STRINGS SO MUCH, I WANT TO DIE (o_O) o-- ()___)
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
    wstring wide_line = converter.from_bytes(this->line_buff);

    if (wide_line.find(L"£import") == 0) {
        this->line_buff.erase(0, 8);
        return true;
    }

    return false;
}
