#include <string>
#include <iostream>

#include "item.hpp"

#ifndef UNRESTRICTED_HPP
#define UNRESTRICTED_HPP

class Unrestricted: public Item {
    public:
        ~Unrestricted();
        Unrestricted(const std::string& code, const int& quantity); 

        void Print(std::ostream& os) const;
};

#endif