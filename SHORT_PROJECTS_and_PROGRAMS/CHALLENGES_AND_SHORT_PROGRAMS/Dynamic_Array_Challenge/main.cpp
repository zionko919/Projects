/*********************************************************
 Purpose: <To get familiar with basics of C++: Dynamic Arrays>
 ********************************************************/


#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class DynamicStringArray {
private:
    string *dynamicArray;
    int size;
public:
    DynamicStringArray(): dynamicArray(nullptr), size(0) {};    // default constructor
    int getSize() const {return size;}; // a function that returns size
    void addEntry(string newString);
    bool deleteEntry(string searchString);
    string getEntry(int index) const;
    DynamicStringArray(const DynamicStringArray &orgList);
    ~DynamicStringArray();
//    void operator = (const DynamicStringArray& org);
    DynamicStringArray& operator = (const DynamicStringArray& value);

};

int main(int argc, char * const argv[]) {
    DynamicStringArray car;
    cout << "Array size at start = " << car.getSize() << endl;
    car.addEntry("Civic");
    car.addEntry("Corolla");
    car.addEntry("Elantra");
    car.addEntry("Camry");
    car.addEntry("Accord");
    car.addEntry("Sonata");

    DynamicStringArray names3 = names3;


    for (int i = 0; i < car.getSize(); i++) {
        cout << "Array [" << i << "]: "<< car.getEntry(i) << endl;
    }
    cout << "Array size after adding 6 cars = " << car.getSize() << endl;
    car.deleteEntry("Civic");
    car.deleteEntry("Accord");
    for (int i = 0; i < car.getSize(); i++) {
        cout << "Array [" << i << "]: "<< car.getEntry(i) << endl;
    }
    cout << "Array size after deleting Honda models = " << car.getSize() << endl;
    return 0;
}

// This will take a string as input.
// The function should create a new dynamic array one element larger than 
// dynamicArray, copy all elements from dynamicArray into the new array,
// add the new string onto the end of the new array, increment size, delete
// the old dynamicArray, and then set dynamicArray to the new array.
void DynamicStringArray::addEntry(string newString)
{
    string* original = dynamicArray; // original copied
    dynamicArray = new string[size + 1]; // create a new array
    dynamicArray[size].assign(newString);

    for (int i = 0; i < size; i++) {    // loop to copy all values and set it to the new array
        dynamicArray[i] = original[i];
    }
    if (size > 0) { // delete original
        delete [] original;
    }
    size ++;
}

// This will take a string as input.
// The function should search dynamicArray for the string. 
// If not found, it returns false. 
// If found, it creates a new dynamic array one element small than dynamicArray.
// It should copy all elements except the imput string into the new array, delete
// dynamicArray, decrement size, and return true;
bool DynamicStringArray::deleteEntry(string searchString)
{
    bool true_false = false;
    int i, j;
    for (i = 0; i < size; i++) {
        if (dynamicArray[i] == searchString) {  // matching strings
            true_false = true;
            break;
        }
    }
    if (true_false == true) {
        string *temp = dynamicArray; // new array
        dynamicArray = new string[size - 1];    // since we are deleting we need to delete on space from the size
        for (j = 0; j < size; j++) {
            if (j < i) {
                dynamicArray[j] = temp[j];  // copying all elements except the input
            } else if (j > i) {
                dynamicArray[j - 1] = temp[j];
            }
        }
        size--;
    }
    return true_false;
}

// takes an integer and returns the string at the index
string DynamicStringArray::getEntry(int index) const
{
    if(index >= size) {
        cout << "Error! your index is bigger than the array size" << endl;
        return NULL;
    } else {
        return dynamicArray[index];
    }
}

// Deep copy constructor
DynamicStringArray::DynamicStringArray(const DynamicStringArray &org)
{
    size = org.size;
    dynamicArray = new string[size];
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = org.dynamicArray[i];
    }
}
//operator overloading
DynamicStringArray& DynamicStringArray::operator = (const DynamicStringArray& value)
{
    if(size != value.size) {
        delete [] dynamicArray;
        dynamicArray = new string[value.size];
    }
    size = value.size;
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = value.dynamicArray[i];
    }
    return *this;
}

// destructor
DynamicStringArray::~DynamicStringArray()
{
    delete [] dynamicArray;
}

// operator overloading (previous)
//void DynamicStringArray::operator = (const DynamicStringArray& org){
//    DynamicStringArray temp(org);
//    if(this->size !=0)
//        delete[] this->dynamicArray;
//
//    this->size = org.getSize();
//    this->dynamicArray = new std::string[this->size];
//    for(int i = 0; i < this->size; i++)
//        this->dynamicArray[i] = org.getEntry(i);
//}












