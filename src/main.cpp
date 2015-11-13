#include <iostream>

using std::string;
using std::cerr;

int main(int argc, char *argv[]) {
    string fileName;

    if (argc > 1) {
        fileName = argv[1];
    } else {
        cerr << "Expecting bytcode file as argument\n";
        return 1;
    }

    try {
        // TODO: Deserialize bytecode
    } catch (...) {
        cerr << "Deserialization error: " << "\n";
        return 1;
    }

    try {
        // TODO: Run code
    } catch (...) {
        cerr << "Virtual Machine error: " << "\n";
        return 1;
    }

    return 0;
}
