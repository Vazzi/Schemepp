#include "Number.hpp"
#include <typeinfo>
#include <sstream>
#include <iostream>

using std::stringstream;

Number::Number(int number){
    this->m_value = number;
}

Number::~Number() {
    // empty
}

string Number::print() const {
    stringstream convert;
    convert << this->m_value;
    return convert.str();
}

int Number::getValue() {
    return m_value;
}

bool Number::equalsTo(const BasicObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    //dynamicke pretypovani
    const Number& objectNumber = dynamic_cast<const Number&>(basicObject);
    if (objectNumber.m_value == this->m_value) {
        return true;
    } else {
        return false;
    }
}

