#include "SchemeObject.hpp"
#include "../VM/GarbageCollector.hpp"
#include <typeinfo>
#include <iostream>

SchemeObject::SchemeObject() : m_gc_isMarked(false) {
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

void* SchemeObject::operator new(size_t size) {
    return TheGarbageCollector::Instance()->allocateObject(size);
}

void SchemeObject::operator delete(void* pointer) {
    TheGarbageCollector::Instance()->releaseObject(pointer);
}

void SchemeObject::gc_mark() {
    if (!m_gc_isMarked) {
        m_gc_isMarked = true;
        gc_markPointed();
    }
}

void SchemeObject::gc_unMark() {
    m_gc_isMarked = false;
}

bool SchemeObject::gc_isMarked() const {
    return m_gc_isMarked;
}
