/* 
 * File:   ConcreateObjects.h
 * Author: Vojta
 *
 * Created on 18. listopadu 2015, 12:18
 */

#ifndef CONCREATEOBJECTS_H
#define	CONCREATEOBJECTS_H
#include "Object.hpp"

class Bool:public Object{
    public:
        Bool();       
        virtual ~Bool();
        
    private:
    
};

class Null : public Object{
    public:
        Null();
        virtual ~Null();
    private:

};

class Number : public Object{
    public:
        Number();
        virtual ~Number();
    private:

};
class Symbol : public Object{
    public:
        Symbol();
        virtual ~Symbol();
    private:

};

class Pair:public Object{
    public:
        Pair();
        virtual ~Pair();
    private:

};

#endif	/* CONCREATEOBJECTS_H */

