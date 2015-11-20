#ifndef __BYTECODE_OBJECT_HPP__
#define __BYTECODE_OBJECT_HPP__

#include <string>
#include <vector>

using std::string;
using std::vector;

class BytecodeObject {
    public:
        BytecodeObject() {}
        ~BytecodeObject() {}

        string name;
        vector<string> args;
        vector<string> variableNames;
        vector<Object*> constants;
        vector<Instruction> instructions;

}

#endif
