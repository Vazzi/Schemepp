#ifndef __DESERIALIZTION_ERROR_HPP__
#define __DESERIALIZTION_ERROR_HPP__

#include <stdexcept>
#include <string>

using std::runtime_error;
using std::string;

class DeserializationError: public runtime_error {
    public:
        DeserializationError(const string& err): runtime_error(err) {}
};

#endif
