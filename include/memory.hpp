#ifndef __MEMORY_HPP__
#define __MEMORY_HPP__

#include "token.hpp"

#include <string>
#include <variant>
#include <vector>
#include <map>
#include <memory>

using namespace std;

/**
 * @brief Variable type
 *
 * Variable type is used to store the type of a variable. It is used by the
 * interpreter to know the type of a variable
 */
struct variable_t {
    variant<int, float, string, bool> value;
    Type type;
};

/**
 * @brief Function type
 *
 * Function type is used to store the arguments and body of a function. It is
 * used by the interpreter to store the arguments and body of a function
 */
struct function_t {
    vector<variable_t> args;
    vector<Token> body;
};

/**
 * @brief Memory class
 *
 * Memory class is used to store variables and functions. It is used by the
 * interpreter to store the variables and functions that are created during the
 * execution of the program
 */
class Memory {
    public:
        /**
         * @brief Cast a variable to integer
         *
         * Cast a variable to integer. If the variable type does not match the
         * type to cast, the function throws an exception
         * @param var Variable to cast
         * @return int The casted variable
         * @throws runtime_error If the variable type does not match the
         * type to cast
         */
        static int cast_int(const unique_ptr<variable_t>& var);

        /**
         * @brief Cast a variable to float
         *
         * Cast a variable to float. If the variable type does not match the
         * type to cast, the function throws an exception
         * @param var Variable to cast
         * @return double The casted variable
         * @throws runtime_error If the variable type does not match the type to
         * cast
         */
        static float cast_float(const unique_ptr<variable_t>& var);

        /**
         * @brief Cast a variable to string
         *
         * Cast a variable to string. If the variable type does not match the
         * type to cast, the function throws an exception
         * @param var Variable to cast
         * @return string The casted variable
         * @throws runtime_error If the variable type does not match the type to
         * cast
         */
        static string cast_string(const unique_ptr<variable_t>& var);

        /**
         * @brief Cast a variable to boolean
         *
         * Cast a variable to boolean. If the variable type does not match the
         * type to cast, the function throws an exception
         * @param var Variable to cast
         * @return bool The casted variable
         * @throws runtime_error If the variable type does not match the type to
         * cast
         */
        static bool cast_boolean(const unique_ptr<variable_t>& var);

        /**
         * @brief Set the variable value
         * 
         * Change the value of a variable or create a new one
         * @param name Variable name
         * @param value variable value
         */
        void set_variable(const string& name, const variable_t& value);
        
        /**
         * @brief Get the variable value
         *
         * Get the value of a variable. If the variable does not exist, return
         * nullptr, otherwise return the variable value
         * @param name Variable name
         * @return unique_ptr<variable_t> Variable value
         */
        unique_ptr<variable_t> get_variable(const string& name);

        /**
         * @brief Add a function to the memory
         *
         * Add a function to the memory. If the function already exists, the
         * function throws an exception
         * @param name Function name
         * @param func Function definition (arguments and body)
         * @throws runtime_error If the function already exists
         */
        void add_function(const string& name, const function_t& func);

    private:
        map<string, variable_t> variables;
        map<string, function_t> functions;

};

#endif // __MEMORY_HPP__
