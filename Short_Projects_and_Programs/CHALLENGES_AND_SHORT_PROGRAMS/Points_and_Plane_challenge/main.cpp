/*********************************************************
 Purpose: <To get familiar with basics of C++: Class>

    A program with  a definition of a class named Point 
    that might be used to store and manipulate the location 
    of a point in the plane. 
    Declared and implemented functions:
        • A member function that sets the private data 
            after an object of this class is created.
        • A member function to move the point by an amount 
            along the vertical and horizontal directions 
            specified by the first and second arguments, 
            e.g., the current coordinate is (3, 4) 
            and moved by (1, 1), that is, one up, one right.
        • A member function to rotate the point by 90 
            degrees clockwise around the origin.
        • Two accessor functions to retrieve the current 
            coordinates of the point.

 ********************************************************/
    

#include <iostream>

using namespace std;

void getInput(int& num);
void clearBuffer();

class Point
{
public:
    void setData(int x_input, int y_input); // sets the private data after Point object is created.
    void moveData(int vertical, int horizontal); // moves the point by the amount along the vertical and horizontal directions.
    void rotateData(); // rotates the point by 90 degrees clockwise around the origin.
    int getX(); // first accessor function to retrieve x-coordinate.
    int getY(); // second accessor function to retrieve y- coordinate.
private:
    int xValue;
    int yValue;
};

int main()
{
    Point coordinates;  // declaring object variable.
    int x, y;   // declaring integer variable.

    cout << "Enter x-coordinate: ";
    getInput(x); // stores x-coordinate into int x;
    clearBuffer();
    cout << "Enter y-coordinate: ";
    getInput(y); // stores y-coordinate into int x;
    clearBuffer();
    coordinates.setData(x, y); // calling mutator function to set the point.
    cout << "Current coordinate: (" << coordinates.getX() << ", " << coordinates.getY() << ")" << endl; // outputs the current point by using two accessor functions.

    cout << "Enter your vertical move amount: ";
    getInput(x);
    clearBuffer();
    cout << "Enter your horizontal move amount: ";
    getInput(y);
    clearBuffer();
    coordinates.moveData(x, y); // calling mutator function to move the current point.
    cout << "Current coordinates after moving: (" << coordinates.getX() << ", " << coordinates.getY() << ")" << endl;

    coordinates.rotateData();   // calling mutator function to rotate the current point.
    cout << "Current coordinates after rotating: (" << coordinates.getX() << ", " << coordinates.getY() << ")" << endl;
    cout << "\n***Test Cases from the Instruction*****" << endl;

    /* Test case 1: We start with (1, 2). This point is rotated 90 degrees, four times,
     * getting back to the original point.*/
    Point test1;
    test1.setData(1, 2);
    cout << "Test 1 coordinates: (" << test1.getX() << ", " << test1.getY() << ")" << endl;
    test1.rotateData();
    test1.rotateData();
    test1.rotateData();
    test1.rotateData();
    cout << "Test 1 coordinates after 4 rotations: (" << test1.getX() << ", " << test1.getY() << ")" << endl;
    cout << endl;

    /*The point (3, 4) is set and moved by (1, 1),that is,one up,one right.*/
    Point test2;
    test2.setData(3,4);
    cout << "Test 2 coordinates: (" << test2.getX() << ", " << test2.getY() << ")" << endl;
    test2.moveData(1,1);
    cout << "Test 2 coordinates after moving 1 right, 1 up: (" << test2.getX() << ", " << test2.getY() << ")" << endl;
    cout << endl;

    /*The point, (5, -4) is set and moved by (-5, 4) 5 left, 4 up. Then we move it back to the origin, (0, 0).*/
    Point test3;
    test3.setData(5,-4);
    cout << "Test 3 coordinates: (" << test3.getX() << ", " << test3.getY() << ")" << endl;
    test3.moveData(-5,4);
    cout << "Test 3 coordinates after moving 5 left, 4 up: (" << test3.getX() << ", " << test3.getY() << ")" << endl;
    cout << endl;

    return 0;
}

// a mutator function that sets the private data after Point object is created.
void Point::setData(int x_input, int y_input)
{
    xValue = x_input;    // sets private x-coordinate data
    yValue = y_input;    // sets private y-coordinate data
}

// a mutator function that moves the point by the amount along the vertical and horizontal directions.
void Point::moveData(int vertical, int horizontal)
{
    xValue += vertical;    // moves x-coordinate
    yValue += horizontal;  // moves y-coordinate
}

// a mutator function that rotates the point by 90 degrees clockwise around the origin.
void Point::rotateData()
{
    int newX = yValue;  // store current y-coordinate data in to newX
    int newY = 0 - xValue; // store inversed x-coordinate data into newY
    xValue = newX; // mutate current xValue with newX.
    yValue = newY; // mutate current yValue with newY.
}

// first accessor function to retrieve x-coordinate.
int Point::getX()
{
    return xValue;
}

// second accessor function to retrieve y-coordinate.
int Point::getY()
{
    return yValue;
}

// a simple function to get inputs from the user
void getInput(int& num)
{
    cin >> num;
}

// a simple function to clear keyboard buffer
void clearBuffer()
{
    cin.clear();
    cin.ignore(10000, '\n');
}