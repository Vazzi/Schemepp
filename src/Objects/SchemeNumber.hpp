#ifndef __SCHEME_NUMBER_HPP__
#define __SCHEME_NUMBER_HPP__

#include "SchemeObject.hpp"
#include <string>

using std::string;

class SchemeNumber : public SchemeObject{
    public:
        SchemeNumber(int value);
        ~SchemeNumber();
        int getValue();
        string print() const;
        bool equalsTo(const SchemeObject& basicObject) const;
    private:
        int m_value;
};

#endif
