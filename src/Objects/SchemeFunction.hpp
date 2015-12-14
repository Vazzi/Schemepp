#ifndef __SCHEME_FUNCTION_HPP__
#define __SCHEME_FUNCTION_HPP__

#include "SchemeObject.hpp"
#include <string>

class Environment;
class SchemeCodeObject;

using std::string;

class SchemeFunction : public SchemeObject {
    public:
        SchemeFunction(SchemeCodeObject* codeObject, Environment* env);
        ~SchemeFunction();

        string print() const;

        SchemeCodeObject* codeObject;
        Environment* env;

        virtual void GCMarkPointed();
};

#endif /* ifndef __SCHEME_FUNCTION_HPP__ */
