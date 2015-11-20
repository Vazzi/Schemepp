/* 
 * File:   BasicObject.h
 * Author: Vojta
 *
 * Created on 20. listopadu 2015, 10:01
 */

#ifndef BASICOBJECT_HPP
#define	BASICOBJECT_HPP

#include <string>

class BasicObject {
public:
    BasicObject();
    BasicObject(const BasicObject& orig);
    virtual ~BasicObject();
    virtual bool equalsTo(const BasicObject& basicObject)const;
    virtual std::string print();
     
private:


};

#endif	/* BASICOBJECT_HPP */

