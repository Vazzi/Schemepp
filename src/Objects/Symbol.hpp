#ifndef __SYMBOL_HPP__
#define __SYMBOL_HPP__

#include "BasicObject.hpp"
#include <string>

using std::string;

class Symbol : public BasicObject{
    public:
        Symbol(string symbol);
        ~Symbol();
        string print() const;
        bool equalsTo(const BasicObject& basicObject) const;
    private:
        string m_value;
};

#endif
