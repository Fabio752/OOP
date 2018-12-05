#include <string>

#include "../include/dvd.hpp"
#include "../include/exception.hpp"

Dvd::~Dvd(){
    std::cout <<this->title_ <<" is leaving" <<std::endl;
}

Dvd::Dvd(const std::string& title){
    title_ = title;
    status_ = "available";
    date_ = "";
    borrower_ = "";
}


void Dvd::BorrowItem(const std::string& borrower){
    if(status_ == "unavailable"){
       throw not_available("this item is not available");
       return;
    }
    
    status_ = "unavailable";
    date_ = "14/12/2016";
    borrower_ = borrower;
}

void Dvd::Print(std::ostream& os) const{
    os <<"dvd: " <<title_;
    if(status_ == "available")
        os <<", currently available";
    else{
        os << ", borrowed by " <<borrower_ <<", return by: " <<date_;
    }
}

std::ostream& operator<<(std::ostream& os, const Item& item){
   item.Print(os);
   return os;
}
