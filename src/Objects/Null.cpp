/* 
 * File:   Null.cpp
 * Author: Vojta
 * 
 * Created on 20. listopadu 2015, 10:07
 */

#include "Null.hpp"
#include <typeinfo>


Null::Null(){}
Null::~Null(){}
string Null::print(){
    return "()";
}
bool Null::equalsTo(const BasicObject& basicObject)const{
    if (typeid(*this).name() != typeid(basicObject).name()) return false;
    return true; // vzdy nastane situace: null==null a to je true 

}