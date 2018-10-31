#include <vector>

class Point {
    private:
        double x_;
        double y_;
        double distance_;
        
    public:
        Point();
        Point(double x, double y);
        ~Point();
        
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
int ClosestPointIndex(const std::vector<Point>& points_list); 
bool EqualPoints(const Point& first_point, const Point& second_point);
int MemberPointUnorderedSearch(const Point& point, const std::vector<Point>& points_list);
int MemberPointBinarySearch(const Point& point, const std::vector<Point>& points_list);
void QuickSort(int low, int high, std::vector<Point>& points_list);
int partition_vector(int low, int high, std::vector<Point>& points_list);
int FindPoint(const Point& point, const std::vector<Point>& points_list, bool ordered = false);
void swap_elements(Point& first_point, Point& second_point);
void CommonPoints(const std::vector<Point>& first_points_list, const std::vector<Point>& second_points_list, std::vector<Point>& common_points, bool ordered = false);
int TestCommonPoints(char **argv);