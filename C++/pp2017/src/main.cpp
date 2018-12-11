#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>

#include "../include/restricted.hpp"
#include "../include/unrestricted.hpp"
#include "../include/item.hpp"

using namespace std;

int main(){
    list<Item*> unrestricted_item;
    list<Item*> restricted_item; 
    
    string file1 = "unrestricted.txt";
    
    ifstream inputfile;
    inputfile.open(file1.c_str());
    
    // if inputfile is not valid
    if(!inputfile.is_open()){
        cout << "ERROR, FILE NOT FOUND" << std::endl;
        return 1;
    }
    
    //if inputfile is valid
    else {
        string code;
        int quantity;
        
        while(inputfile >> code >> quantity){
            Item* un_item = new Unrestricted(code, quantity);
            unrestricted_item.push_back(un_item); 
        }
    }

    string file2 = "restricted.txt";
    
    ifstream inputfile2;
    inputfile2.open(file2.c_str());
    
    // if inputfile2 is not valid
    if(!inputfile2.is_open()){
        cout << "ERROR, FILE NOT FOUND" << std::endl;
        return 1;
    }
    
    //if inputfile2 is valid
    else {
        string code, super_user;
        int quantity;
        while(inputfile2 >> code >> quantity >> super_user){
            Item* re_item = new Restricted(code, quantity, super_user);
            restricted_item.push_back(re_item); 
        }
    }
     
    //display items unsorted
    cout <<"Unrestricted Items: \n";
    IterateList(unrestricted_item);

    cout <<"Restricted Items: \n";
    IterateList(restricted_item);
    
    //sorting items
    unrestricted_item.sort(Compare);
    restricted_item.sort(Compare);

    cout <<"\n \n AFTER SORTING: " <<endl;
    
    //display items sorted
    cout <<"Unrestricted Items: \n";
    IterateList(unrestricted_item);

    cout <<"Restricted Items: \n";
    IterateList(restricted_item);
    
    //display smallest item in quantity
    if(*(*unrestricted_item.begin()) < *(*restricted_item.begin()))
        cout << "smallest item in quantity: " <<*(*unrestricted_item.begin()) << endl;    
    else    
        cout << "smallest item in quantity: " <<*(*restricted_item.begin()) << endl;    
    
    
    //deleting
    Delete(unrestricted_item);
    Delete(restricted_item);
    

    return 0;    
}
