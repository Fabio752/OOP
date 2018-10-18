
import java.util.ArrayList;
import java.util.Random;

public class FarthestPoint{

  public static void main(String[] args) {
    ArrayList<Point> points_list = new ArrayList<Point>();
    Random rand = new Random();
    for (int i = 0; i < rand.nextInt(20); i++) {
      points_list.add(new Point(rand.nextInt(20), rand.nextInt(20)));
    }
    
    for (int i = 0; i < points_list.size(); i++) {
        System.out.println("point number " + String.valueOf(i));
        System.out.println("coordinates: ");
        points_list.get(i).display_coord();
      }
    
    Point farthest_point = points_list.get(0);
    
    for (int i = 0; i < points_list.size(); i++) {
      if (farthest_point.get_distance_from_origin() < points_list.get(i).get_distance_from_origin()) {
        farthest_point = points_list.get(i);
      }
    }

    System.out.println("Farthest point in the list : ");
    farthest_point.display_coord();
    System.out.println(" with distance: " + String.valueOf(farthest_point.get_distance_from_origin()));
    
  }

}
