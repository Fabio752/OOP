
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
        
        void SetX(const double& x_in);
        void SetY(const double& y_in);
        void SetDistanceFromOrigin();
        
        void DisplayCoordinates() const;
        
        double GetDistanceFromPoint(const Point& other_point) const;
        
        void GenerateSymmetricPoint();
        void TranslatePoint(const Point& other_point);
        
};
