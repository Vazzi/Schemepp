#ifndef __SCHEME_NULL_HPP__
#define __SCHEME_NULL_HPP__

#include "SchemeBasicObject.hpp"
#include <string>

using std::string;

class SchemeNull : public SchemeBasicObject {
    public:
        SchemeNull();
        ~SchemeNull();
        string print() const;
        bool equalsTo(const SchemeBasicObject& basicObject) const;
};

#endif
