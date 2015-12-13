#include "Bytecode/Deserialization.hpp"
#include "Bytecode/DeserializationError.hpp"
#include "Objects/SchemeCodeObject.hpp"
#include "VM/VirtualMachine.hpp"
#include "VM/VirtualMachineError.hpp"
#include "ArgsParser.hpp"
#include <iostream>
#include <cstdio>

using std::string;
using std::cerr;

int main(int argc, char *argv[]) {
    ParsedArgs args;
    FILE* inFile;
    FILE* outFile;
    SchemeCodeObject* code;

    // Parse arguments
    try {
        args = ArgsParser::parse(argc, argv);
        inFile = ArgsParser::openFile(args[ArgInputFileName], "r");
        outFile = ArgsParser::openFile(args[ArgOutputFileName], "w");
    } catch (ArgsParseError& err) {
        cerr << "Arguments error: " << err.what() << "\n";
        return 1;
    }

    // Deserialization of bytecode
    try {
        Deserialization* des = new Deserialization();
        code = des->deserializeByteCode(args[ArgByteCodeFileName]);
        delete des;
    } catch (DeserializationError& err) {
        cerr << "Deserialization error: " << err.what() << "\n";
        return 1;
    }

    // Virtual machine run
    try {
        VirtualMachine* vm = new VirtualMachine();
        vm->setInputFile(inFile);
        vm->setOutputFile(outFile);
        vm->run(code);
        delete vm;
    } catch (VirtualMachineError& err) {
        cerr << "Virtual Machine error: " << err.what() << "\n";
        return 1;
    }

    // Clean
    fclose(inFile);
    fclose(outFile);

    return 0;
}
