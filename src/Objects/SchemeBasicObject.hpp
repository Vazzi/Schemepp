#ifndef __SCHEME_BASIC_OBJECT_HPP__
#define __SCHEME_BASIC_OBJECT_HPP__

#include <string>

using std::string;

class SchemeBasicObject {
    public:
        SchemeBasicObject();
        SchemeBasicObject(const SchemeBasicObject& orig);
        virtual ~SchemeBasicObject();
        virtual bool equalsTo(const SchemeBasicObject& basicObject) const;
        virtual string print() const;
};

#endif

