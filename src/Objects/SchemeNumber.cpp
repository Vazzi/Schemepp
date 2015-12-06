#include "SchemeNumber.hpp"
#include <typeinfo>
#include <sstream>
#include <iostream>

using std::stringstream;

SchemeNumber::SchemeNumber(int number){
    this->m_value = number;
}

SchemeNumber::~SchemeNumber() {
    // empty
}

string SchemeNumber::print() const {
    stringstream convert;
    convert << this->m_value;
    return convert.str();
}

int SchemeNumber::getValue() {
    return m_value;
}

bool SchemeNumber::equalsTo(const SchemeBasicObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    //dynamicke pretypovani
    const SchemeNumber& objectNumber = dynamic_cast<const SchemeNumber&>(basicObject);
    if (objectNumber.m_value == this->m_value) {
        return true;
    } else {
        return false;
    }
}

