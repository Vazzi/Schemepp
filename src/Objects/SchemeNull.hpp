#ifndef __SCHEME_NULL_HPP__
#define __SCHEME_NULL_HPP__

#include "SchemeObject.hpp"
#include <string>

using std::string;

class SchemeNull : public SchemeObject {
    public:
        SchemeNull();
        ~SchemeNull();
        string print() const;
        bool equalsTo(const SchemeObject& basicObject) const;
};

#endif
