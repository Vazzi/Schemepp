#include "SchemeSymbol.hpp"
#include <typeinfo>

SchemeSymbol::SchemeSymbol(std::string symbol) {
    this->m_value=symbol;
}

SchemeSymbol::~SchemeSymbol() {
    // empty
}

string SchemeSymbol::print() const{
    return m_value;
}

bool SchemeSymbol::equalsTo(const SchemeObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }

    const SchemeSymbol& objectSchemeSymbol = dynamic_cast<const SchemeSymbol&>(basicObject);

    if (objectSchemeSymbol.m_value==this->m_value) {
        return true;
    }
    return false;
}

