#ifndef __SCHEME_BOOL_HPP__
#define __SCHEME_BOOL_HPP__

#include "SchemeObject.hpp"
#include <string>

using std::string;

class SchemeBool : public SchemeObject {
    public:
        SchemeBool(bool boolean);
        ~SchemeBool();
        bool getValue();
        string print() const;
        bool equalsTo(const SchemeObject& basicObject) const;
    private:
        bool m_value;
};

#endif

