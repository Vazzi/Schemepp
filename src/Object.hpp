/* 
 * File:   Object.h
 * Author: Vojta
 *
 * Created on 18. listopadu 2015, 11:28
 */

#ifndef OBJECT_HPP
#define	OBJECT_HPP
#include <string>

class Object {
public:
    Object();
    Object(const Object& orig);
    virtual ~Object();
    virtual bool equalsTo(const Object &object)const;
    virtual std::string print();
     
private:


};

#endif	/* OBJECT_HPP */

