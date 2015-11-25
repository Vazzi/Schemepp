#ifndef __CODE_OBJECT_HPP__
#define __CODE_OBJECT_HPP__

#include "BasicObject.hpp"
#include "../Bytecode/Bytecode.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class CodeObject : public BasicObject {
    public:
        CodeObject() {}
        ~CodeObject() {}
        string print() const { return "#CODE_OBJECT#"; }

        string name;
        vector<string> args;
        vector<string> variableNames;
        vector<BasicObject*> constants;
        vector<Instruction> instructions;
};

#endif
