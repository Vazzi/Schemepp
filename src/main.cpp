#include <iostream>

#include "Deserialization.hpp"
#include "DeserializationError.hpp"

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
        Deserialization::deserializeByteCode(fileName);
        // TODO: Save deserialized code
    } catch (DeserializationError& err) {
        cerr << "Deserialization error: " << err.what() << "\n";
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
