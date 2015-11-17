#ifndef __DESERIALIZATION_HPP__
#define __DESERIALIZATION_HPP__

#include <string>
#include <stdexcept>

using std::string;
using std::runtime_error;

class Deserialization {
public:
    static void deserializeByteCode(const string& fileName);
};

class DeserializationError: public runtime_error {
    public:
    DeserializationError(const string& err) : runtime_error(err) {}
};

#endif

