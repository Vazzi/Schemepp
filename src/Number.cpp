/* 
 * File:   Number.cpp
 * Author: Vojta
 * 
 * Created on 20. listopadu 2015, 10:09
 */

#include "Number.hpp"
#include <typeinfo>
#include <sstream>
#include <iostream>

Number::Number(int number){
    this->m_value=number;
}
Number::~Number(){}

string Number::print(){    
    std::stringstream convert;
    convert << this->m_value;   
    return convert.str();
}

int Number::getValue(){
    return m_value;
}


bool Number::equalsTo(const BasicObject& basicObject) const {    
    //std::cout << "prvni: " << typeid(*this).name() << ", druhy:" << typeid(basicObject).name()<<std::endl; 
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    //dynamicke pretypovani
    const Number& objectNumber = dynamic_cast<const Number&>(basicObject);
    if(objectNumber.m_value==this->m_value) return true;
    else return false;     
}

