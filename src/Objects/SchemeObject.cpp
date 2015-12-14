#include "SchemeObject.hpp"
#include <typeinfo>
#include <iostream>

SchemeObject::SchemeObject() {
    // empty
}

SchemeObject::~SchemeObject() {
    // empty
}

string SchemeObject::print() const {
    return "#OBJECT#";
}

// Every subclass should override this
bool SchemeObject::equalsTo(const SchemeObject& object) const {
    (void)object; // For no warning of not using object
    return false;
}

bool equalObjects(const SchemeObject *first, const SchemeObject *second){
    if (first == second) {
        return true;
    } else if (typeid(*first) != typeid(*second)) {
        return false;
    } else {
        return first->equalsTo(*second);
    }
}

void SchemeObject::GCMark() {
    if (!m_isGCMarked) {
        m_isGCMarked = true;
    }
}

void SchemeObject::GCUnMark() {
    m_isGCMarked = false;
}

bool SchemeObject::isGCMarked() const {
    return m_isGCMarked;
}
