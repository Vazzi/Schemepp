#ifndef __BUILT_IN_FUNCTION_HPP__
#define __BUILT_IN_FUNCTION_HPP__

#include "../../Objects/SchemeObject.hpp"
#include "BuiltIn.hpp"

class BuiltInFunction: public SchemeObject {
    public:
        BuiltInFunction(const string& name, BuiltInFunc function);
        virtual ~BuiltInFunction();

        virtual const string& getName() const;
        virtual SchemeObject* evaluate(BuiltInArgs& args) const;

    private:
        string m_name;
        BuiltInFunc m_func;
};

#endif /* ifndef __BUILT_IN_FUNCTION_HPP__ */
