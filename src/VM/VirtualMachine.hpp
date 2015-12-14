#ifndef __VIRTUAL_MACHINE_HPP__
#define __VIRTUAL_MACHINE_HPP__

#include <vector>
#include <iostream>

class SchemeCodeObject;
class SchemeObject;
class Environment;

struct Instruction;

using std::vector;
using std::string;

struct ExecutionFrame {
    SchemeCodeObject* codeObject;
    unsigned int pc; // Program counter - which instruction is next to execute
    Environment* env; // Current environment
};

class VirtualMachine {
    public:
        VirtualMachine();
        ~VirtualMachine();

        void run(SchemeCodeObject* bytecode);

        void setInputFile(FILE* file);
        void setOutputFile(FILE* file);

        void GCMarkRoots();
    private:
        vector<ExecutionFrame> m_frameStack;
        vector<SchemeObject*> m_valuesStack; // Can not be stack because we need to iterate (Mark for GC)
        ExecutionFrame m_currFrame;

        Environment* createGlobalEnvironment();
        bool getNextInstruction(Instruction& instr) const;

        void evalInstruction(const Instruction& instr);
        void evalConstOP(const unsigned int& instrArg);
        void evalLoadVarOP(const unsigned int& instrArg);
        void evalStoreVarOP(const unsigned int& instrArg);
        void evalDefVarOP(const unsigned int& instrArg);
        void evalFunctionOP(const unsigned int& instrArg);
        void evalPopOP();
        void evalJumpOP(const unsigned int& instrArg);
        void evalFJumpOP(const unsigned int& instrArg);
        void evalReturnOP();
        void evalCallOP(const unsigned int& instrArg);
};

#endif /* ifndef __VIRTUAL_MACHINE_HPP__ */
