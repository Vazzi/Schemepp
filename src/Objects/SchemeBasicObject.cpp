#include "SchemeBasicObject.hpp"
#include <typeinfo>
#include <iostream>

SchemeBasicObject::SchemeBasicObject() {
    // empty
}

SchemeBasicObject::SchemeBasicObject(const SchemeBasicObject& orig) {
    // empty
}

SchemeBasicObject::~SchemeBasicObject() {

}

string SchemeBasicObject::print() const {
    return "#OBJECT#";
}

bool SchemeBasicObject::equalsTo(const SchemeBasicObject & basicObject) const {
    return false;
}

bool equalObjects(const SchemeBasicObject *first,const  SchemeBasicObject *second){
    if (first == second) {
        return true;
    } else if (typeid(*first) != typeid(*second)) {
        return false;
    } else {
        return first->equalsTo(*second);
    }
}
