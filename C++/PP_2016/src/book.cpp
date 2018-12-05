#include <string>

#include "../include/book.hpp"
#include "../include/exception.hpp"

Book::~Book(){
    std::cout <<this->title_ <<" is leaving" <<std::endl;
}

Book::Book(const std::string& title){
    title_ = title;
    status_ = "available";
    date_ = "";
    borrower_ = "";
}

void Book::BorrowItem(const std::string& borrower){
    if(status_ == "unavailable"){
        throw not_available("this item is not available");
        return;
    }
    
    status_= "unavailable";
    date_ = "21/12/2016";
    borrower_ = borrower;
}

void Book::Print(std::ostream& os) const{
    os <<"book: " <<title_;
    if(status_ == "available")
        os <<", currently available";
    else{
        os << ", borrowed by " <<borrower_ <<", return by: " <<date_;
    }
}
