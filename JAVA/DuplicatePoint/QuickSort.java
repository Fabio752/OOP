
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;

public class QuickSort {
 
  public static void Sort(int low, int high, ArrayList<Point> points_list){
    if(low < high){
      int pivot = partition_vector(low, high, points_list);

      Sort(low, pivot -1, points_list);
      Sort(pivot + 1, high, points_list);
    }
  }
  
   public static void swap_elements(Point first_point, Point second_point){
    Point tmp = new Point(0, 0);
    tmp.SetX(first_point.GetX());
    tmp.SetY(first_point.GetY());

    first_point.SetX(second_point.GetX()); 
    first_point.SetY(second_point.GetY());
   
    second_point.SetX(tmp.GetX());
    second_point.SetY(tmp.GetY());
  }

  public static int partition_vector(int low, int high, ArrayList<Point> points_list){
    Point pivot = points_list.get(high);    
    int index_smaller_element = low - 1; 
  
    for (int i = low; i < high; i++) { 
      if (points_list.get(i).SmallerThan(pivot)) { 
        index_smaller_element++; 
        swap_elements(points_list.get(index_smaller_element), points_list.get(i)); 
      } 
    } 
    swap_elements(points_list.get(index_smaller_element + 1), points_list.get(high)); 
    return index_smaller_element + 1; 
  }

  public static void main(String[] args) throws Exception{
    System.out.println("############### QUICKSORT TEST ###########");

    ArrayList<Point> points_list = new ArrayList<Point>();

    File file = new File("test2.txt"); 
    Scanner input = new Scanner(file); 
    
    while (input.hasNextDouble()){
      Point tmp_point = new Point(input.nextDouble(), input.nextDouble());
      points_list.add(tmp_point); 
    } 
    
    Sort(0, points_list.size() - 1, points_list);
    
    for(int i = 0; i < points_list.size(); i++){
      System.out.println("Point number: " + String.valueOf(i));
      points_list.get(i).DisplayCoordinates();
    }

    System.out.println("############### END QUICKSORT TEST ###########");
  }
}