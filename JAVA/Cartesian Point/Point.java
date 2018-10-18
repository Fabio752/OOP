
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
		
		public double get_x() {
			return x_;
		}
		public double get_y() {
			return y_;
		}
		public double get_distance_from_origin() {
			return distance_;
		}
        
        public void set_x(double x_in) {
        	x_ = x_in;
        	set_distance_from_origin();
        }
        public void set_y(double y_in) {
        	y_ = y_in;
        }
        public void set_distance_from_origin() {
			distance_ = Math.sqrt(x_ * x_ + y_ * y_);
        }
        
        public void display_coord() {
        	System.out.println("(" + String.valueOf(x_) + " " + String.valueOf(y_) + ")");
        }
        
        public double distance(Point p_in) {
        	return Math.sqrt((x_ - p_in.x_) *(x_ - p_in.x_) + (y_ - p_in.y_) *(y_ - p_in.y_));
        }
        
        public void symm_point() {
        	x_ = -x_;
        	y_ = -y_;
        }
        public void trans_point(Point p_in) {
        	x_ = x_ + p_in.x_;
        	y_ = y_ + p_in.y_;
        }
        
}
