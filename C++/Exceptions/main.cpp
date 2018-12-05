#include <iostream>
#include <vector>

#include "exception.hpp"

using namespace std;

double my_division(const double& dividend, const double& divider);

int main(){
    //catch .at exception
    vector<int> list = {2, 3, 4, 5, 8};
  
    try{
        cout << list.at(10) << endl;
    }
    catch(const out_of_range& msg){
        cout <<msg.what() << endl;    
    }


    double dividend = 13.7;
    double divider = 0;

    try{
        my_division(dividend, divider);
    }
    catch(const divide_zero& msg){
        cout <<msg.what();
    }

    cout <<my_division(dividend, divider) << endl;

    return 0;
}


double my_division(const double& dividend, const double& divider){
    if(divider == 0){
        throw divide_zero("divider is 0");
        return 0;
    }
    else{
        return dividend/divider;
    }
}
