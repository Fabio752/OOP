
import java.util.*;

public class Main {

	public static void main(String[] args) {
	
		Point first_point = new Point(5, 2.2);
		Point other_point = new Point (3, 7);

		ArrayList<Double> line_eqns = new ArrayList<Double>();
		Scanner in = new Scanner (System.in);
		System.out.println("Enter x value of the first point " );
		first_point.SetX(in.nextDouble());

		System.out.println("Enter y value of the first point ");
		first_point.SetY(in.nextDouble());



		first_point.DisplayCoordinates();
		System.out.println("distance from origin = " + String.valueOf(first_point.GetDistanceFromOrigin()));

		first_point.GenerateSymmetricPoint();
		System.out.println("the symmetric point coordinates are: ");
		first_point.DisplayCoordinates();

		first_point.GenerateSymmetricPoint(); //back how it was


		boolean inserting = true;

		while (inserting == true){

		System.out.println("insert a value 'b' to form equation y = b : " );

		line_eqns.add(in.nextDouble());

		System.out.println("do you want to enter one more? (Y,N): ");
		String answer = in.next();

		if (!answer.equals("Y")) {
		    inserting = false;
		}
		}


		other_point.SetX(first_point.GetX());

		for(int i = 0; i < line_eqns.size(); i++){
		other_point.SetY(line_eqns.get(i));
		System.out.println ("line eqns:  y = " + String.valueOf(line_eqns.get(i)));
		System.out.println ("distance from fist point = " + String.valueOf(first_point.GetDistanceFromPoint(other_point)));
		}


		System.out.println("Set value x of second point: ");
		other_point.SetX(in.nextDouble());

		System.out.println("Set value y of second point: ");
		other_point.SetY(in.nextDouble());

		System.out.println("the chosen point has coordinates: ");
		other_point.DisplayCoordinates();

		System.out.println("the first point has coordinates: ");
		first_point.DisplayCoordinates();
		System.out.println(" translated accordingly to the second point, has coordinates: ");

		first_point.TranslatePoint(other_point);
		first_point.DisplayCoordinates();
	}
}
