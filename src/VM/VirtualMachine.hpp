#ifndef __VIRTUAL_MACHINE_HPP__
#define __VIRTUAL_MACHINE_HPP__

class SchemeCodeObject;

class VirtualMachine {
    public:
        VirtualMachine() {}
        ~VirtualMachine() {}

        void run(SchemeCodeObject* bytecode);
};

#endif /* ifndef __VIRTUAL_MACHINE_HPP__ */
