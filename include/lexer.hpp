#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include "token.hpp"

#include <fstream>
#include <string>
#include <array>
#include <locale>

/**
 * @brief The keywords in the language
 */
const array<string, 11> KEYWORDS = {
    "set",
    "print",
    "add",
    "sub",
    "mul",
    "div",
    "mod",
    "equals",
    "greater",
    "less",
    "define",
};

using namespace std;

/**
 * @brief A class to read tokens from a source file
 * 
 * The lexer reads tokens from a source file and returns them one by one.
 * It also keeps track of the current line and column in the source file.
 */
class Lexer {
    public:
        /**
         * @brief Construct a new Lexer object
         *
         * @param filename The name of the file to read from
         */
        Lexer(const char* filename);

        /**
         * @brief Construct a new Lexer object
         *
         * @param filename The name of the file to read from
         */
        Lexer(const string& filename);

        /**
         * @brief Destroy the Lexer object
         */
        ~Lexer();

        /**
         * @brief Get the next token from the source file
         *
         * @return The next token
         */
        Token next_token();

    private:
        static locale loc;
        ifstream source;
        string filename;
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

        /**
         * @brief Return the type of a given identifier
         *
         * @param identifier The identifier to check
         * @return The type of the identifier
         */
        Type get_type(const string& identifier);
};

#endif // __LEXER_HPP__
