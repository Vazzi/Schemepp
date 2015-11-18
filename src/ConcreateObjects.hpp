/* 
 * File:   ConcreateObjects.h
 * Author: Vojta
 *
 * Created on 18. listopadu 2015, 12:18
 */

#ifndef CONCREATEOBJECTS_HPP
#define	CONCREATEOBJECTS_HPP
#include "Object.hpp"
#include <string>

class Bool:public Object{
    public:
        Bool(bool boolean);       
        ~Bool();
        bool getValue();
        std::string print();
        bool equalsTo(const Object& object) const;
    private:
        bool value;
};

class Null : public Object{
    public:
        Null();
        ~Null();
        std::string print();
        bool equalsTo(const Object& object) const;
    private:

};

class Number : public Object{
    public:
        Number(int value);
        ~Number();
        int getValue();
        std::string print();
        bool equalsTo(const Object& object) const;
   private:
        int value;

};
class Symbol : public Object{
    public:
        Symbol(std::string symbol);
        ~Symbol();
        std::string getValue();
        bool equalsTo(const Object& object) const;
    private:
        std::string value;
};

class Pair:public Object{
    public:
        Pair(Object *first, Object *second);
        ~Pair();
        Object* getFirst();
        Object* getSecond();
        void setFirst(Object *f);
        void setSecond(Object *s);
        
       // std::string print();
       // bool equalsTo(const Object& object) const;
    private:
        Object *first;
        Object *second;
};

#endif	/* CONCREATEOBJECTS_HPP */

