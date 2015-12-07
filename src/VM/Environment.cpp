#include "Environment.hpp"

#include "../Objects/SchemeObject.hpp"

Environment::Environment(Environment* parent): m_parent(parent) {
    // empty
}

Environment::~Environment() {
    // empty
}

void Environment::defineVariable(string name, SchemeObject* object) {
    // TODO: Implement
}
