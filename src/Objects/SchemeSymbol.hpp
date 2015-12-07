#ifndef __SCHEME_SYMBOL_HPP__
#define __SCHEME_SYMBOL_HPP__

#include "SchemeObject.hpp"
#include <string>

using std::string;

class SchemeSymbol : public SchemeObject{
    public:
        SchemeSymbol(string symbol);
        ~SchemeSymbol();
        string print() const;
        bool equalsTo(const SchemeObject& basicObject) const;
    private:
        string m_value;
};

#endif
