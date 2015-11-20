#ifndef __NULL_HPP__
#define __NULL_HPP__

#include "BasicObject.hpp"
#include <string>

using std::string;

class Null : public BasicObject {
    public:
        Null();
        ~Null();
        string print() const;
        bool equalsTo(const BasicObject& basicObject) const;
};

#endif
