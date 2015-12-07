#ifndef __SCHEME_CODE_OBJECT_HPP__
#define __SCHEME_CODE_OBJECT_HPP__

#include "SchemeObject.hpp"
#include "../Bytecode/Bytecode.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class SchemeCodeObject : public SchemeObject {
    public:
        SchemeCodeObject() {}
        ~SchemeCodeObject() {}
        string print() const { return "#CODE_OBJECT#"; }

        string name;
        vector<string> args;
        vector<string> variableNames;
        vector<SchemeObject*> constants;
        vector<Instruction> instructions;
};

#endif
