#include <string>

#include "../include/unrestricted.hpp"

//constructors
Unrestricted::Unrestricted(const std::string& code, const int& quantity){ 
    code_ = code;
    quantity_ = quantity;
}

//destructor
Unrestricted::~Unrestricted(){}

//member functions
std::ostream& Unrestricted::Print(std::ostream& os) const{
    os <<code_ <<" " <<quantity_;
    return os;
}



