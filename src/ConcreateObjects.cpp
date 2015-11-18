/* 
 * File:   ConcreateObjects.cpp
 * Author: Vojta
 * 
 * Created on 18. listopadu 2015, 12:18
 */
#include "ConcreateObjects.hpp"
#include "Object.hpp"
#include <string>
#include <sstream>
#include <typeinfo>
#include <iostream>


/*      Bool        */
Bool::Bool(bool boolean){
    this->value=boolean;
}
Bool::~Bool(){}
bool Bool::getValue(){
    return value;
}
std::string Bool::print(){
    if (value==true) return "t";
    return "f";
}
bool Bool::equalsTo(const Object& object)const{
    if (typeid(*this).name() != typeid(object).name()) return false;
    
    const Bool& objectBool = dynamic_cast<const Bool&>(object);
    if(objectBool.value==this->value) return true;
    else return false;  

}

/*      Null        */
Null::Null(){}
Null::~Null(){}
std::string Null::print(){
    return "()";
}
bool Null::equalsTo(const Object& object)const{
    if (typeid(*this).name() != typeid(object).name()) return false;
    return true; // vzdy nastane situace: null==null a to je true 

}

/*      Number        */
Number::Number(int number){
    this->value=number;
}
Number::~Number(){}

std::string Number::print(){    
    std::stringstream convert;
    convert << this->value;   
    return convert.str();
}

int Number::getValue(){
    return value;
}

//dynamicke pretypovani
bool Number::equalsTo(const Object& object) const {    
    std::cout << "prvni: " << typeid(*this).name() << ", druhy:" << typeid(object).name()<<std::endl; 
    if (typeid(*this).name() != typeid(object).name()) {
        return false;
    }
    
    const Number& objectNumber = dynamic_cast<const Number&>(object);
    if(objectNumber.value==this->value) return true;
    else return false; 
    
}

/*      Symbol        */
Symbol::Symbol(std::string symbol){
    this->value=symbol;
}
Symbol::~Symbol(){}

std::string Symbol::getValue(){
    return value;
}

bool Symbol::equalsTo(const Object& object) const {
    if (typeid(*this).name() != typeid(object).name()) return false;
    
    const Symbol& objectSymbol = dynamic_cast<const Symbol&>(object);
    if(objectSymbol.value==this->value) return true;
    else return false;  
}

/*      Pair        */
Pair::Pair(Object *first, Object *second){}
Pair::~Pair(){}

Object* Pair::getFirst(){
    return this->first;
}
Object* Pair::getSecond(){
    return this->second;
}
void Pair::setFirst(Object *f){
    this->first=f;
}
void Pair::setSecond(Object *s){
    this->second=s;
}
/*
std::string Pair::print(){}


bool equalPairs(const Object* first,const Object* second){
    std::cout << "2. "<<std::endl;
    if(first==second){
        return true;
    }

    else if(typeid(*first).name() != typeid(*second).name()){
        return false;   
    }
    return true;

    return first->equalsTo(*second);

}
bool Pair::equalsTo(const Object& object) const{
    if (typeid(*this).name() != typeid(object).name()) 
        return false;
    std::cout << "1. "<<std::endl;
    const Pair& objectPair = static_cast<const Pair&>(object);
    if(equalPairs(this->first,objectPair.first) && (equalPairs(this->second,objectPair.second)))
        return true;
    return false;

}
 
*/