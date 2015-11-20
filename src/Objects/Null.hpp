/* 
 * File:   Null.h
 * Author: Vojta
 *
 * Created on 20. listopadu 2015, 10:07
 */

#ifndef NULL_HPP
#define	NULL_HPP
#include "BasicObject.hpp"
#include <string>

using std::string;

class Null : public BasicObject{
    public:
        Null();
        ~Null();
        string print();
        bool equalsTo(const BasicObject& basicObject) const;
    private:

};
#endif	/* NULL_HPP */

