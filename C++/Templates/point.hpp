#include <vector>
#include <iostream>

class Point{
    private:
        double x_;
        double y_;
        double distance_;
        
    public:
        Point();
        Point(double x, double y);
        
        double GetX() const;
        double GetY() const;
        double GetDistanceFromOrigin() const;
        
        void SetX(double const& x_in);
        void SetY(double const& y_in);
        void SetDistanceFromOrigin();
        
        
        double GetDistanceFromPoint(const Point& other_point) const;
        
        void GenerateSymmetricPoint();
        void TranslatePoint(const Point& other_point);

        //Operators
        friend bool operator<(const Point& first_point, const Point& second_point);
        friend bool operator==(const Point& first_point, const Point& second_point);
        friend bool operator>(const Point& first_point, const Point& second_point);
        friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

//Global Functions Declarations
int ClosestPointIndex(const std::vector<Point>& points_list); 
bool EqualPoints(const Point& first_point, const Point& second_point);