#include "interpreter.hpp"

#include <iostream>
#include <cstdlib>

using namespace std;

const string VERSION = "0.0.1";

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <source file>" << endl;
        return EXIT_FAILURE;
    }

    Interpreter interpreter(argv[1]);
    try {
        interpreter.run();
    } catch (const string& error) {
        cout << "\033[1;31mError:\033[0m " << error << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


