#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "point.hpp"

using namespace std;

Point::Point(){
    x_ = 0;
    y_ = 0;
    distance_ = 0;
}

Point::Point(double x, double y){
    x_ = x;
    y_ = y;
    distance_ = sqrt((x_* x_) + (y_ * y_)); 
}

double Point::GetX() const{
    return x_;
}

double Point::GetY() const{
    return y_;
}

double Point::GetDistanceFromOrigin() const{
    return distance_;
}

void Point::SetX(const double& x_in){
   x_ = x_in;
   
   SetDistanceFromOrigin();
}

void Point::SetY(const double& y_in){
   y_ = y_in;
   
   SetDistanceFromOrigin();
}

void Point::SetDistanceFromOrigin(){
    distance_ = sqrt(x_ * x_ + y_ * y_);
}
    
double Point::GetDistanceFromPoint(const Point& other_point) const{
        double distance = sqrt((other_point.x_ - x_) * (other_point.x_ - x_) + (other_point.y_ - y_) * (other_point.y_ - y_));
        return distance;
}


void Point::DisplayCoordinates() const{
    string coordinates = "(" + to_string(x_) + ", " + to_string(y_) + ")";
    cout <<coordinates << endl;
}


void Point::GenerateSymmetricPoint(){
    x_ = -x_;
    y_ = -y_;
}

void Point::TranslatePoint(const Point& other_point){
    x_  = x_ + other_point.x_;
    y_ = y_ + other_point.y_;
}



//Operators
bool operator<(const Point& first_point, const Point& second_point){
    return first_point.GetDistanceFromOrigin() < second_point.GetDistanceFromOrigin();
}

bool operator==(const Point& first_point, const Point& second_point){
    return (first_point.GetX() == second_point.GetX()) && (first_point.GetY() == second_point.GetY());
}

bool operator>(const Point& first_point, const Point& second_point){
    return first_point.GetDistanceFromOrigin() > second_point.GetDistanceFromOrigin();
}


//Global Functions
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



