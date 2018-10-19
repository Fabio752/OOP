
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
        points_list.get(i).DisplayCoordinates();
      }
    
    Point farthest_point = points_list.get(0);
    
    for (int i = 0; i < points_list.size(); i++) {
      if (farthest_point.GetDistanceFromOrigin() < points_list.get(i).GetDistanceFromOrigin()) {
        farthest_point = points_list.get(i);
      }
    }

    System.out.println("Farthest point in the list : ");
    farthest_point.DisplayCoordinates();
    System.out.println(" with distance: " + String.valueOf(farthest_point.GetDistanceFromOrigin()));
    
  }

}
