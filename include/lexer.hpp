#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include "token.hpp"

#include <fstream>
#include <string>
#include <locale>

using namespace std;

class Lexer {
    public:
        Lexer(const char* filename);
        Lexer(const string& filename);
        ~Lexer();
        Token next_token();

    private:
        static locale loc;
        ifstream source;
        string line_buff;
        size_t line, column;

        /**
         * @brief Skip blanks in the line buffer
         *
         * @return The first non-blank character
         */
        char skip_blanks();

        /**
         * @brief Pop the first character from the line buffer
         *
         * @return The first character of the line buffer
         */
        char pop_char();

        /**
         * @brief Check if the current line is an import line
         *
         * @return True if the line is an import line, false otherwise
         */
        bool is_import_line();
};

#endif // __LEXER_HPP__
