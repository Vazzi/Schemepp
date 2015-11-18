/* 
 * File:   Object.cpp
 * Author: Vojta
 * 
 * Created on 18. listopadu 2015, 11:28
 */

#include "Object.hpp"
#include <typeinfo>
#include <string>
Object::Object(){}

Object::Object(const Object& orig) {}

Object::~Object() {}
std::string Object::print(){
    return "OBJECT";
}

bool Object::equalsTo(const Object & object) const {
    return false;
}

bool equalObjects(const Object *first,const  Object *second){
    if(first==second) return true;
    else if (typeid(*first) != typeid(*second)) return false;
    else return first->equalsTo(*second);
     
}