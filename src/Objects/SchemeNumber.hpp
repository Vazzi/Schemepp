#ifndef __SCHEME_NUMBER_HPP__
#define __SCHEME_NUMBER_HPP__

#include "SchemeBasicObject.hpp"
#include <string>

using std::string;

class SchemeNumber : public SchemeBasicObject{
    public:
        SchemeNumber(int value);
        ~SchemeNumber();
        int getValue();
        string print() const;
        bool equalsTo(const SchemeBasicObject& basicObject) const;
    private:
        int m_value;
};

#endif
