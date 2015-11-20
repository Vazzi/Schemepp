#include "BasicObject.hpp"
#include <typeinfo>
#include <iostream>

BasicObject::BasicObject() {
    // empty
}

BasicObject::BasicObject(const BasicObject& orig) {
    // empty
}

BasicObject::~BasicObject() {

}

string BasicObject::print() const {
    return "#OBJECT#";
}

bool BasicObject::equalsTo(const BasicObject & basicObject) const {
    return false;
}

bool equalObjects(const BasicObject *first,const  BasicObject *second){
    if (first == second) {
        return true;
    } else if (typeid(*first) != typeid(*second)) {
        return false;
    } else {
        return first->equalsTo(*second);
    }
}
