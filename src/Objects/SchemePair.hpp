#ifndef __SCHEME_PAIR_HPP__
#define __SCHEME_PAIR_HPP__

#include "SchemeBasicObject.hpp"
#include <string>

using std::string;

class SchemePair : public SchemeBasicObject{
    public:
        SchemePair(SchemeBasicObject *first, SchemeBasicObject *second);
        ~SchemePair();
        SchemeBasicObject* getFirst();
        SchemeBasicObject* getSecond();
        void setFirst(SchemeBasicObject *f);
        void setSecond(SchemeBasicObject *s);

        string print() const;
        bool equalsTo(const SchemeBasicObject& basicObject) const;
    private:
        SchemeBasicObject *m_first;
        SchemeBasicObject *m_second;
};

#endif

