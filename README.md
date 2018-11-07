# Imperial college OOP second year module exercises and assessments.
Albeit the college course is on C++, I am coding in parallel the same pieces of code in Java and Python as well.


LAB 1)
  Create a class Point with private x, y, and distance from the origin double data types.
  Implement the following member functions:
    GetX, GetY, GetDistanceFromOrigin, SetX, SetY, SetDistanceFromOrigin, DisplayCoordinates, GenerateSymmetricPoint,
    TranslatePoint.
  
  Implement a global function: FarthestPoint
  
  Write a main to test everything.
  
LAB 2)
  Create a class Triangle with private first_corner, second_corner and third_corner Point class types.
  Add to the Point class the following member operators:
    > operator (distance from the origin)
    < operator (distance from the origin)
    = operator (same coordinates).
  
  Add to the Point.cpp the following global functions:
    ClosestPointIndex
    EqualPoints
   
  Implement in the Triangle class the following member functions
    Getters for corners
    GetPerimeter
    TranslateTriangle
    GetArea
  
  Implement in the Triangle class the following operators:
    < operator (area)
    > operator (area)
    = operator (area)
  
  Implement the global function: BiggestTriangle
  
  Write a main to test everything.

LAB 3)
  Add some global functions to the class point.
    MemberPointUnorderedSearch: perform a O(n) complexity unordered search of a given point in a list of points
    MemberPointBinarySearch: perform a O(log(n)) complexity binary search of a given point in a list of points, given       that the list is sorted.
    QuickSort: perform a quicksorting operation on an unordered list of points (declared partition_vector and swap_elements functions as helper functions)
    FindPoint: perform either a Binary Search or an Unordered Search determined on if the list is sorted or not.
    CommonPoints: Populate a passed by reference vector with the points which are in both the two lists given.
    TestCommonPoints: test the functionality of CommonPoints by reading two txt files containing the two lists of points, generate the common_points vector and provide it as output in a output.txt file.
   

LAB 4) Polynomial class, use of destructor and constructors, overload operators.

LAB 5) Complete Polynomial class with << operator, concatenation test, self assignment test, labeled_point class and operators.
