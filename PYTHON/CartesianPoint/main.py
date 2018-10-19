import random
from point import Point

#Return index farthest point
def FarthestPoint(points_list):
  index_farthest_point = 0
  for index in range(0, len(points_list)):
    if(points_list[index].GetDistanceFromOrigin() > points_list[index_farthest_point].GetDistanceFromOrigin()):
      index_farthest_point = index
  
  return index_farthest_point


def main():
      
  #Test constructor
  first_point = Point(0, 0)

  print("default coordinates: ")
  first_point.DisplayCoordinates()
  #End Test constructor

  #Test Set instructions and display
  first_point.SetX(input('Enter x value of first point: '))
  first_point.SetY(input('Enter y value of first point: '))

  print("first point coordinates: ")
  first_point.DisplayCoordinates()
  print ("distance from origin: " + str(first_point.GetDistanceFromOrigin()))
  #End test set instruction and display

  #Test GenerateSymmetricPoint
  first_point.GenerateSymmetricPoint()
  print("Symmetric point has coordinates: ")
  first_point.DisplayCoordinates()

  first_point.GenerateSymmetricPoint()
  #End Test GenerateSymmetricPoint

  #Test GetDistanceFromPoint
  line_eqns = []
  
  print("Lets build a list of line equations y = 'b'")
  line_eqns.append(input("Enter x value of b: "))
  
  while(raw_input('Do you wanna add another equation? (Y/N) \n').upper()
 == 'Y'):
    line_eqns.append(input("Enter x value of b: "))
    
  for equation in line_eqns:
    other_point = Point(first_point.GetX(), equation)
    print("Equation: y = " + str(equation))
    print("Distance from first point: " + str(first_point.GetDistanceFromPoint(other_point)))
  #End Test GetDistanceFromPoint

  #Test TranslatePoint
  translator_point= Point(input('Enter x value of translator point: '), input('Enter y value of translator point: '))
  print("first point coordinates: ")
  first_point.DisplayCoordinates()
  print("translator point coordinates: ")
  translator_point.DisplayCoordinates()

  first_point.TranslatePoint(translator_point)
  print("first point translated according to translator point has coordinates: ")
  first_point.DisplayCoordinates()
  #End Test TranslatePoint 

  #Test FarthestPoint function
  points_list = []

  for i in range(0, random.randint(4, 10)):
    new_point = Point(random.randint(-10, 10), random.randint(-10, 10))
    print("point number " + str(i))
    new_point.DisplayCoordinates() 
    points_list.append(new_point)
  
  index_farthest_point = FarthestPoint(points_list)
  print ("farthest point from origin is number: " + str(index_farthest_point))
  #End Test FarthestPoint function




if __name__ == '__main__':
  main()

    