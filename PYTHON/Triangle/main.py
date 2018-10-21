import random
from point import *
from triangle import *

def main():
      
  first_corner = Point(5, 2.2);
  second_corner = Point(8, 7);
  third_corner = Point(12, -1);
      
  triangle = Triangle(first_corner, second_corner, third_corner);
  print("Triangle corners are: ");
  triangle.GetFirstCorner().DisplayCoordinates();
  triangle.GetSecondCorner().DisplayCoordinates();
  triangle.GetThirdCorner().DisplayCoordinates();
      
  #Test GetPerimeter function
  print("Triangle perimeter = " + str(triangle.GetPerimeter()));
  #End Test GetPerimeter function
      
  #Test TranslateTriangle function
  translator_point = Point(random.randint(1, 10), random.randint(1, 10));
  triangle.TranslateTriangle(translator_point);
      
  print("Translate triangle according to point: ");
  translator_point.DisplayCoordinates();
  
  triangle = Triangle(first_corner, second_corner, third_corner);

  print("New triangle corners are: ");
  triangle.GetFirstCorner().DisplayCoordinates();
  triangle.GetSecondCorner().DisplayCoordinates();
  triangle.GetThirdCorner().DisplayCoordinates();
      
  print("Perimeter always = " + str(triangle.GetPerimeter()) + "\n");
  #End Test TranslateTriangle function

  triangles_list = []
  for i in range(0, random.randint(1,10)):
    print("triangle number: " + str(i))
    first_corner = Point(random.randint(-10, 10), random.randint(-10, 10))
    second_corner = Point(random.randint(-10, 10), random.randint(-10, 10))
    third_corner = Point(random.randint(-10, 10), random.randint(-10, 10))
    rand_triangle = Triangle(first_corner, second_corner, third_corner)
    print(rand_triangle.GetArea())
    triangles_list.append(rand_triangle)
  
  index_biggest_triangle = BiggestTriangle(triangles_list)
  print("biggest triangle is number: " + str(index_biggest_triangle))
  

if __name__ == '__main__':
  main()

    