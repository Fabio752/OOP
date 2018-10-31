#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

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

Point::~Point(){
    //cout << "x = " << x_ <<"   y = " << y_ << "   distance from origin = " << distance_ <<endl;
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

// LAB 3
int MemberPointUnorderedSearch(const Point& point, const std::vector<Point>& points_list){
    for(int i = 0; i < points_list.size(); i++){
        if(point == points_list[i]){
            return i;
        }
    }
    return points_list.size();
}

int MemberPointBinarySearch(const Point& point, const std::vector<Point>& points_list){
    int base_index = points_list.size()/2;
    int offset = points_list.size();
    while(offset >= 1){
        offset /= 2;

        if(point == points_list[base_index]){
            return base_index;
        }
        else{
            if(point > points_list[base_index]){
                if(offset == 1)
                    base_index += offset;
                else
                    base_index += offset/2; 
            }
            else{
                if(offset == 1)
                    base_index -= offset;
                else
                    base_index-= offset/2;
            }
        }
    }
    return points_list.size();
}
    

void QuickSort(int low, int high, vector<Point>& points_list){
    if(low < high){
        int pivot = partition_vector(low, high, points_list);

        QuickSort(low, pivot -1, points_list);
        QuickSort(pivot + 1, high, points_list);
    } 
}

int partition_vector(int low, int high, vector<Point>& points_list){
    Point pivot = points_list[high];    
    int index_smaller_element = low - 1; 
  
    for (int i = low; i < high; i++) { 
        if (points_list[i] < pivot) { 
            index_smaller_element++; 
            swap_elements(points_list[index_smaller_element], points_list[i]); 
        } 
    } 
    swap_elements(points_list[index_smaller_element + 1], points_list[high]); 
    return index_smaller_element + 1; 
}

void swap_elements(Point& first_point, Point& second_point){
    Point tmp = first_point;
    first_point = second_point;
    second_point = tmp;
}

int FindPoint(const Point& point, const std::vector<Point>& points_list, bool ordered  /*= false*/){
    if(ordered)
        return MemberPointBinarySearch(point, points_list);
    
    else
        return MemberPointUnorderedSearch(point, points_list);
}

void CommonPoints(const std::vector<Point>& first_points_list, const std::vector<Point>& second_points_list, std::vector<Point>& common_points,bool ordered /*= false*/){
    for(int i = 0; i < first_points_list.size(); i++){
        int index_common_point = FindPoint(first_points_list[i], second_points_list, ordered);
        if(index_common_point < second_points_list.size())
            common_points.push_back(second_points_list[i]);
    }
}

int TestCommonPoints(char **argv){
    std::vector<Point> first_points_list, second_points_list, common_points;
   
    string first_file = argv[1];
    
    ifstream inputfile;
    inputfile.open(first_file.c_str());
    
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
                first_points_list.push_back(tmp_point);
            }
            counter++;
        }
    }

    string second_file = argv[2];
    
    ifstream inputfile2;
    inputfile2.open(second_file.c_str());
    
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


    CommonPoints(first_points_list, second_points_list, common_points);    
    
    string third_vector_file = argv[3];
    ofstream outputfile(argv[3]);

    cout <<"size: " <<common_points.size();
    for(int i = 0; i < common_points.size(); i++){
        outputfile <<to_string(common_points[i].GetX()) + " " + to_string(common_points[i].GetY()) +"\n";
    }

    return 0;
}