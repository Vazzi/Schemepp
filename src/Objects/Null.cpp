#include "Null.hpp"
#include <typeinfo>

Null::Null() {
    // epmty
}

Null::~Null() {
    // empty
}

string Null::print() const {
    return "()";
}

bool Null::equalsTo(const BasicObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    return true; // vzdy nastane situace: null==null a to je true
}
