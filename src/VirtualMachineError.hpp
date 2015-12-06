#ifndef __VIRTUAL_MACHINE_ERROR_HPP__
#define __VIRTUAL_MACHINE_ERROR_HPP__

#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;

class VirtualMachineError: public runtime_error {
    public:
        VirtualMachineError(const string& err): runtime_error(err) {}
};

#endif /* ifndef __VIRTUAL_MACHINE_ERROR_HPP__ */
