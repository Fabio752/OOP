#include <iostream>
#include <string>
#include <vector>
#include "point.hpp"
#include <ctime>

using namespace std;

int ReturnFarthestPointIndex(vector<Point> const& points_list); //global function

int main(){
    //initialise time
    srand(time(NULL));
    
    
    //Start Test Constructors
    Point first_point(5, 5);
    Point other_point;
    
    cout <<"constructor(5,5) called for first point, output: ";
    first_point.DisplayCoordinates();
    cout <<endl;
    
    cout <<"constructor() called for other point, output: ";
    other_point.DisplayCoordinates();
    cout <<endl;
    
    //End Constructors' testing

    
    
    vector<double> line_eqns;
    double value, dist;
    bool inserting = true;
    string answer;
    
    
    //Start Testing SetX, SetY, DisplayCoordinates, GenerateSymmetricPoint functions
    cout <<"Set value x of first point: " <<endl;
    cin >> value;
    first_point.SetX(value);
    
    cout <<"Set value y of first point: " <<endl;
    cin >> value;
    first_point.SetY(value);
        
    cout <<"the chosen point has coordinates: " ;
    first_point.DisplayCoordinates();

    
    first_point.GenerateSymmetricPoint();
    cout <<"the symmetric point coordinates are: ";
    first_point.DisplayCoordinates();
    
    first_point.GenerateSymmetricPoint(); //back how it was
    
    
    //End Testing SetX, SetY, DisplayCoordinates, GenerateSymmetricPoint functions

    
    //Start Testing GetDistanceFromPoint function
    while (inserting == true){
        
        cout << "insert a value 'b' to form equation y = b : " << endl;
        cin >> value;
        line_eqns.push_back(value);
        
        cout << "do you want to insert one more? (Y,N): " <<endl;
        cin >> answer;
        if (answer == "N")
            inserting = false;
    }
    
    other_point.SetX(first_point.GetX());
    
    for(int i = 0; i < line_eqns.size(); i++){
        
        other_point.SetY(line_eqns[i]);
        dist = first_point.GetDistanceFromPoint(other_point);
        cout <<"line eqns:  y = " <<line_eqns[i] << endl;
        cout <<"distance from first point = " <<dist <<endl;
    }
    
    //End testing GetDistanceFromPoint function 
    
    
    //Test TranslatePoint function
    cout <<"Set value x of other point: " <<endl;
    cin >> value;
    other_point.SetX(value);
    
    cout <<"Set value y of other point: " <<endl;
    cin >> value;
    other_point.SetY(value);
        
    cout <<"the chosen point has coordinates: " ;
    other_point.DisplayCoordinates();
    
    
    cout <<"the first point ";
    first_point.DisplayCoordinates();
    cout << " translated accordingly to the second point, has coordinates: ";
    
    first_point.TranslatePoint(other_point);
    first_point.DisplayCoordinates(); 
    
    //End test TranslatePoint function
    
    
    //Start test global return_index_farthest_point function
    vector<Point> points_list;
    
    for(int i = 0; i < rand() % 10; i++){
        Point random_point;
        random_point.SetX(rand() % 10);
        random_point.SetY(rand() % 10);
        points_list.push_back(random_point);
        
        cout <<"random generated point number: " << i <<" with coordinates: ";
        random_point.DisplayCoordinates();
        cout <<endl;
    }
    
    int index_farthest_point = ReturnFarthestPointIndex(points_list);

    cout <<"the farthest point of the list is the number: " <<index_farthest_point <<" and has distance from origin : " <<points_list[index_farthest_point].GetDistanceFromOrigin() <<endl;
    
    
    //End test global return_index_farthest_point function

    return 0;
}


//Global function declaration
int ReturnFarthestPointIndex(vector<Point> const& points_list) {
    int return_index = 0;
    
    for(int i = 1; i < points_list.size(); i++)
        
        if(points_list[i].GetDistanceFromOrigin() > points_list[return_index].GetDistanceFromOrigin())
            return_index = i;
    
    return return_index;
    
}

