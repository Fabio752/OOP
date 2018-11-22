/*
run with:
g++ shapes.cpp -o s && \
./s > shape.svg && \
display shape.svg
*/

#include <iostream>
#include <vector>
using namespace std;

class Point {
 public:
  Point(int x, int y) : x_(x), y_(y) {}
  
  int GetX() const {
    return x_;
  }
  int GetY() const {
    return y_; 
  }
 
 private:
  int x_, y_;
};

void DrawLine (const Point& p1, const Point& p2);
void DrawLine (double x1, double x2, double y1, double y2);

class Shape {
 public:
  virtual void Draw() {};
};

class Square : Shape {
 public:
   Square(const std::vector<Point> c) {
     if (c.size() != 4) {
      exit(40);
    };
    for (Point coord : c) {
      coords_.push_back(coord); 
    }
  }

  void Draw() {
    for (int i = 0; i < 4; i++) {
      DrawLine(coords_[i], coords_[(i + 1) % 4]);
    }
  }

 private:
  std::vector<Point> coords_;
};

class Triangle : Shape {
 public:
  Triangle(const std::vector<Point> c) {
    if (c.size() != 3) {
      exit(30);
    };
    for (Point coord : c) {
      coords_.push_back(coord); 
    }
  }

  void Draw() {
    for (int i = 0; i < 3; i++) {
      DrawLine(coords_[i], coords_[(i + 1) % 3]);
    }
  }

 private:
  std::vector<Point> coords_;
};

int main () {
  std::vector<Point> v = {Point(250, 500), Point(500, 500), Point(500, 750), Point(250, 750)};
  std::vector<Point> v1 = {Point(100, 500), Point(500, 500), Point(500, 900)};
  Square sq(v);
  Triangle tr(v1);
  double width = 1000, height = 1000;
  cout << "<svg width=\"" << width << "\" height=\"" << height << "\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;
  cout << "<style type=\"text/css\">line{stroke:black;stroke-width:1;stroke-opacity:0.5;stroke-linecap:round;}</style>" << endl;
  //DrawLine (10, 50, 10, 50);
  //DrawLine (25, 100, 50, 50);
  sq.Draw();
  //tr.Draw();
  cout << "</svg>" << endl ;
}

void DrawLine (const Point& p1, const Point& p2) {
  cout << "<line x1=\"" << p1.GetX() << "\" x2=\"" << p2.GetX() << "\" y1=\"" << p1.GetY() <<"\" y2=\"" << p2.GetY() << "\"/>" << endl;
}

void DrawLine (double x1, double x2, double y1, double y2) {
  cout << "<line x1=\"" << x1 << "\" x2=\"" << x2 << "\" y1=\"" << y1 <<"\" y2=\"" << y2 << "\"/>" << endl;
}