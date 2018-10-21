import math


#Global function
def FarthestPoint(points_list):
  index_farthest_point = 0
  for index in range(0, len(points_list)):
    if(points_list[index].GetDistanceFromOrigin() > points_list[index_farthest_point].GetDistanceFromOrigin()):
      index_farthest_point = index
  
  return index_farthest_point


class Point:
  
  def __init__(self, x, y):
    self.__x = x
    self.__y = y
    self.__distance = math.sqrt(pow(x, 2) + pow(y, 2))
    
  def GetX(self):
    return self.__x

  def GetY(self):
    return self.__y

  def GetDistanceFromOrigin(self):
    return self.__distance

  def SetX(self, x):
    self.__x = x
    self.SetDistanceFromOrigin()
    
  def SetY(self, y):
    self.__y = y
    self.SetDistanceFromOrigin()

  def SetDistanceFromOrigin(self):
    self.__distance = math.sqrt(pow(self.__x, 2) + pow(self.__y, 2))

  def DisplayCoordinates(self):
    print "(" + str(self.GetX()) + ", " + str(self.GetY()) + ")"
  
  def GetDistanceFromPoint(self, other_point):
    return math.sqrt(pow(self.__x - other_point.GetX(), 2) + pow(self.__y - other_point.GetY(), 2))

  def GenerateSymmetricPoint(self):
    self.__x = -self.GetX()
    self.__y = -self.GetY()

  def TranslatePoint(self, translator_point):
    self.__x += translator_point.GetX() 
    self.__y += translator_point.GetY()      



