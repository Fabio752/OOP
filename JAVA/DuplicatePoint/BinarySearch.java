
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;

public class BinarySearch {

  public static void main(String[] args) throws Exception{
    System.out.println("############### BINARY SEARCH TEST ###########");

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
    
    int base_index = points_list.size()/2;
    int offset = points_list.size();
    while(offset >= 1){
      offset /= 2;

      if(search_point.EqualTo(points_list.get(base_index))){
        System.out.println(" Present in the list at index: " + String.valueOf(base_index));
        System.out.println("############### END BINARY SEARCH TEST ###########");
        System.exit(0);
      }
      else{
        if(search_point.GreaterThan(points_list.get(base_index))){
          if(offset == 1)
              base_index += offset;
          else
              base_index += offset/2; 
        }
        else{
          if(offset == 1)
              base_index -= offset;
          else
              base_index-= offset/2;
        }
      }
    }
    System.out.println("Not present in the list: " + String.valueOf(points_list.size()));

    System.out.println("############### END BINARY SEARCH TEST ###########");
  }

}