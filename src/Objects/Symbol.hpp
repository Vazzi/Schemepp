/* 
 * File:   Symbol.h
 * Author: Vojta
 *
 * Created on 20. listopadu 2015, 10:10
 */

#ifndef SYMBOL_HP
#define	SYMBOL_HP
#include "BasicObject.hpp"
#include <string>

using std::string;

class Symbol : public BasicObject{
    public:
        Symbol(string symbol);
        ~Symbol();
        string print();
        bool equalsTo(const BasicObject& basicObject) const;
    private:
        string m_value;
};
#endif	/* SYMBOL_HPP */

