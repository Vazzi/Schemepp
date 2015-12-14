#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include <string>
#include <map>
#include "../Objects/SchemeObject.hpp"

using std::map;
using std::string;

typedef map<string, SchemeObject*> VariablesMap;

class Environment: public SchemeObject {
    public:
        Environment(Environment* parent=0);
        ~Environment();

        void defineVariable(const string& name, SchemeObject* value);
        SchemeObject* setVariable(const string& name, SchemeObject* value);
        SchemeObject* getVariable(const string& name);
        virtual void gc_markPointed();

    private:
        Environment* m_parent;
        VariablesMap m_variables;
};

#endif /* ifndef __ENVIRONMENT_HPP__ */
