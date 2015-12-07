#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include <string>
#include <map>

using std::map;
using std::string;

class SchemeObject;

typedef map<string, SchemeObject*> VariablesMap;

class Environment {
    public:
        Environment(Environment* parent=0);
        ~Environment();

        void defineVariable(const string& name, SchemeObject* value);
        SchemeObject* setVariable(const string& name, SchemeObject* value);
        SchemeObject* getVariable(const string& name);

    private:
        Environment* m_parent;
        VariablesMap m_variables;
};

#endif /* ifndef __ENVIRONMENT_HPP__ */
