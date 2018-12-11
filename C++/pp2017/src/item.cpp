#include <string>
#include <iostream>
#include <list>

#include "../include/item.hpp"

//destructor
Item::~Item(){}

//operators overloading
bool operator<(const Item first_item, const Item second_item){
    if(first_item.quantity_ < second_item.quantity_)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const Item& item){
   return item.Print(os);
}

//member functions
std::ostream& Item::Print(std::ostream& os) const{}  

//global functions
void IterateList(const std::list<Item*>& l) { //for printing
    typename std::list<Item*>::const_iterator it;
    for (it = l.begin(); it != l.end(); ++it){
        std::cout << *(*it) <<std::endl;
    }
}

bool Compare(Item* a, Item* b){ //for sorting
    return (*a < *b);
}

void Delete(std::list<Item*> list){
    typename std::list<Item*>::const_iterator it;
    for (it = list.begin(); it != list.end(); ++it){
        delete *it;    
    }
}
