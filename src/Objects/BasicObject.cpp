/* 
 * File:   BasicObject.cpp
 * Author: Vojta
 * 
 * Created on 20. listopadu 2015, 10:01
 */

#include "BasicObject.hpp"
#include <typeinfo>
#include <iostream>


BasicObject::BasicObject(){}

BasicObject::BasicObject(const BasicObject& orig) {}

BasicObject::~BasicObject() {}

std::string BasicObject::print(){
    return "#OBJECT#";
}

bool BasicObject::equalsTo(const BasicObject & basicObject) const {
    return false;
}

bool equalObjects(const BasicObject *first,const  BasicObject *second){
    if(first==second) return true;
    else if (typeid(*first) != typeid(*second)) return false;
    else return first->equalsTo(*second);
     
}