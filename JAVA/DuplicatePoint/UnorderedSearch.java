
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;

public class UnorderedSearch{

  public static void main(String[] args) throws Exception{
    System.out.println("############### UNORDERED SEARCH TEST ###########");

    ArrayList<Point> points_list = new ArrayList<Point>();
    Point search_point = new Point(20, 22);
    System.out.println("Point to search: ");
    search_point.DisplayCoordinates();

    File file = new File("test.txt"); 
    Scanner input = new Scanner(file); 
    
    while (input.hasNextDouble()){
      Point tmp_point = new Point(input.nextDouble(), input.nextDouble());
      points_list.add(tmp_point); 
    } 
    
    for(int i = 0; i < points_list.size(); i++){
      if(search_point.EqualTo(points_list.get(i))){
        System.out.println("Present in the list at index: " + String.valueOf(i));
        System.out.println("############### END UNORDERED SEARCH TEST ###########");
        System.exit(0);
      }
    }
    System.out.println("Not present in the list: " + String.valueOf(points_list.size()));
    
    System.out.println("############### END UNORDERED SEARCH TEST ###########");
  }

}