#include <string>
#include <iostream>
#include <vector>

#include "../include/item.hpp"

Item::~Item(){
    std::cout <<"Item is leaving" <<std::endl;
}

void Item::Print(std::ostream& os) const{
    //error!
}

//global function
void IterateLibrary(const std::vector<Item*>& library) {
    typename std::vector<Item*>::const_iterator it;
    for (it = library.begin(); it != library.end(); ++it){
        std::cout << *(*it) <<std::endl;
    }
}