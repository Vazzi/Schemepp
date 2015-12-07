#ifndef __SCHEME_OBJECT_HPP__
#define __SCHEME_OBJECT_HPP__

#include <string>

using std::string;

class SchemeObject {
    public:
        SchemeObject();
        virtual ~SchemeObject();
        virtual bool equalsTo(const SchemeObject& object) const;
        virtual string print() const;
};

#endif

