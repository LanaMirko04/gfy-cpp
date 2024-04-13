#include "token.hpp"
#include "lexer.hpp"
#include "memory.hpp"

#include <iostream>

using namespace std;

const string VERSION = "0.0.1";

int main(int argc, char* argv[]) {
    cout << "GFY interpreter - v" << VERSION << endl; 
    
    Lexer lexer("examples/test.gfy");
    Token token = lexer.next_token();

    while (token.get_type() != Type::Eof) {
        cout << token.to_string() << endl;
        token = lexer.next_token();
    }

    float tmp = 10.5;

    // Test Memory
    Memory memory;
    memory.set_variable("x", variable_t{10, Type::Int});
    memory.set_variable("y", variable_t{tmp, Type::Float});
    memory.set_variable("z", variable_t{"Hello, World!", Type::String});
    memory.set_variable("a", variable_t{true, Type::Boolean});

    cout << "x = " << Memory::cast_int(memory.get_variable("x"))<< endl;
    cout << "y = " << Memory::cast_float(memory.get_variable("y")) << endl;
    cout << "z = " << Memory::cast_string(memory.get_variable("z")) << endl;
    cout << "a = " << Memory::cast_boolean(memory.get_variable("a")) << endl;

    return EXIT_SUCCESS;
}
