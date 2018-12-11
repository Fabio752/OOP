#include <string>
#include <iostream>

#include "item.hpp"

#ifndef UNRESTRICTED_HPP
#define UNRESTRICTED_HPP

class Unrestricted: public Item {
    public:
        //constructors
        Unrestricted(const std::string& code, const int& quantity); 
        
        //destructor
        ~Unrestricted();

        //member functions
        std::ostream& Print(std::ostream& os) const;
};

#endif