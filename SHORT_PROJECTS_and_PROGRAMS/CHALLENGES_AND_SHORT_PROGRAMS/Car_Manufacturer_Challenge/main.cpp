/*********************************************************
    Challenge:
    
    Create a base class called Vehicle that has the 
    manufacturer’s name (type string), number of cylinders
    in the engine (type int), and owner (type Person given 
    in the code that follows). Then create a class called 
    Truck that is derived from Vehicle and has additional 
    properties, the load capacity in tons (type double 
    since it may contain a fractional part) and towing 
    capacity in pounds (type int).
 ********************************************************/


#include <iostream>
#include <string>

using namespace std;

// Person Class
class Person {
private:
    string name;
public:
    // constructors
    Person() : name("none") {};
    Person(string theName) : name (theName) {};
    // copy constructor
    Person(const Person& theObject);
    // accessor
    string getName() const {
        return name;
    }
    // Overloading operators
    Person& operator =(const Person& theObject) {
        this->name = theObject.name;
        return (*this);
    };
    friend istream& operator >>(istream& inStream, Person& personObject) {
        cout << "Enter your name: ";
        string full_name;
        getline(inStream, personObject.name);
        return inStream;
    };
    friend ostream& operator <<(ostream& onStream, const Person& pObject) {
        onStream << pObject.getName();
        return onStream;
    };
};

// Vehicle Class
class Vehicle {
private:
    string manufacturer;
    int numCylinders;
    Person owner;
public:
    // constructors
    Vehicle() : manufacturer("Unknown Manufactory"), numCylinders(0), owner("Unknown Owner") {};
    Vehicle(string manufacturerName, int numCyl, Person theOwner){
        manufacturer = manufacturerName;
        numCylinders = numCyl;
        owner = theOwner;
    };
    // copy constructor
    Vehicle(const Vehicle& theObject);
    // accessors
    string getManufacturer() const;
    int getNumCylinders() const {
        return numCylinders;
    }
    Person getOwner() const {
        return owner;
    }
    // operator overloadings
    Vehicle& operator =(const Vehicle& theObject) {
        this->manufacturer = theObject.manufacturer;
        this->numCylinders = theObject.numCylinders;
        this->owner = theObject.owner;
        return (*this);
    };
    friend ostream& operator << (ostream& onStream, const Vehicle& vehicleObject) {
        onStream << vehicleObject.getManufacturer() << ", " << vehicleObject.getNumCylinders()
        << " cylinders, belongs to: "<< vehicleObject.getOwner();
        return onStream;
    };

};

// Truck class derived from Vehicle class
class Truck : public Vehicle {
private:
    double loadCapacity;
    int towingCapacity;
public:
    // constructors
    Truck() : Vehicle(), loadCapacity(0), towingCapacity(0) {};
    Truck(string manufacturerName, int numCyl, Person theOwner, double loadCapacity_tons, int towingCapacity_pounds) :
    Vehicle(manufacturerName, numCyl, theOwner) {
        loadCapacity = loadCapacity_tons;
        towingCapacity = towingCapacity_pounds;
    }
    // copy constructor
    Truck(const Truck& theObject);
    // operator overloadings
    Truck& operator =(const Truck& theObject) {
//        this->manufacturer = theObject.manufacturer;
//        this->numCylinders = theObject.numCylinders;
//        this->owner = theObject.owner;
        this->loadCapacity = theObject.loadCapacity;
        this->towingCapacity = theObject.towingCapacity;
        return (*this);
    };
    friend ostream& operator << (ostream& onStream, const Truck& truckObject) {
        onStream << truckObject.getManufacturer() << ", " << truckObject.getNumCylinders()
                 << " cylinders, belongs to: "<< truckObject.getOwner() << ", load capacity: "
                 << truckObject.loadCapacity << ", towing capacity: " << truckObject.towingCapacity;
        return onStream;
    };

};


int main(int argc, char * const argv[])
{
    cout << "//////////////// Testing Person Class ////////////////" << endl;
    Person defaultPerson;
    cout << "Testing default constructor: " << "the person is: " << defaultPerson << endl;

    Person prof("Sirong Lin");
    cout << "Testing constructor(string): " << "I am: " << prof << endl;

    Person copyProf(prof);
    cout << "Testing copy constructor: " << "another me is: " <<  copyProf << endl;

    Person wizard;
    cout << "Testing >> overloading: ";
    cin >> wizard;
    cout << "\t\tYou are: " << wizard << endl;

    Person copyWizard = wizard;
    cout << "Testing = overloading: ";
    cout << "Another you is: " << copyWizard << endl;

    cout << endl;
    cout << "//////////////// Testing Vehicle Class ////////////////" << endl;
    Vehicle unknownCar;
    cout << "Testing default constructor: " << "the Vehicle is: " << unknownCar << endl;

    Vehicle fordVan("Ford Van", 8, Person("Sirong Lin"));
    cout << "Testing constructor(args): " << "for my car: " << fordVan << endl;

    Vehicle copyFordVan(fordVan);
    cout << "Testing copy constructor: " << "my second same car: " <<  copyFordVan << endl;

    Vehicle myCar("Ford", 6, Person("James Smith"));
    Vehicle mySecondCar = myCar;
    cout << "Testing = overloading: " << endl;
    cout << "\t\tYour Car is: " << myCar << endl;
    cout << "\t\tYour Second Car is: " << mySecondCar << endl;

    cout << endl;
    cout << "//////////////// Testing Truck Class ////////////////" << endl;
    Truck unknownTruck;
    cout << "Testing default constructor: " << "the Truck is: " << "\n\t\t" << unknownTruck << endl;

    Truck aTruck("Mac", 8, Person("Mike Elf"), 250, 2000);
    cout << "Testing constructor(args): " << "for a truck: " << "\n\t\t" << aTruck << endl;

    Truck copyTruck(aTruck);
    cout << "Testing copy constructor: " << "copied truck: " << "\n\t\t" << copyTruck << endl;

    Truck hisTruck("Toyota Truck", 8, Person("James Smith"), 200, 5000);
    Truck hisSameTruck = hisTruck;
    cout << "Testing = overloading: " << endl;
    cout << "\t\this truck is: " << hisTruck << endl;
    cout << "\t\this same truck is: " << hisSameTruck << endl;

    return 0;
}

// Copy constructors
Person::Person(const Person& theObject)
{
    name = theObject.name;
}

Vehicle::Vehicle(const Vehicle& theObject)
{
    manufacturer = theObject.manufacturer;
    numCylinders = theObject.numCylinders;
    owner = theObject.owner;
}

string Vehicle::getManufacturer() const {
    return manufacturer;
}

Truck::Truck(const Truck& theObject) :
Vehicle(theObject.getManufacturer(), theObject.getNumCylinders(), theObject.getOwner())
{
    loadCapacity = theObject.loadCapacity;
    towingCapacity = theObject.towingCapacity;
}
