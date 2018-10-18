#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "triangle.hpp"


using namespace std;

int ClosestPointIndex(const vector<Point>& points_list); 
bool EqualPoints(const Point& first_point, const Point& second_point);
int BiggestTriangle(const vector<Triangle>& triangles_list);

int main(){
     //initialise time
    srand(time(NULL));
    
    //Test Constructor;
    Point first_corner(5,3);
    Point second_corner(2,3);
    Point third_corner(2, -6);
    Triangle triangle(first_corner, second_corner, third_corner);
    cout <<"Triangle corners are: ";
    
    triangle.GetFirstCorner().DisplayCoordinates();
    triangle.GetSecondCorner().DisplayCoordinates();
    triangle.GetThirdCorner().DisplayCoordinates();
    //End Test Constructor
    
    //Test GetPerimeter function
    cout <<"Triangle perimeter = " <<triangle.GetPerimeter();
    //End Test GetPerimeter function
    
    //Test TranslateTriangle function
    Point translator_point(rand() % 10, rand() % 10);
    cout <<endl;
    triangle.TranslateTriangle(translator_point);

    cout <<"Translate triangle by: ";
    translator_point.DisplayCoordinates();
    
    cout <<"New triangle corners are: ";
    triangle.GetFirstCorner().DisplayCoordinates();
    triangle.GetSecondCorner().DisplayCoordinates();
    triangle.GetThirdCorner().DisplayCoordinates();
    cout <<"Perimeter always = " <<triangle.GetPerimeter() <<endl;;
    //End Test TranslateTriangle function
    
    
    //Test ClosestPointIndex function
    vector<Point> points_list;
    string file;
    
    cout << "Enter the name of file containing the points' coordinates " <<endl;
    cin >> file;
    
    ifstream inputfile;
    inputfile.open(file.c_str());
    
    // if inputfile is not valid
    if(!inputfile.is_open()){
        cout << "ERROR, FILE NOT FOUND" << std::endl;
        return 1;
    }
    
    //if inputfile is valid
    else {
        double tmp;
        Point tmp_point;
        int counter = 0;
        

        while(inputfile >> tmp){
            if(!(counter % 2))
                tmp_point.SetX(tmp);
            else{
                tmp_point.SetY(tmp);
                cout <<"point number: " <<counter/2 <<" with coordinates: ";
                tmp_point.DisplayCoordinates();
                points_list.push_back(tmp_point);
                cout <<endl;
            }
            counter++;
        }
    }
    
    int index_closest_point = ClosestPointIndex(points_list);
    cout << "Closest point to the origin is the number: " <<index_closest_point <<" and has coordinates: ";
    
    points_list[index_closest_point].DisplayCoordinates();
    cout <<endl;
    //End Test ClosestPointIndexFunction
    
    //TestEqualPointsFunction
    cout <<"the first and the second number of the testfile are :";
    if(EqualPoints(points_list[0], points_list[1]))
        cout <<" equal" <<endl;
    else
        cout <<" not equal" <<endl;
    
    
    // Test Triangles Operators
    vector<Triangle> triangles_list;
    
    for(int i = 0; i < points_list.size(); i+=3){
        Triangle tmp_triangle(points_list[i], points_list[i + 1], points_list[i + 2]);
        triangles_list.push_back(tmp_triangle);
    }
    
   
    int index_biggest_triangle = BiggestTriangle(triangles_list);
    cout << "Biggest triangle is the number: " <<index_biggest_triangle <<" and has area: " <<triangles_list[index_biggest_triangle].GetArea() <<endl;
    cout <<endl;
    
    //End Test Triangles Operators
    

    
    return 0;
}


int ClosestPointIndex(const vector<Point>& points_list){
    int index_closest_point = 0;
    
    for(int i = 1; i < points_list.size(); i++)
        if(points_list[i] < points_list[index_closest_point])
            index_closest_point = i;
    
    return index_closest_point;
}

bool EqualPoints(const Point& first_point, const Point& second_point){
        if(first_point == second_point)
             return true;
        
    return false;
}

int BiggestTriangle(const vector<Triangle>& triangles_list){
     int index_biggest_triangle = 0;
    
    for(int i = 1; i < triangles_list.size(); i++)
        if(triangles_list[i] > triangles_list[index_biggest_triangle])
            index_biggest_triangle = i;
    
    return index_biggest_triangle;
}
