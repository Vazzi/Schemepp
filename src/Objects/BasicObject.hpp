#ifndef __BASIC_OBJECT_HPP__
#define __BASIC_OBJECT_HPP__

#include <string>

using std::string;

class BasicObject {
    public:
        BasicObject();
        BasicObject(const BasicObject& orig);
        virtual ~BasicObject();
        virtual bool equalsTo(const BasicObject& basicObject) const;
        virtual string print() const;
};

#endif

