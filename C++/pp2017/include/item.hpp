#include <string>
#include <vector>
#include <iostream>
#include <list>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item {
    
    protected:
         std::string code_;
         int quantity_;

    public:
        //destructor
        virtual ~Item();
        
        //member functions
        virtual std::ostream& Print(std::ostream& os) const;

        //operators overloading
        friend std::ostream& operator<<(std::ostream& os, const Item& item);
        friend bool operator<(const Item first_item, const Item second_item);

};

//global functions
void IterateList(const std::list<Item*>& list);
bool Compare(Item* a, Item* b);
void Delete(std::list<Item*> list);
#endif