#include "token.hpp"
#include "lexer.hpp"

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

    return EXIT_SUCCESS;
}
