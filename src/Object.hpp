/* 
 * File:   Object.h
 * Author: Vojta
 *
 * Created on 18. listopadu 2015, 11:28
 */

#ifndef OBJECT_H
#define	OBJECT_H

class Object {
public:
    Object();
    Object(const Object& orig);
    virtual ~Object();
    virtual bool equalsTo(const Object &object)const;
    
private:

};

#endif	/* OBJECT_H */

