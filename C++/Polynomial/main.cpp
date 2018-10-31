#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "point.hpp"
#include "polynomial.hpp"

using namespace std;


int main(int argc, char *argv[]){
    // {
    //     //First way of input file
    //     vector<Point> points_list;
    //     string file = "test.txt";
        
    //     ifstream inputfile;
    //     inputfile.open(file);

    //     // if inputfile is not valid
    //     if(!inputfile.is_open()){
    //         cout << "ERROR, FILE NOT FOUND" << std::endl;
    //         return 1;
    //     }
        
    //     //if inputfile is valid, store points
    //     else {
    //         double tmp;
    //         Point tmp_point(0,0);
    //         int counter = 0;
            
    //         while(inputfile >> tmp){
    //             if(!(counter % 2))
    //                 tmp_point.SetX(tmp);
    //             else{
    //                 tmp_point.SetY(tmp);
    //                 points_list.push_back(tmp_point);
    //             }
    //             counter++;

    //         }
    //         inputfile.close();
    //     }

    //     //Second way of input file
    //     vector<Point*> second_points_list;
    //     string file2 = argv[1];

    //     ifstream inputfile2;
    //     inputfile2.open(file2.c_str());
        
    //     // if inputfile is not valid
    //     if(!inputfile2.is_open()){
    //         cout << "ERROR, FILE NOT FOUND" << std::endl;
    //         return 1;
    //     }
        
    //     //if inputfile is valid, store points
    //     else {
    //         double tmp;
    //         Point* tmp_point;
    //         int counter = 0;
            

    //         while(inputfile2 >> tmp){
    //             tmp_point = new Point();
    //             if(!(counter % 2))
    //                 tmp_point->SetX(tmp);
    //             else{
    //                 tmp_point->SetY(tmp);
    //                 second_points_list.push_back(tmp_point);
    //                 cout << "list size: " <<second_points_list.size()
    //                     <<"   list capacity: " <<second_points_list.capacity() <<endl;
    //             }
    //             counter++;
    //             //tmp_point->GenerateSymmetricPoint();

    //             delete tmp_point;
    //         }
    //         inputfile2.close();
    //     }
    // }
    // cout << "end of the inner scope! " <<endl;


    ///////////////POLYNOMIAL///////////////////////////////
    //constructors test
    cout << "default constructor, polynomial1 = ";
    Polynomial polynomial_1;
    polynomial_1.DisplayPolynomial();
    cout <<endl;

    double* coefficients = new double[3];
    coefficients[0] = 2;
    coefficients[1] = 2;
    coefficients[2] = 2;
    Polynomial polynomial_2(3, coefficients);
    cout <<"costumised constructor, polynomial2 = ";
    polynomial_2.DisplayPolynomial();

    Polynomial polynomial_3(polynomial_2);
    cout <<"copy constructor, polynomial3 =  ";
    polynomial_3.DisplayPolynomial();
    //End constructors test
    
    //Test operators
    Polynomial polynomial_4 = polynomial_1;
    cout << "polynomial 4 = polynomial 1 = ";
    polynomial_4.DisplayPolynomial();
    
    polynomial_4 = polynomial_3 + polynomial_2;
    cout << "polynomial 3 + polynomial 2 = ";
    polynomial_4.DisplayPolynomial();
   
    double constant = 13;
    polynomial_4 = polynomial_3 + constant;
    cout << "polynomial3 + " <<constant << " = ";
    polynomial_4.DisplayPolynomial();
    
    polynomial_4 = polynomial_1 - polynomial_2;
    cout << "polynomial 1 - polynomial 2 = ";
    polynomial_4.DisplayPolynomial();
    
    polynomial_4 = polynomial_1 - constant;
    cout << "polynomial1 - " <<constant << " = ";
    polynomial_4.DisplayPolynomial();
   
    polynomial_4 = polynomial_3 * polynomial_3;
    cout << "polynomial 3 * polynomial 3 = ";
    polynomial_4.DisplayPolynomial();

    //End test operators

    //Test GetAndSet, Evaluate
    int index = 0;
    double value = polynomial_4.GetAndSetCoefficient(index);
    cout << "value at index: " << index << " is = " << value <<endl;
    cout <<"polynomial_4 now is: ";
    polynomial_4.DisplayPolynomial();

    double evaluation_value = 2;
    double evaluation = polynomial_4.evaluate(evaluation_value);
    cout << "polynomial_4 evaluated at " <<evaluation_value <<" is = " <<evaluation << endl;
    //End Test GetAndSet, Evaluate

    //delete [] coefficients;
    return 0;
}


