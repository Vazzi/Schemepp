/* 
 * File:   Number.h
 * Author: Vojta
 *
 * Created on 20. listopadu 2015, 10:09
 */

#ifndef NUMBER_HPP
#define	NUMBER_HPP
#include "BasicObject.hpp"
#include <string>

using std::string;

class Number : public BasicObject{
    public:
        Number(int value);
        ~Number();
        int getValue();
        string print();
        bool equalsTo(const BasicObject& basicObject) const;
   private:
        int m_value;

};
#endif	/* NUMBER_HPP */

