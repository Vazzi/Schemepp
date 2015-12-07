#ifndef __BUILT_IN_HPP__
#define __BUILT_IN_HPP__

#include <map>
#include <string>
#include <vector>

class SchemeObject;

using std::map;
using std::string;
using std::vector;

typedef vector<SchemeObject*> BuiltInArgs;
typedef SchemeObject* (*BuiltInFunc)(BuiltInArgs& args);

class BuiltInFunctions {
    public:
        static map<string, BuiltInFunc> makeMapOfAll();
};

#endif /* ifndef __BUILT_IN_HPP__ */
