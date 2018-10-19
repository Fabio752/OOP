import java.util.ArrayList;
import java.util.Random;

public class BiggestTriangle {
	public static void main(String[] args) {
		//Test Operators
		ArrayList<Triangle> triangles_list = new ArrayList<Triangle>();
		Random rand = new Random();

		for(int i = 0; i < rand.nextInt(10) ; i++){
			Point new_point1 = new Point(rand.nextInt(10), rand.nextInt(10));
			Point new_point2 = new Point(rand.nextInt(10), rand.nextInt(10));
			Point new_point3 = new Point(rand.nextInt(10), rand.nextInt(10));
			System.out.println("Triangle number: " + String.valueOf(i) + " Area: ");
			
			Triangle new_triangle = new Triangle(new_point1, new_point2, new_point3);
			triangles_list.add(new_triangle);
			System.out.println(String.valueOf(new_triangle.GetArea()));
		}

		int index_biggest_triangle = 0;
    
		for (int i = 0; i < triangles_list.size(); i++) {
			if (triangles_list.get(index_biggest_triangle).SmallerThan(triangles_list.get(i))) {
			index_biggest_triangle = i;
			}
		}

		System.out.println("Biggest triangle in the list is number: " + String.valueOf(index_biggest_triangle));

	}	
}
