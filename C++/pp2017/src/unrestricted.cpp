#include <string>

#include "../include/unrestricted.hpp"
#include "../include/exception.hpp"

Unrestricted::~Unrestricted(){
    std::cout <<this->code_ <<" is leaving" <<std::endl;
}

Unrestricted::Unrestricted(const std::string& code, const int& quantity){ 
    code_ = code;
    quantity_ = quantity;
}

void Unrestricted::Print(std::ostream& os) const{
    os <<code_ <<" " <<quantity_;
}



