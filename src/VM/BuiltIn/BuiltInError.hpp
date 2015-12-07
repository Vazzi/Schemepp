#ifndef __BUILT_IN_ERROR_HPP__
#define __BUILT_IN_ERROR_HPP__

#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;

class BuiltInError: public runtime_error {
    public:
        BuiltInError(const string& err): runtime_error(err) {}
};

#endif /* ifndef __BUILT_IN_ERROR_HPP__ */
