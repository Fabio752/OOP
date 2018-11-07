#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

#include "labeled_point.hpp"

using namespace std;

LabeledPoint::LabeledPoint(){
    x_ = 0;
    y_ = 0;
    label_ = "A";
    distance_ = 0;
}

LabeledPoint::LabeledPoint(double x, double y, string label){
    x_ = x;
    y_ = y;
    label_ = label;
    distance_ = sqrt((x_* x_) + (y_ * y_)); 
}

LabeledPoint::~LabeledPoint(){
    //cout << "x = " << x_ <<"   y = " << y_ << "   distance from origin = " << distance_ <<endl;
}

double LabeledPoint::GetX() const{
    return x_;
}

double LabeledPoint::GetY() const{
    return y_;
}

string LabeledPoint::GetLabel() const{
    return label_;
}

double LabeledPoint::GetDistanceFromOrigin() const{
    return distance_;
}

void LabeledPoint::SetX(const double& x_in){
   x_ = x_in;
   
   SetDistanceFromOrigin();
}

void LabeledPoint::SetY(const double& y_in){
   y_ = y_in;
   
   SetDistanceFromOrigin();
}

void LabeledPoint::SetLabel(const string& label){
   label_ = label;
}

void LabeledPoint::SetDistanceFromOrigin(){
    distance_ = sqrt(x_ * x_ + y_ * y_);
}
    
double LabeledPoint::GetDistanceFromLabeledPoint(const LabeledPoint& other_point) const{
        double distance = sqrt((other_point.x_ - x_) * (other_point.x_ - x_) + (other_point.y_ - y_) * (other_point.y_ - y_));
        return distance;
}

//Operators
bool operator<(const LabeledPoint& first_point, const LabeledPoint& second_point){
    return (first_point.GetDistanceFromOrigin() < second_point.GetDistanceFromOrigin());
}
bool operator<(const Point& second_point, const LabeledPoint& first_point){
    return (first_point.GetDistanceFromOrigin() < second_point.GetDistanceFromOrigin());
}
bool operator<(const LabeledPoint& first_point, const Point& second_point){
    return (first_point.GetDistanceFromOrigin() < second_point.GetDistanceFromOrigin());
}

bool operator>(const LabeledPoint& first_point, const LabeledPoint& second_point){
    return (first_point.GetDistanceFromOrigin() > second_point.GetDistanceFromOrigin());
}
bool operator>(const Point& second_point, const LabeledPoint& first_point){
    return (first_point.GetDistanceFromOrigin() > second_point.GetDistanceFromOrigin());
}
bool operator>(const LabeledPoint& first_point, const Point& second_point){
    return (first_point.GetDistanceFromOrigin() > second_point.GetDistanceFromOrigin());
}

bool operator==(const LabeledPoint& first_point, const LabeledPoint& second_point){
    return ((first_point.GetX() == second_point.GetX()) && first_point.GetY() == second_point.GetY());
}
bool operator==(const Point& second_point, const LabeledPoint& first_point){
    return ((first_point.GetX() == second_point.GetX()) && first_point.GetY() == second_point.GetY());
}
bool operator==(const LabeledPoint& first_point, const Point& second_point){
    return ((first_point.GetX() == second_point.GetX()) && first_point.GetY() == second_point.GetY());
}
