#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

#include <string>
#include <tuple>

using namespace std;

enum class Type {
    Identifier,
    Int,
    Float,
    String,
    Boolean,
    Operator,
    Delimiter,
    Keyword,
    Module,
    Eof,
    Unknown
};

class Token {
    public:
        /**
         * @brief Construct a new Token object
         * 
         * @param type The type of the token
         * @param text The text of the token
         * @param position The position of the token
         */
        Token(Type type, string text, tuple<int, int> position) :
            type(type), text(text), position(position) {}

        /**
         * @brief Type getter
         *
         * @return The type of the token
         */ 
        Type get_type();

        /**
         * @brief Text getter
         *
         * @return The text of the token
         */
        string get_text();

        /**
         * @brief Position getter
         *
         * @return The position of the token
         */
        tuple<int, int> get_position();

        /**
         * @brief Get token line number
         *
         * @return The line number of the token
         */
        int get_line();

        /**
         * @brief Get token column number
         *
         * @return The column number of the token
         */
        int get_column();

        /**
         * @brief Stringify the token
         *
         * @return The stringified token
         */
        string to_string() const;

    private:
        Type type;
        string text;
        tuple<int, int> position;
};

/**
 * @brief Convert a type to a string
 *
 * @return The string representation of the type
 */
string type2str(Type type);

#endif // __TOKEN_HPP__
