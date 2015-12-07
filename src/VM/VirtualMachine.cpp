#include "VirtualMachine.hpp"

#include "../Objects/SchemeCodeObject.hpp"
#include "../Objects/SchemeBool.hpp"
#include "Environment.hpp"
#include "BuiltIn/BuiltIn.hpp"
#include "BuiltIn/BuiltInFunction.hpp"
#include "VirtualMachineError.hpp"
#include <cassert>

VirtualMachine::VirtualMachine() {
    m_currFrame.codeObject = 0;
    m_currFrame.pc = 0;
    m_currFrame.env = this->createGlobalEnvironment();
}

VirtualMachine::~VirtualMachine() {
    delete m_currFrame.env;
}


void VirtualMachine::run(SchemeCodeObject* codeObject) {
    if (codeObject == NULL) {
        return;
    }

    // Set current frame
    m_currFrame.codeObject = codeObject;
    m_currFrame.pc = 0;

    while(true) {
        // Get instruction
        Instruction instr;
        if (this->getNextInstruction(instr)) {
            m_currFrame.pc++;
        } else {
            break; // Last instruction, we are done
        }
        // Evaluate instruction
        this->evalInstruction(instr);
    }
}

Environment* VirtualMachine::createGlobalEnvironment() {
    Environment* env = new Environment();

    // Define all built in functions
    BuiltInMap builtIns = mapOfAllBuiltIns();
    for (BuiltInMap::const_iterator it = builtIns.begin();
            it != builtIns.end(); ++it) {
        SchemeObject* func = new BuiltInFunction(it->first, it->second);
        m_currFrame.env->defineVariable(it->first, func);
    }

    return env;
}

bool VirtualMachine::getNextInstruction(Instruction& instr) const {
    if (m_currFrame.pc >= m_currFrame.codeObject->instructions.size()) {
        if (m_frameStack.size() == 0) {
            return false;
        } else {
            throw VirtualMachineError("Code ended prematurely");
        }
    } else {
        instr = m_currFrame.codeObject->instructions[m_currFrame.pc];
    }
    return true;
}

void VirtualMachine::evalInstruction(const Instruction& instr) {
    switch (instr.opCode) {
        case OP_CONST:
            this->evalConstOP(instr.arg);
            break;
        case OP_LOADVAR:
            this->evalLoadVarOP(instr.arg);
            break;
        case OP_STOREVAR:
            this->evalStoreVarOP(instr.arg);
            break;
        case OP_DEFVAR:
            this->evalDefVarOP(instr.arg);
            break;
        case OP_FUNCTION:
            this->evalFunctionOP(instr.arg);
            break;
        case OP_POP:
            this->evalPopOP();
            break;
        case OP_JUMP:
            this->evalJumpOP(instr.arg);
            break;
        case OP_FJUMP:
            this->evalFJumpOP(instr.arg);
            break;
        case OP_RETURN:
            this->evalReturnOP();
            break;
        case OP_CALL:
            this->evalCallOP(instr.arg);
            break;
        case OP_INVALID:
        default:
            char *err = new char;
            sprintf(err, "Invalid instruction operation code 0x%02X", instr.opCode);
            string text = string(err);
            throw VirtualMachineError(text);
    }
}

void VirtualMachine::evalConstOP(const unsigned int& instrArg) {
    SchemeObject* value = m_currFrame.codeObject->constants[instrArg];
    m_valuesStack.push(value);
}

void VirtualMachine::evalLoadVarOP(const unsigned int& instrArg) {
    (void)instrArg;
    // TODO: Implement
}

void VirtualMachine::evalStoreVarOP(const unsigned int& instrArg) {
    (void)instrArg;
    // TODO: Implement
}

void VirtualMachine::evalDefVarOP(const unsigned int& instrArg) {
    (void)instrArg;
    // TODO: Implement
}

void VirtualMachine::evalFunctionOP(const unsigned int& instrArg) {
    (void)instrArg;
    // TODO: Implement
}

void VirtualMachine::evalPopOP() {
    // TODO: Implement
}

void VirtualMachine::evalJumpOP(const unsigned int& instrArg) {
    m_currFrame.pc = instrArg;
}

void VirtualMachine::evalFJumpOP(const unsigned int& instrArg) {
    assert(!m_valuesStack.empty() && "Values stack is empty");
    SchemeBool* predicate = dynamic_cast<SchemeBool*>(m_valuesStack.top());
    m_valuesStack.pop();
    if (predicate && !predicate->getValue()) {
        m_currFrame.pc = instrArg;
    }
}

void VirtualMachine::evalReturnOP() {
    assert(!m_frameStack.empty() && "Frame stack is empty");
    m_currFrame = m_frameStack.top();
    m_frameStack.pop();
}

void VirtualMachine::evalCallOP(const unsigned int& instrArg) {
    (void)instrArg;
    // TODO: Implement
}
