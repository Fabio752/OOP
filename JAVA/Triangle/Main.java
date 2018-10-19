import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		//Test Constructor
	    Point first_corner = new Point(5, 2.2);
	    Point second_corner = new Point(8, 7);
	    Point third_corner = new Point(12, -1);
	    
	    Triangle triangle = new Triangle(first_corner, second_corner, third_corner);
	    System.out.println("Triangle corners are: ");
	    triangle.GetFirstCorner().DisplayCoordinates();
	    triangle.GetSecondCorner().DisplayCoordinates();
	    triangle.GetThirdCorner().DisplayCoordinates();
	    //End Test Constructor
	    
	    //Test GetPerimeter function
	    System.out.println("Triangle perimeter = " + String.valueOf(triangle.GetPerimeter()));
	    //End Test GetPerimeter function
	    
	    //Test TranslateTriangle function
	    Random rand = new Random();
	    Point translator_point = new Point(rand.nextInt(20), rand.nextInt(20));
	    triangle.TranslateTriangle(translator_point);
	    
	    System.out.println("Translate triangle according to point: ");
	    translator_point.DisplayCoordinates();
	    
	    System.out.println("New triangle corners are: ");
	    triangle.GetFirstCorner().DisplayCoordinates();
	    triangle.GetSecondCorner().DisplayCoordinates();
	    triangle.GetThirdCorner().DisplayCoordinates();
	    
	    System.out.println("Perimeter always = " + String.valueOf(triangle.GetPerimeter()) + "\n");
	    //End Test TranslateTriangle function
		
		
	}
}
