#ifndef __BYTECODE_OBJECT_HPP__
#define __BYTECODE_OBJECT_HPP__

#include "../Objects/BasicObject.hpp"
#include "Bytecode.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class BytecodeObject : public BasicObject {
    public:
        BytecodeObject() {}
        virtual ~BytecodeObject() {}
        string print() const { return "#BYTECODE_OBJECT#"; }

        string name;
        vector<string> args;
        vector<string> variableNames;
        vector<BasicObject*> constants;
        vector<Instruction> instructions;
};

#endif
