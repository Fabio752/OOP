import java.lang.Math;

public class Triangle {
	
	private Point first_corner_;
	private Point second_corner_;
	private Point third_corner_;
	private Double area_;
	
	Triangle(Point first_corner, Point second_corner, Point third_corner){
		first_corner_ = first_corner;
		second_corner_ = second_corner;
		third_corner_ = third_corner;
		SetArea();
	}
	
	public Point GetFirstCorner(){
		return first_corner_;
	}
	
	public Point GetSecondCorner(){
		return second_corner_;
	}
	
	public Point GetThirdCorner(){
		return third_corner_;
	}
	
	public double GetPerimeter() {
		return first_corner_.GetDistanceFromPoint(second_corner_) +
			   second_corner_.GetDistanceFromPoint(third_corner_) +
			   third_corner_.GetDistanceFromPoint(first_corner_);
	}
	
	public void TranslateTriangle(Point translator_point) {
		first_corner_.TranslatePoint(translator_point);
		second_corner_.TranslatePoint(translator_point);
		third_corner_.TranslatePoint(translator_point);
		
	}
	
	public double GetArea() {
		return area_;
	}	
	
	public void SetArea(){
		double semiperimeter = GetPerimeter()/2;
		double first_side = first_corner_.GetDistanceFromPoint(second_corner_);
		double second_side = second_corner_.GetDistanceFromPoint(third_corner_);
		double third_side = third_corner_.GetDistanceFromPoint(first_corner_);
		area_ = Math.sqrt(semiperimeter * (semiperimeter - first_side) * 
		        (semiperimeter - second_side) * (semiperimeter - third_side));
		
	}

	public boolean GreaterThan(Triangle other_triangle){
		return area_ > other_triangle.GetArea();
	}

	public boolean SmallerThan(Triangle other_triangle){
		return area_ < other_triangle.GetArea();
	}
	public boolean EqualTo(Triangle other_triangle){
		return area_ == other_triangle.GetArea();
	}
	
}
