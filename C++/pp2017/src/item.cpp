#include <string>
#include <iostream>
#include <vector>

#include "../include/item.hpp"

Item::~Item(){}

bool operator<(const Item first_item, const Item second_item){
    if(first_item.quantity_ < second_item.quantity_)
        return true;
    return false;
}

void Item::Print(std::ostream& os) const{}
    

std::ostream& operator<<(std::ostream& os, const Item& item){
   item.Print(os);
   return os;
}


//global function
void IterateList(const std::list<Item*>& l) {
    typename std::list<Item*>::const_iterator it;
    for (it = l.begin(); it != l.end(); ++it){
        std::cout << *(*it) <<std::endl;
    }
}