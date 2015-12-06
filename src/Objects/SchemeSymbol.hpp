#ifndef __SCHEME_SYMBOL_HPP__
#define __SCHEME_SYMBOL_HPP__

#include "SchemeBasicObject.hpp"
#include <string>

using std::string;

class SchemeSymbol : public SchemeBasicObject{
    public:
        SchemeSymbol(string symbol);
        ~SchemeSymbol();
        string print() const;
        bool equalsTo(const SchemeBasicObject& basicObject) const;
    private:
        string m_value;
};

#endif
