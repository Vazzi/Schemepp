#include "Environment.hpp"

#include "../Objects/SchemeObject.hpp"

Environment::Environment(Environment* parent): m_parent(parent) {
    // empty
}

Environment::~Environment() {
    m_parent = NULL;
    // TODO: Remove all variables
}

void Environment::defineVariable(const string& name, SchemeObject* value) {
    m_variables[name] = value;
}

SchemeObject* Environment::setVariable(const string& name, SchemeObject* value) {
    VariablesMap::const_iterator it = m_variables.find(name);
    if (it == m_variables.end()) {
        if (m_parent == NULL) {
            return 0;
        } else {
            return m_parent->setVariable(name, value);
        }
    } else {
        m_variables[name] = value;
        return value;
    }
}

SchemeObject* Environment::getVariable(const string& name) {
    VariablesMap::const_iterator it = m_variables.find(name);
    if (it == m_variables.end()) {
        if (m_parent == NULL) {
            return 0;
        } else {
            return m_parent->getVariable(name);
        }
    } else {
        return it->second;
    }
}

void Environment::gc_markPointed() {
    for (VariablesMap::iterator it = m_variables.begin(); it != m_variables.end(); it++) {
        it->second->gc_mark();
    }
    if (m_parent) {
        m_parent->gc_mark();
    }
}

