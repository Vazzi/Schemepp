#ifndef __SCHEME_PAIR_HPP__
#define __SCHEME_PAIR_HPP__

#include "SchemeObject.hpp"
#include <string>

using std::string;

class SchemePair : public SchemeObject{
    public:
        SchemePair(SchemeObject *first, SchemeObject *second);
        ~SchemePair();
        SchemeObject* getFirst();
        SchemeObject* getSecond();
        void setFirst(SchemeObject *f);
        void setSecond(SchemeObject *s);

        string print() const;
        bool equalsTo(const SchemeObject& basicObject) const;
        virtual void GCMarkPointed();

    private:
        SchemeObject *m_first;
        SchemeObject *m_second;
};

#endif

