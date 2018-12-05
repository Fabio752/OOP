#include <string>
#include <iostream>

#include "item.hpp"

#ifndef DVD_HPP
#define DVD_HPP

class Dvd: public Item {
    public:
        ~Dvd();
        Dvd(const std::string& title);
        void BorrowItem(const std::string& borrower);
        void Print(std::ostream& os) const;
};

#endif