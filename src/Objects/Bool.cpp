/* 
 * File:   Bool.cpp
 * Author: Vojta
 * 
 * Created on 20. listopadu 2015, 10:05
 */

#include "Bool.hpp"
#include <typeinfo>
Bool::Bool(bool boolean){
    this->m_value=boolean;
}
Bool::~Bool(){}
bool Bool::getValue(){
    return m_value;
}
string Bool::print(){
    if (m_value==true) return "t";
    return "f";
}
bool Bool::equalsTo(const BasicObject& basicObject)const{
    if (typeid(*this).name() != typeid(basicObject).name()) return false;
    
    const Bool& objectBool = dynamic_cast<const Bool&>(basicObject);
    if(objectBool.m_value==this->m_value) return true;
    else return false;  

}