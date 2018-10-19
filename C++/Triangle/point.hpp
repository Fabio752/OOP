#include <vector>
using namespace std;


class Point {
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
        
        void DisplayCoordinates() const;
        
        double GetDistanceFromPoint(const Point& other_point) const;
        
        void GenerateSymmetricPoint();
        void TranslatePoint(const Point& other_point);
        
        //Operators
        friend bool operator<(const Point& first_point, const Point& second_point);
        friend bool operator==(const Point& first_point, const Point& second_point);
        friend bool operator>(const Point& first_point, const Point& second_point);
};

//Global Functions Declarations
int ClosestPointIndex(const vector<Point>& points_list); 
bool EqualPoints(const Point& first_point, const Point& second_point);