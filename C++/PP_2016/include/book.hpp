#include <string>
#include <iostream>

#include "item.hpp"

#ifndef BOOK_HPP
#define BOOK_HPP

class Book: public Item {
    public:
        ~Book();
        Book(const std::string& title);
        void BorrowItem(const std::string& borrower);
        void Print(std::ostream& os) const;
};

#endif