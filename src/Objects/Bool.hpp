#ifndef __BOOL_HPP__
#define __BOOL_HPP__

#include "BasicObject.hpp"
#include <string>

using std::string;

class Bool : public BasicObject {
    public:
        Bool(bool boolean);
        ~Bool();
        bool getValue();
        string print() const;
        bool equalsTo(const BasicObject& basicObject) const;
    private:
        bool m_value;
};

#endif

