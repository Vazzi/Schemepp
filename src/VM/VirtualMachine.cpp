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
