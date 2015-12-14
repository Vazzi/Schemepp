#include "SchemeFunction.hpp"

#include "SchemeCodeObject.hpp"
#include "../VM/Environment.hpp"

SchemeFunction::SchemeFunction(SchemeCodeObject* codeObject, Environment* env)
    : codeObject(codeObject), env(env) {
        // empty
    }

SchemeFunction::~SchemeFunction() {
    // empty
}

string SchemeFunction::print() const {
    return "<function " + codeObject->name + ">";
}

void SchemeFunction::gc_markPointed() {
    codeObject->gc_mark();
    env->gc_mark();
}
