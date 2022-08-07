/*********************************************************
*****************/


#include <iostream>
#include <string>

using namespace std;

void testPFArrayD(void);
void testException(void);

//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
    PFArrayD( ) : capacity(50), used(0) {a = new double[capacity];};     //Initializes with a capacity of 50.
    PFArrayD(int capacityValue) : capacity(capacityValue), used(0) {a = new double[capacity];};
    PFArrayD(const PFArrayD& pfaObject);    //copy constructor
    void addElement(double element);    //Precondition: The array is not full. Postcondition: The element has been added.
    bool full( ) const { return (capacity == used); }     //Returns true if the array is full, false otherwise.
    int getCapacity( ) const { return capacity; }
    int getNumberUsed( ) const { return used; }
    void emptyArray( ){ used = 0; }     //Empties the array.
    double& operator[](int index);     //Read and change access to elements 0 through numberUsed - 1.
    PFArrayD& operator =(const PFArrayD& rightSide);
    ~PFArrayD( ) {  //destructor
        delete [] a;
    };
private:
    double *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.

};

class OutOfRange {
private:
    int indexTest;
    string someArgument;
public:
    OutOfRange() : indexTest(0), someArgument("Error!") {};
    OutOfRange(int value, string newString) : indexTest(value), someArgument(newString) {};
    int index() const {return indexTest;}
    string err() const {return someArgument;}
};

int main(int argc, char *argv[])
{
    cout << "This program tests the class PFArrayD.\n";

    char ans;
    do
    {
//        testPFArrayD( );
        testException();
        cout << "Test again? (y/n) ";
        cin >> ans;
    }while ((ans == 'y') || (ans == 'Y'));

    return 0;
}

void testPFArrayD( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }

    cout << "You entered the following "
         << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}

void testException(void)
{
    cout << "*****Testing exceptions*****" << endl;
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    double next;
    int tf = 0;
    try {
        cout << "Enter up to " << cap << " nonnegative numbers.\n";
        cout << "Place a negative number at the end.\n";
        cin >> next;
        while (next >= 0) {
            temp.addElement(next);
            cin >> next;
        }
    }
    catch (OutOfRange e) {
        cout << e.err() << endl;
//        tf = 1;
    }
//    if (tf == 0) {
        cout << "*****Array Result*****" << endl;
        cout << "You entered the following " << temp.getNumberUsed( ) << " numbers:\n";
        int index;
        int count = temp.getNumberUsed( );
        for (index = 0; index < count; index++) {
            try {
                cout << temp[index] << " ";
            }
            catch (OutOfRange e) {
                cout << e.err() << endl;
            }
        }
        cout << endl;
        cout << "(plus a sentinel value.)\n";
        cout << "*****Testing Indexing*****" << endl;
        int testIndex;
        try {
            cout << "Select an index to test indexing: ";
            cin >> testIndex;
            cout << "Value at index [" << testIndex <<"]:\n" << temp[testIndex] << endl;
        }
        catch (OutOfRange e) {
            cout << e.err() << endl;
        }
//    }
}


PFArrayD::PFArrayD(const PFArrayD& pfaObject) : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new double [capacity];
    for (int i = 0; i < used; i++) {
        a[i] = pfaObject.a[i];
    }
}

void PFArrayD::addElement(double element)
{
    if (used >= capacity) {
        throw OutOfRange(capacity+1,"Error! You have exceeded the capacity");
//        cout << "Error! Capacity exceeded!" << endl;
        exit(1);
    }
    a[used] = element;
    used++;
}

double& PFArrayD::operator[](int index)
{
    if (index < 0 || index >= capacity) {
        throw OutOfRange(index,"Error! INVALID INDEX!");
//        cout << "Error! Index is out of bound!" << endl;
        exit(1);
    }
    return a[index];
}

PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide)
{
    if (capacity != rightSide.capacity) {
        delete [] a;
        a = new double [rightSide.capacity];
    }
    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++) {
        a[i] = rightSide.a[i];
    }
    return *this;
}


