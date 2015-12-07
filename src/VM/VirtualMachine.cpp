#include "VirtualMachine.hpp"

#include "../Objects/SchemeCodeObject.hpp"

VirtualMachine::VirtualMachine() {
    m_currFrame.codeObject = 0;
    m_currFrame.pc = 0;
    // TODO: Implement
    //m_frame.env = createGlobalEnvironment();
}

VirtualMachine::~VirtualMachine() {
    // empty
}

void VirtualMachine::run(SchemeCodeObject* codeObject) {
    if (codeObject == NULL) {
        return;
    }

    // Set current frame
    m_currFrame.codeObject = codeObject;
    m_currFrame.pc = 0;
}
