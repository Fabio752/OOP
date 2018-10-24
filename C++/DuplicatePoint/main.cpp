#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "point.hpp"

using namespace std;


int main(int argc, char **argv){
    
    //Test ClosestPointIndex function
    vector<Point> points_list;
    string file = "test.txt";
    
    ifstream inputfile;
    inputfile.open(file.c_str());
    
    // if inputfile is not valid
    if(!inputfile.is_open()){
        cout << "ERROR, FILE NOT FOUND" << std::endl;
        return 1;
    }
    
    //if inputfile is valid, store points
    else {
        double tmp;
        Point tmp_point;
        int counter = 0;
        

        while(inputfile >> tmp){
            if(!(counter % 2))
                tmp_point.SetX(tmp);
            else{
                tmp_point.SetY(tmp);
                points_list.push_back(tmp_point);
            }
            counter++;
        }
    }

    vector<Point> second_points_list;
    string file2 = "test2.txt";
    
    ifstream inputfile2;
    inputfile2.open(file2.c_str());
    
    // if inputfile is not valid
    if(!inputfile2.is_open()){
        cout << "ERROR, FILE NOT FOUND" << std::endl;
        return 1;
    }
    
    //if inputfile is valid, store points
    else {
        double tmp;
        Point tmp_point;
        int counter = 0;
        

        while(inputfile2 >> tmp){
            if(!(counter % 2))
                tmp_point.SetX(tmp);
            else{
                tmp_point.SetY(tmp);
                second_points_list.push_back(tmp_point);
            }
            counter++;
        }
    }

    //Test Unordered Search and Binary Search
    Point point(111, 0);

    // int index = MemberPointUnorderedSearch(point, points_list);
    int index = MemberPointBinarySearch(point, points_list);
    cout <<"index is " <<index <<endl;
    

    //Test QuickSort
    QuickSort(0, points_list.size() - 1, points_list);
    cout <<" Sorted Vector: " <<endl;
    for(int i = 0; i < points_list.size(); i++)
        points_list[i].DisplayCoordinates();

    //Test FindPoint
    Point point(9, 3);
    // bool ordered = true;
    int index = FindPoint(point, points_list);
    cout <<"index is " <<index <<endl;  
    
    // Test CommonPoints
    vector<Point> common_points;
    CommonPoints(points_list, second_points_list, common_points);
    cout <<"common points: " <<endl;
    for(int i = 0; i < common_points.size(); i++){
        common_points[i].DisplayCoordinates();
    }
    
    int return_value = TestCommonPoints(argv);
    return return_value;
}


