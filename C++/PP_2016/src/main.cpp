#include <iostream>
#include <vector>
#include <string>
#include <fstream>


#include "../include/book.hpp"
#include "../include/dvd.hpp"
#include "../include/exception.hpp"

using namespace std;

int main(){
    vector<Item*> library; 
    string file1 = "books.txt";
    
    ifstream inputfile;
    inputfile.open(file1.c_str());
    
    // if inputfile is not valid
    if(!inputfile.is_open()){
        cout << "ERROR, FILE NOT FOUND" << std::endl;
        return 1;
    }
    
    //if inputfile is valid
    else {
        string tmp;

        while(inputfile >> tmp){
            Item* book = new Book(tmp);
            library.push_back(book); 
        }
    }

    string file2 = "dvds.txt";
    
    ifstream inputfile2;
    inputfile2.open(file2.c_str());
    
    // if inputfile is not valid
    if(!inputfile2.is_open()){
        cout << "ERROR, FILE NOT FOUND" << std::endl;
        return 1;
    }
    
    //if inputfile is valid
    else {
        string tmp;

        while(inputfile2 >> tmp){
            Item* dvd = new Dvd(tmp);
            library.push_back(dvd); 
        }
    }

    IterateLibrary(library);

    char answer;
    int item_code;
    string borrow_code;

    cout <<"do you want to borrow an item? (y,n): " <<endl;
    cin >> answer;
    while(answer == 'y'){
        cout << "enter number of the item: " <<endl;
        cin >> item_code;
        cout << "enter borrow code: " <<endl;
        cin >> borrow_code;
        
        try{
            library[item_code]->BorrowItem(borrow_code);
        }
        catch(const not_available& msg){
            cout <<"this item is currently unavailable" << endl;    
        }

        //display new condition
        IterateLibrary(library);

        cout <<"do you want to borrow another item? (y,n): " <<endl;
        cin >> answer;
    }

    ofstream library_status;
    library_status.open ("librarystate.txt");
    typename std::vector<Item*>::const_iterator it;
    for (it = library.begin(); it != library.end(); ++it){
        library_status << *(*it) <<endl;    
    }
    library_status.close();

    typename std::vector<Item*>::const_iterator it2;
    for (it2 = library.begin(); it2 != library.end(); ++it2){
        delete *it2;    
    }
    
    return 0;    
}
