#include "BuiltInFunction.hpp"

BuiltInFunction::BuiltInFunction(const string& name, BuiltInFunc function)
    :m_name(name), m_func(function) {
        // empty
    }

BuiltInFunction::~BuiltInFunction() {
    // empty
}

const string& BuiltInFunction::getName() const {
    return m_name;
}

SchemeObject* BuiltInFunction::evaluate(BuiltInArgs& args) const {
    return m_func(args);
}
