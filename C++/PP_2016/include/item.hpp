#include <string>
#include <vector>
#include <iostream>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item {
    public:
        std::string title_;
        std::string status_;
        std::string date_;
        std::string borrower_;

    public:
        virtual ~Item();
        virtual void BorrowItem(const std::string& borrower) = 0;
        virtual void Print(std::ostream& os) const;
        friend std::ostream& operator<<(std::ostream& os, const Item& item);
};


//global functions
void IterateLibrary(const std::vector<Item*>& library);

#endif