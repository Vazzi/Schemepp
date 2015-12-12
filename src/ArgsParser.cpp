#include "ArgsParser.hpp"

void throwUsageError(char* argv[]) {
    string progName = argv[0];
    throw ArgsParseError("Usage: " + progName
            + " <bytecodeFile> <outputFile(optional)> -i <inputFile(optional)>");
}

string parseByteCodeFile(int argc, char* argv[]) {
    if (argc > 1) {
        return argv[1];
    } else {
        throwUsageError(argv);
    }
    return "";
}

ParsedArgs ArgsParser::parse(int argc, char* argv[]) {
    ParsedArgs args;
    args[ArgByteCodeFileName] = parseByteCodeFile(argc, argv);
    int index = 1;
    while (++index < argc) {
        string arg = argv[index];
        if (arg == "-i") {
            if (argc > ++index) {
                args[ArgInputFileName] = argv[index];
            } else {
                throw ArgsParseError("Wrong -i argument");
            }
        } else if (index == 2) {
            args[ArgOutputFileName] = arg;
        } else {
            throwUsageError(argv);
        }
    }
    return args;
}

FILE* ArgsParser::openFile(const string fileName, const char* mode) {
    if (fileName.empty()) {
        return NULL;
    }
    FILE* file = fopen(fileName.c_str(), mode);
    if (!file) {
        throw ArgsParseError("Can not open file " + fileName);
    }
    return file;
}
