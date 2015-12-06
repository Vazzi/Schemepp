#include "VirtualMachine.hpp"

#include "Objects/SchemeCodeObject.hpp"

void VirtualMachine::run(SchemeCodeObject* codeObject) {
    if (codeObject == NULL) {
        return;
    }
}
