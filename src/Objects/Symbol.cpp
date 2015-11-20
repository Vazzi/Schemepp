/* 
 * File:   Symbol.cpp
 * Author: Vojta
 * 
 * Created on 20. listopadu 2015, 10:10
 */

#include "Symbol.hpp"
#include <typeinfo>
Symbol::Symbol(std::string symbol){
    this->m_value=symbol;
}

Symbol::~Symbol(){}

string Symbol::print(){
    return m_value;
}


bool Symbol::equalsTo(const BasicObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) return false;
    
    const Symbol& objectSymbol = dynamic_cast<const Symbol&>(basicObject);
    
    if(objectSymbol.m_value==this->m_value) return true;
    return false;  
}

