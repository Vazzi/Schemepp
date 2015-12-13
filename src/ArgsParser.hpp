#ifndef __ARGUMENTS_PARSER_HPP__
#define __ARGUMENTS_PARSER_HPP__

#include <stdexcept>
#include <iostream>
#include <map>
#include <cstdio>
using std::runtime_error;
using std::string;
using std::map;

class ArgsParseError: public runtime_error {
    public:
        ArgsParseError(const string& err): runtime_error(err) {}
};

enum argsIdentifiers_t {
    ArgByteCodeFileName = 0,
    ArgOutputFileName,
    ArgInputFileName
};

typedef map<argsIdentifiers_t, string> ParsedArgs;

class ArgsParser {
    public:
        static ParsedArgs parse(int argc, char* argv[]);
        static FILE* openFile(const string fileName, const char* mode);
};

#endif /* ifndef __ARGUMENTS_PARSER_HPP__ */
