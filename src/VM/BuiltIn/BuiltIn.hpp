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
typedef map<string, BuiltInFunc> BuiltInMap;

BuiltInMap mapOfAllBuiltIns();

#endif /* ifndef __BUILT_IN_HPP__ */
