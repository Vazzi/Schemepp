#ifndef __NUMBER_HPP__
#define __NUMBER_HPP__

#include "BasicObject.hpp"
#include <string>

using std::string;

class Number : public BasicObject{
    public:
        Number(int value);
        ~Number();
        int getValue();
        string print() const;
        bool equalsTo(const BasicObject& basicObject) const;
    private:
        int m_value;
};

#endif
