#ifndef __SCHEME_CODE_OBJECT_HPP__
#define __SCHEME_CODE_OBJECT_HPP__

#include "SchemeBasicObject.hpp"
#include "../Bytecode/Bytecode.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

class SchemeCodeObject : public SchemeBasicObject {
    public:
        SchemeCodeObject() {}
        ~SchemeCodeObject() {}
        string print() const { return "#CODE_OBJECT#"; }

        string name;
        vector<string> args;
        vector<string> variableNames;
        vector<SchemeBasicObject*> constants;
        vector<Instruction> instructions;
};

#endif
