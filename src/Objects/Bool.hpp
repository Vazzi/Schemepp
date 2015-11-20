/* 
 * File:   Bool.h
 * Author: Vojta
 *
 * Created on 20. listopadu 2015, 10:05
 */

#ifndef BOOL_HPP
#define	BOOL_HPP
#include "BasicObject.hpp"
#include <string>

using std::string;

class Bool : public BasicObject{
    public:
        Bool(bool boolean);       
        ~Bool();
        bool getValue();
        string print();
        bool equalsTo(const BasicObject& basicObject) const;
    private:
        bool m_value;
};

#endif	/* BOOL_HPP */

