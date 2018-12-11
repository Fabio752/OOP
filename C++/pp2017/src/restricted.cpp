#include <string>
#include <iostream>

#include "../include/restricted.hpp"

//constructors
Restricted::Restricted(const std::string& code, const int& quantity, const std::string& super_user){ 
    code_ = code;
    quantity_ = quantity;
    super_user_ = super_user;
}

Restricted::Restricted(const Restricted& restricted){
    code_ = restricted.code_;
    quantity_ = restricted.quantity_;
    super_user_ = restricted.super_user_;
}


//destructor
Restricted::~Restricted(){}

//member functions
std::ostream& Restricted::Print(std::ostream& os) const{
    os <<code_ <<" " <<quantity_ <<" " <<super_user_;
    return os;
}

