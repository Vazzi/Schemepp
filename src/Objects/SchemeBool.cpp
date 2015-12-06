#include "SchemeBool.hpp"
#include <typeinfo>

SchemeBool::SchemeBool(bool boolean) {
    this->m_value = boolean;
}

SchemeBool::~SchemeBool() {
    // empty
}

bool SchemeBool::getValue() {
    return m_value;
}

string SchemeBool::print() const {
    if (m_value == true) {
        return "t";
    }
    return "f";
}

bool SchemeBool::equalsTo(const SchemeBasicObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    const SchemeBool& objectSchemeBool = dynamic_cast<const SchemeBool&>(basicObject);
    if (objectSchemeBool.m_value == this->m_value) {
        return true;
    } else {
        return false;
    }
}
