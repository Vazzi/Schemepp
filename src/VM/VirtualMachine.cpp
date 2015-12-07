#include "VirtualMachine.hpp"

#include "../Objects/SchemeCodeObject.hpp"
#include "Environment.hpp"
#include "BuiltIn/BuiltIn.hpp"
#include "BuiltIn/BuiltInFunction.hpp"
#include "VirtualMachineError.hpp"

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
        SchemeCodeObject* currObject = m_currFrame.codeObject;

        // Get instruction
        Instruction instr;
        if (this->getNextInstruction(currObject, instr)) {
            m_currFrame.pc++;
        } else {
            break; // Last instruction, we are done
        }

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

bool VirtualMachine::getNextInstruction(const SchemeCodeObject* currObject,
        Instruction& instr) const {
    if (m_currFrame.pc >= currObject->instructions.size()) {
        if (m_frameStack.size() == 0) {
            return false;
        } else {
            throw VirtualMachineError("Code ended prematurely");
        }
    } else {
        instr = currObject->instructions[m_currFrame.pc];
    }
    return true;
}

void VirtualMachine::evalInstruction(const Instruction& instr) {
    switch (instr.opCode) {
        case OP_CONST:
            this->evalConstOP();
            break;
        case OP_LOADVAR:
            this->evalLoadVarOP();
            break;
        case OP_STOREVAR:
            this->evalStoreVarOP();
            break;
        case OP_DEFVAR:
            this->evalDefVarOP();
            break;
        case OP_FUNCTION:
            this->evalFunctionOP();
            break;
        case OP_POP:
            this->evalPopOP();
            break;
        case OP_JUMP:
            this->evalJumpOP();
            break;
        case OP_FJUMP:
            this->evalFJumpOP();
            break;
        case OP_RETURN:
            this->evalReturnOP();
            break;
        case OP_CALL:
            this->evalCallOP();
            break;
        case OP_INVALID:
        default:
            char *err = new char;
            sprintf(err, "Invalid instruction operation code 0x%02X", instr.opCode);
            string text = string(err);
            throw VirtualMachineError(text);
    }
}

void VirtualMachine::evalConstOP() {
    // TODO: Implement
}

void VirtualMachine::evalLoadVarOP() {
    // TODO: Implement
}

void VirtualMachine::evalStoreVarOP() {
    // TODO: Implement
}

void VirtualMachine::evalDefVarOP() {
    // TODO: Implement
}

void VirtualMachine::evalFunctionOP() {
    // TODO: Implement
}

void VirtualMachine::evalPopOP() {
    // TODO: Implement
}

void VirtualMachine::evalJumpOP() {
    // TODO: Implement
}

void VirtualMachine::evalFJumpOP() {
    // TODO: Implement
}

void VirtualMachine::evalReturnOP() {
    // TODO: Implement
}

void VirtualMachine::evalCallOP() {
    // TODO: Implement
}
