#include "point.hpp"

class Triangle {
    
    //private:
    //QUESTION: HOW TO MAKE THEM PRIVATE AND POINT FRIEND CLASS
    private:
        Point first_corner_;
        Point second_corner_;
        Point third_corner_;
        
    public:
        Triangle(Point first_corner, Point second_corner, Point third_corner);
        
        Point GetFirstCorner();
        Point GetSecondCorner();
        Point GetThirdCorner();

        double GetPerimeter();
        void TranslateTriangle(Point translator_point); 
        double GetArea();
        
        
        //Operators
        friend bool operator<(Triangle first_triangle, Triangle second_triangle);
        friend bool operator==(Triangle first_triangle, Triangle second_triangle);
        friend bool operator>(Triangle first_triangle, Triangle second_triangle);
};

//Global Functions Declarations
int BiggestTriangle(const vector<Triangle>& triangles_list);
