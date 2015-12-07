#ifndef __VIRTUAL_MACHINE_HPP__
#define __VIRTUAL_MACHINE_HPP__

#include <stack>

class SchemeCodeObject;
class SchemeObject;
class Environment;

struct Instruction;

using std::stack;

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
    private:
        stack<ExecutionFrame> m_frameStack;
        stack<SchemeObject*> m_valuesStack;
        ExecutionFrame m_currFrame;

        Environment* createGlobalEnvironment();
        bool getNextInstruction(const SchemeCodeObject* currObject, Instruction& instr) const;

        void evalInstruction(const Instruction& instr);
        void evalConstOP();
        void evalLoadVarOP();
        void evalStoreVarOP();
        void evalDefVarOP();
        void evalFunctionOP();
        void evalPopOP();
        void evalJumpOP();
        void evalFJumpOP();
        void evalReturnOP();
        void evalCallOP();
};

#endif /* ifndef __VIRTUAL_MACHINE_HPP__ */
