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



//Global function 
int ReturnFarthestPointIndex(vector<Point> const& points_list) {
    int return_index = 0;
    
    for(int i = 1; i < points_list.size(); i++)
        
        if(points_list[i].GetDistanceFromOrigin() > points_list[return_index].GetDistanceFromOrigin())
            return_index = i;
    
    return return_index;
    
}

