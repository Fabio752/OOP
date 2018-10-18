
import java.util.*;
//import java.lang.Math;

public class Main {

	public static void main(String[] args) {
	
	    Point first_point = new Point(5, 2.2);
	    Point other_point = new Point (3, 7);
	    
	    ArrayList<Double> line_eqns = new ArrayList<Double>();
	    Scanner in = new Scanner (System.in);
	    System.out.println("Enter x value of the first point " );
	    first_point.set_x(in.nextDouble());
	    
	    System.out.println("Enter y value of the first point ");
	    first_point.set_y(in.nextDouble());

	    
	    
	    first_point.display_coord();
	    System.out.println("distance from origin = " + String.valueOf(first_point.get_distance_from_origin()));
	    
	    first_point.symm_point();
	    System.out.println("the symmetric point coordinates are: ");
	    first_point.display_coord();
	    
	    first_point.symm_point(); //back how it was
	    
	    
	    boolean inserting = true;
	    
	    while (inserting == true){
	        
	        System.out.println("insert a value 'b' to form equation y = b : " );
	        
	        line_eqns.add(in.nextDouble());
	        
	        System.out.println("do you want to enter one more? (Y,N): ");
	        String answer = in.next();
	        
	        if (answer.equals("N")) {
	            inserting = false;
	        }
	    }
	    
	    
	    other_point.set_x(first_point.get_x());
	    
	    for(int i = 0; i < line_eqns.size(); i++){
	        other_point.set_y(line_eqns.get(i));
	        System.out.println ("line eqns:  y = " + String.valueOf(line_eqns.get(i)));
	        System.out.println ("distance from fist point = " + String.valueOf(first_point.distance(other_point)));
	    }
	    
	    
	    System.out.println("Set value x of second point: ");
	    other_point.set_x(in.nextDouble());
	    
	    System.out.println("Set value y of second point: ");
	    other_point.set_y(in.nextDouble());
	        
	    System.out.println("the chosen point has coordinates: ");
	    other_point.display_coord();
	    
	    System.out.println("the first point has coordinates: ");
	    first_point.display_coord();
	    System.out.println(" translated accordingly to the second point, has coordinates: ");
	    
	    first_point.trans_point(other_point);
	    first_point.display_coord();
	   	}
}
