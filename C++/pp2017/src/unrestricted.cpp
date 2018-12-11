#include <string>

#include "../include/unrestricted.hpp"

Unrestricted::~Unrestricted(){}

Unrestricted::Unrestricted(const std::string& code, const int& quantity){ 
    code_ = code;
    quantity_ = quantity;
}


void Unrestricted::Print(std::ostream& os) const{
    os <<code_ <<" " <<quantity_;
}



