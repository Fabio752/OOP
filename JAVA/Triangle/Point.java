
import java.lang.Math;

public class Point {
	private double x_;
	private double y_;
	private double distance_;

	Point(double x, double y){
		x_ = x;
		y_ = y;
		distance_ = Math.sqrt(x * x + y * y);
	}

	public double GetX() {
		return x_;
	}
	public double GetY() {
		return y_;
	}
	public double GetDistanceFromOrigin() {
		return distance_;
	}
        
        public void SetX(double x_in) {
        	x_ = x_in;
        	SetDistanceFromOrigin();
        }
        public void SetY(double y_in) {
        	y_ = y_in;
        	SetDistanceFromOrigin();
        }
        public void SetDistanceFromOrigin() {
			distance_ = Math.sqrt(x_ * x_ + y_ * y_);
        }
        
        public void DisplayCoordinates() {
        	System.out.println("(" + String.valueOf(x_) + " " + String.valueOf(y_) + ")");
        }
        
        public double GetDistanceFromPoint(Point other_point) {
        	return Math.sqrt((x_ - other_point.x_) *(x_ - other_point.x_) + (y_ - other_point.y_) *(y_ - other_point.y_));
        }
        
        public void GenerateSymmetricPoint() {
        	x_ = -x_;
        	y_ = -y_;
        }
        public void TranslatePoint(Point translator_point) {
        	x_ = x_ + translator_point.x_;
        	y_ = y_ + translator_point.y_;
	}

	//Operators
	public boolean GreaterThan(Point other_point){
		return distance_ > other_point.GetDistanceFromOrigin();
	}

	public boolean SmallerThan(Point other_point){
		return distance_ < other_point.GetDistanceFromOrigin();
	}
	public boolean EqualTo(Point other_point){
		return (x_ == other_point.GetX()) && (y_ == other_point.GetY());
	}
		

        
}
