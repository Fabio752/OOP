
#include <vector>
#include <string>
#include "point.hpp"

class LabeledPoint {
    private:
        double x_;
        double y_;
        double distance_;
        std::string label_;
        
    public:
        LabeledPoint();
        LabeledPoint(double x, double y, std::string label);
        ~LabeledPoint();
        
        double GetX() const;
        double GetY() const;
        double GetDistanceFromOrigin() const;
        std::string GetLabel() const;
        
        void SetX(double const& x_in);
        void SetY(double const& y_in);
        void SetDistanceFromOrigin();
        void SetLabel(const std::string& label);
        
        
        double GetDistanceFromLabeledPoint(const LabeledPoint& other_point) const;
       
        //Operators
        friend bool operator<(const LabeledPoint& first_point, const LabeledPoint& second_point);
        friend bool operator==(const LabeledPoint& first_point, const LabeledPoint& second_point);
        friend bool operator>(const LabeledPoint& first_point, const LabeledPoint& second_point);
        friend bool operator<(const Point& second_point, const LabeledPoint& first_point);
        friend bool operator==(const Point& second_point, const LabeledPoint& first_point);
        friend bool operator>(const Point& second_point, const LabeledPoint& first_point) ;
        friend bool operator<(const LabeledPoint& first_point, const Point& second_point);
        friend bool operator==(const LabeledPoint& first_point, const Point& second_point);
        friend bool operator>(const LabeledPoint& first_point, const Point& second_point);
};
