#ifndef __SCHEME_BOOL_HPP__
#define __SCHEME_BOOL_HPP__

#include "SchemeBasicObject.hpp"
#include <string>

using std::string;

class SchemeBool : public SchemeBasicObject {
    public:
        SchemeBool(bool boolean);
        ~SchemeBool();
        bool getValue();
        string print() const;
        bool equalsTo(const SchemeBasicObject& basicObject) const;
    private:
        bool m_value;
};

#endif

