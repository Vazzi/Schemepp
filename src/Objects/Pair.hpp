#ifndef __PAIR_HPP__
#define __PAIR_HPP__

#include "BasicObject.hpp"
#include <string>

using std::string;

class Pair : public BasicObject{
    public:
        Pair(BasicObject *first, BasicObject *second);
        ~Pair();
        BasicObject* getFirst();
        BasicObject* getSecond();
        void setFirst(BasicObject *f);
        void setSecond(BasicObject *s);

        string print() const;
        bool equalsTo(const BasicObject& basicObject) const;
    private:
        BasicObject *m_first;
        BasicObject *m_second;
};

#endif

