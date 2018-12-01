#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

#include "point.hpp"
#include "template.hpp"

using namespace std;

int main (){
    srand(time(NULL));

    cout <<"#########TEST 1st PART################\n";
    int a = 10;
    int b = 5;
    cout << "a = " <<a <<"\n" <<"b= " <<b <<endl;
    my_swap(a, b);
    cout <<"after swap: \n" << "a = " <<a <<"\n" <<"b= " <<b <<endl;
    
    string c = "s1";
    string d = "s2";
    cout << "c = " <<c <<"\n" <<"d= " <<d <<endl;
    my_swap(c, d);
    cout <<"after swap: \n" << "c = " <<c <<"\n" <<"d= " <<d <<endl;
    
    double e = 10.3;
    double f = 5.5;
    cout << "e = " <<e <<"\n" <<"f= " <<f <<endl;
    my_swap(e, f);
    cout <<"after swap: \n" << "e = " <<e <<"\n" <<"f= " <<f <<endl;

    
    cout <<"#########TEST 2nd PART################\n";
    cout <<"vector of integers\n";
    vector<int> numbers;
    for(int i = 0; i < 10; i++){
        int rand_num = rand() % 15;
        numbers.push_back(rand_num);
        cout <<"element " <<i <<": " <<rand_num <<endl;
    }
    cout <<endl;

    int index = index_smallest_element(numbers);
    cout <<"smallest element index : " <<index <<endl;
    cout <<"smallest element: " <<numbers[index] <<endl;
    cout <<"#########################\n";
    cout <<"using built-in function: " <<endl;

    std::vector<int>::iterator result = min_element(numbers.begin(), numbers.end());
    std::cout <<"smaller number index: "<< distance(numbers.begin(), result) << endl;
    std::cout <<"smaller number: "<< numbers[distance(numbers.begin(), result)];
 

    std::cout <<"\n vector of points\n";
    vector<Point> v_points;
    for(int i = 0; i < 10; i++){
        double rand1_num = rand() % 15;
        double rand2_num = rand() % 15;
        Point tmp(rand1_num,rand2_num);
        v_points.push_back(tmp);
        cout <<tmp <<endl;
    }
    cout <<endl;

    index = index_smallest_element(v_points);
    cout <<"smallest element index: " << index <<endl;
    cout <<"smallest element: " << v_points[index] <<endl;
    

    cout <<"#########TEST 3rd PART################\n";
    cout <<"vector of integers\n";
    iter_vec(numbers);
   
    my_sort(numbers);
    cout <<"after sorting: \n";
    iter_vec(numbers);
    cout <<endl;


    std::cout <<"\n vector of points\n";
    iter_vec(v_points);
   
    my_sort(v_points);
 
    cout <<"after sorting: \n";
    iter_vec(v_points);

    return 0;
}