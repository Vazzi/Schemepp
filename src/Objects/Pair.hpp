/* 
 * File:   Pair.h
 * Author: Vojta
 *
 * Created on 20. listopadu 2015, 10:12
 */

#ifndef PAIR_H
#define	PAIR_H
#include "BasicObject.hpp"
#include <string>

using std::string;

class Pair:public BasicObject{
    public:
        Pair(BasicObject *first, BasicObject *second);
        ~Pair();
        BasicObject* getFirst();
        BasicObject* getSecond();
        void setFirst(BasicObject *f);
        void setSecond(BasicObject *s);
        
       string print();
       bool equalsTo(const BasicObject& basicObject) const;
    private:
        BasicObject *m_first;
        BasicObject *m_second;
};

#endif	/* PAIR_H */

