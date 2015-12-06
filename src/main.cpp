#include <iostream>

#include "Bytecode/Deserialization.hpp"
#include "Bytecode/DeserializationError.hpp"
#include "Objects/SchemeCodeObject.hpp"

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

    SchemeCodeObject* code;

    try {
        Deserialization* des = new Deserialization();
        code = des->deserializeByteCode(fileName);
        delete des;
    } catch (DeserializationError& err) {
        cerr << "Deserialization error: " << err.what() << "\n";
        return 1;
    }

    try {
        // TODO: Run code using code variable from previous deserialization
    } catch (...) {
        cerr << "Virtual Machine error: " << "\n";
        return 1;
    }

    return 0;
}
