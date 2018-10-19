#include <cmath>
#include <vector>

#include "triangle.hpp"

using namespace std;


Triangle::Triangle(Point first_corner, Point second_corner, Point third_corner){
     first_corner_ = first_corner;
     second_corner_ = second_corner;
     third_corner_ = third_corner;
 }
 
Point Triangle::GetFirstCorner(){
    return first_corner_;
}

Point Triangle::GetSecondCorner(){
    return second_corner_;
}

Point Triangle::GetThirdCorner(){
    return third_corner_;
}
 
double Triangle::GetPerimeter(){
    return first_corner_.GetDistanceFromPoint(second_corner_) + second_corner_.GetDistanceFromPoint(third_corner_) + third_corner_.GetDistanceFromPoint(first_corner_);
}
void Triangle::TranslateTriangle(Point translator_point){
    first_corner_.TranslatePoint(translator_point);
    second_corner_.TranslatePoint(translator_point);
    third_corner_.TranslatePoint(translator_point);
}

double Triangle::GetArea(){
    double semiperimeter = GetPerimeter()/2;
    double first_side = first_corner_.GetDistanceFromPoint(second_corner_);
    double second_side = second_corner_.GetDistanceFromPoint(third_corner_);
    double third_side = third_corner_.GetDistanceFromPoint(first_corner_);
    double area = sqrt(semiperimeter * (semiperimeter - first_side) *
                  (semiperimeter - second_side) * (semiperimeter - third_side));
    return area;
}


 //Operators
bool operator<(Triangle first_triangle, Triangle second_triangle){
    return first_triangle.GetArea() < second_triangle.GetArea();
}

bool operator==(Triangle first_triangle, Triangle second_triangle){
    return first_triangle.GetArea() == second_triangle.GetArea();
}

bool operator>(Triangle first_triangle, Triangle second_triangle){
    return first_triangle.GetArea() > second_triangle.GetArea();
}


//Global functions

int BiggestTriangle(const vector<Triangle>& triangles_list){
     int index_biggest_triangle = 0;
    
    for(int i = 1; i < triangles_list.size(); i++)
        if(triangles_list[i] > triangles_list[index_biggest_triangle])
            index_biggest_triangle = i;
    
    return index_biggest_triangle;
}