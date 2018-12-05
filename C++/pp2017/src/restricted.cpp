#include <string>
#include <iostream>

#include "../include/restricted.hpp"
#include "../include/exception.hpp"

Restricted::~Restricted(){
    std::cout <<this->code_ <<" is leaving" <<std::endl;
}

Restricted::Restricted(const std::string& code, const int& quantity, const std::string& super_user){ 
    code_ = code;
    quantity_ = quantity;
    super_user_ = super_user;
}

void Restricted::Print(std::ostream& os) const{
    os <<code_ <<" " <<quantity_ <<" " <<super_user_;
}

