#include "Bool.hpp"
#include <typeinfo>

Bool::Bool(bool boolean) {
    this->m_value = boolean;
}

Bool::~Bool() {
    // empty
}

bool Bool::getValue() {
    return m_value;
}

string Bool::print() const {
    if (m_value == true) {
        return "t";
    }
    return "f";
}

bool Bool::equalsTo(const BasicObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    const Bool& objectBool = dynamic_cast<const Bool&>(basicObject);
    if (objectBool.m_value == this->m_value) {
        return true;
    } else {
        return false;
    }
}
