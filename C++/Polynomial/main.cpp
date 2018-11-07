#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "point.hpp"
#include "labeled_point.hpp"
#include "polynomial.hpp"

using namespace std;


int main(int argc, char *argv[]){

    //Test 1) at(int) member function
    double coefficients[3];
    Polynomial p(2, coefficients);
    cout << p << endl;
    p.At(0, 2); p.At(1, 3); p.At(2, 1);
    cout << p << endl;
    //Test 2) copy constructor
    Polynomial p1(p);
    cout << p1 << endl;
    //Test 3) subscript operator[]
    p[0] = 5; p[1] = -4; p[2] = 3;
    cout << p << endl;
    //Test 4) assignment operator
    Polynomial p2 = p;
    cout <<p2 << endl;
    p = p; //self assignment
    Polynomial p3 = p2 = p1; //chain assignment
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

    Point po(1, 2);
    string a = "A";
    LabeledPoint lp(2, 3, a);
    cout << "p == lp? " << (po == lp) << endl;
    cout << "lp == p? " << (lp == po) << endl;
    cout << "p < lp? " << (po < lp) << endl;
    cout << "lp < p? " << (lp < po) << endl;
    return 0;
}


