#include "SchemeNull.hpp"
#include <typeinfo>

SchemeNull::SchemeNull() {
    // epmty
}

SchemeNull::~SchemeNull() {
    // empty
}

string SchemeNull::print() const {
    return "()";
}

bool SchemeNull::equalsTo(const SchemeObject& basicObject) const {
    if (typeid(*this).name() != typeid(basicObject).name()) {
        return false;
    }
    return true; // vzdy nastane situace: null==null a to je true
}
