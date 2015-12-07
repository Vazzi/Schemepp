#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include <string>
#include <map>

using std::map;
using std::string;

class SchemeObject;

class Environment {
    public:
        Environment(Environment* parent=0);
        ~Environment();

        void defineVariable(string name, SchemeObject* object);
    private:
        Environment* m_parent;
        map<string, SchemeObject*> m_variables;
};

#endif /* ifndef __ENVIRONMENT_HPP__ */
