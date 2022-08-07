/*********************************************************
 Purpose: <To get familiar with basics of C++: Operator Overloading>
 ********************************************************/


#include <iostream>
#include <cstdlib>

using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

public:
    // constructors
    Rational(): numerator(0), denominator(1){};   // default constructor (0/1)
    Rational(int wholeNumber): numerator(wholeNumber), denominator(1){};
    Rational(int initNume, int initDeno){
        int tempNume;
        int tempDeno;
        int temp;
        if (initDeno == 0) {
            cout << "Error! You cannot have 0 in the denominator" << endl;
            exit(1);
        } else {
            tempNume = initNume;
            tempDeno = initDeno;
            temp = gcd(tempNume, tempDeno);
            tempNume /= temp;
            tempDeno /= temp;
            if (tempNume < 0 && tempDeno < 0) {
                tempNume *= -1;
                tempDeno *= -1;
            } else if (tempNume > 0 && tempDeno < 0) {
                tempNume *= -1;
                tempDeno *= -1;
            }
        }
        numerator = tempNume;
        denominator = tempDeno;
    };

    // getters
    int getNume() const {return numerator;};
    int getDeno() const {return denominator;};

    // operator overloading functions
    friend const Rational operator + (const Rational& fractionA, const Rational& fractionB);
    friend const Rational operator * (const Rational& fractionA, const Rational& fractionB);
    friend const Rational operator / (const Rational& fractionA, const Rational& fractionB);
    friend const Rational operator - (const Rational& fractionA, const Rational& fractionB);
    friend bool operator == (const Rational& fractionA, const Rational& fractionB);
    friend bool operator <= (const Rational& fractionA, const Rational& fractionB);
    friend bool operator < (const Rational& fractionA, const Rational& fractionB);
    friend bool operator >= (const Rational& fractionA, const Rational& fractionB);
    friend bool operator > (const Rational& fractionA, const Rational& fractionB);
    friend ostream &operator << (ostream &outStream, const Rational &fraction);
    friend istream &operator >> (istream &inStream, Rational &fraction);

    int gcd(int numA, int numB)
    {
        if (numB == 0) {
            return numA;
        } else {
            return gcd(numB, numA % numB);
        }
    }
};

int gcd(int numA, int numB);

int main(int argc, char* argv[])
{
    // testing constructors
    cout << "Some tests..." << endl;
    Rational A;
    cout << "Value of A (default constructor): " << A << endl;
    Rational B(12);
    cout << "Value of B (wholenumber): " << B << endl;
    Rational C(-2,10);
    cout << "Value of C (nume/deno): " << C << endl;
    Rational D(9,-3);
    cout << "Value of D (nume/deno): " << D << endl;
    cout << "1) C + D: " << C + D << endl;
    cout << "2) C - D: " << C - D << endl;
    cout << "3) C * D: " << C * D << endl;
    cout << "4) C / D: " << C / D << endl;
    if (C < D) {cout << "5) C < D is TRUE" << endl;} else {cout << "5) C < D is FALSE" << endl;}
    if (C > D) {cout << "6) C > D is TRUE" << endl;} else {cout << "6) C > D is FALSE" << endl;}
    if (C <= D) {cout << "7) C <= D is TRUE" << endl;} else {cout << "7) C <= D is FALSE" << endl;}
    if (C >= D) {cout << "8) C >= D is TRUE" << endl;} else {cout << "8) C >= D is FALSE" << endl;}
    if (C == D) {cout << "9) C == D is TRUE" << endl;} else {cout << "9) C == D is FALSE" << endl;}
    cout << endl;
    // testing any rational numbers
    Rational rationalNumA, rationalNumB;
    cout << "***** Testing User's Two Rational Numbers *****" << endl;
    cout << "Description: This program will test out every overloaded operators." << endl;
    cout << "WARNING: This program terminates if there is an error" << endl;
    cout << "Enter your first rational number: ";
    cin >> rationalNumA;
    cout << "Enter you second rational number: ";
    cin >> rationalNumB;
    cout << "****************** RESULTS ********************" << endl;
    cout << "All results will be in the simplest form." << endl;

    cout << "First Rational Number after the normalization: " << rationalNumA << endl;
    cout << "Second Rational Number after the normalization: " << rationalNumB << endl;
    cout << "Addition: " << rationalNumA + rationalNumB << endl;
    cout << "Subtraction: " << rationalNumA - rationalNumB << endl;
    cout << "Multiplication: " << rationalNumA * rationalNumB << endl;
    cout << "Division: " << rationalNumA / rationalNumB << endl;
    bool less = rationalNumA < rationalNumB;
    if (less) {
        cout << rationalNumA << " < " << rationalNumB << endl;
    } else {
        cout << rationalNumA << " is not less than " << rationalNumB << endl;
    }
    bool lessThanEqual = rationalNumA <= rationalNumB;
    if (lessThanEqual) {
        cout << rationalNumA << " <= " << rationalNumB << endl;
    } else {
        cout << rationalNumA << " is not less than equal to " << rationalNumB << endl;
    }
    bool greater = rationalNumA > rationalNumB;
    if (greater) {
        cout << rationalNumA << " > " << rationalNumB << endl;
    } else {
        cout << rationalNumA << " is not greater than " << rationalNumB << endl;
    }
    bool greaterThanEqual = rationalNumA >= rationalNumB;
    if (greaterThanEqual) {
        cout << rationalNumA << " >= " << rationalNumB << endl;
    } else {
        cout << rationalNumA << " is not greater than equal to " << rationalNumB << endl;
    }
    bool equal = rationalNumA == rationalNumB;
    if (equal) {
        cout << rationalNumA << " = " << rationalNumB << endl;
    } else {
        cout << rationalNumA << " is not equal to " << rationalNumB << endl;
    }

    return 0;
}

const Rational operator + (const Rational& fractionA, const Rational& fractionB)
{
    int tempNume = (fractionA.getNume()  * fractionB.getDeno()) + (fractionB.getNume() * fractionA.getDeno());
    int tempDeno = (fractionA.getDeno() * fractionB.getDeno());
    int temp = gcd(tempNume, tempDeno);
    tempNume /= temp;
    tempDeno /= temp;
    if (tempNume < 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    } else if (tempNume > 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    }
    return Rational(tempNume, tempDeno);
}

const Rational operator * (const Rational& fractionA, const Rational& fractionB)
{
    int tempNume = fractionA.getNume() * fractionB.getNume();
    int tempDeno = (fractionA.getDeno() * fractionB.getDeno());
    int temp = gcd(tempNume, tempDeno);
    tempNume /= temp;
    tempDeno /= temp;
    if (tempNume < 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    } else if (tempNume > 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    }
    return Rational(tempNume, tempDeno);
}
const Rational operator / (const Rational& fractionA, const Rational& fractionB)
{
    int tempNume = fractionA.getNume() * fractionB.getDeno();
    int tempDeno = (fractionA.getDeno() * fractionB.getNume());
    int temp = gcd(tempNume, tempDeno);
    tempNume /= temp;
    tempDeno /= temp;
    if (tempNume < 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    } else if (tempNume > 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    }
    return Rational(tempNume, tempDeno);
}

const Rational operator - (const Rational& fractionA, const Rational& fractionB)
{
    int tempNume = (fractionA.getNume()  * fractionB.getDeno()) - (fractionB.getNume() * fractionA.getDeno());
    int tempDeno = (fractionA.getDeno() * fractionB.getDeno());
    int temp = gcd(tempNume, tempDeno);
    tempNume /= temp;
    tempDeno /= temp;
    if (tempNume < 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    } else if (tempNume > 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    }
    return Rational(tempNume, tempDeno);
}

bool operator == (const Rational& fractionA, const Rational& fractionB)
{
    return((fractionA.getNume() * fractionB.getDeno()) == (fractionA.getDeno() * fractionB.getNume()));
}

bool operator <= (const Rational& fractionA, const Rational& fractionB)
{
    return(((fractionA.getNume() * fractionB.getDeno()) < (fractionA.getDeno() * fractionB.getNume())) ||
            ((fractionA.getNume() * fractionB.getDeno()) == (fractionA.getDeno() * fractionB.getNume())));
}

bool operator < (const Rational& fractionA, const Rational& fractionB)
{
    return(((fractionA.getNume() * fractionB.getDeno()) < (fractionA.getDeno() * fractionB.getNume())));
}

bool operator >= (const Rational& fractionA, const Rational& fractionB)
{
    return(((fractionA.getNume() * fractionB.getDeno()) > (fractionA.getDeno() * fractionB.getNume())) ||
           ((fractionA.getNume() * fractionB.getDeno()) == (fractionA.getDeno() * fractionB.getNume())));
}

bool operator > (const Rational& fractionA, const Rational& fractionB)
{
    return(((fractionA.getNume() * fractionB.getDeno()) > (fractionA.getDeno() * fractionB.getNume())));
}

ostream &operator << (ostream &outStream, const Rational &fraction)
{
    int tempNume = fraction.getNume();
    int tempDeno = fraction.getDeno();
    int temp = gcd(tempNume, tempDeno);
    tempNume /= temp;
    tempDeno /= temp;
    if (tempNume < 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    } else if (tempNume > 0 && tempDeno < 0) {
        tempNume *= -1;
        tempDeno *= -1;
    }
    outStream << tempNume << "/" << tempDeno;

    return outStream;
}

istream &operator >> (istream &inStream, Rational &fraction)
{
    char fracSign;
    int inNume, inDeno;
    inStream >> inNume;
    inStream >> fracSign;
    if (fracSign != '/') {
        cout << "Error! Wrong format, please include / between your numerator and denominator" << endl;
        cout << "Program terminating..." << endl;
        exit(1);
    }
    inStream >> inDeno;
    if (inDeno == 0) {
        cout << "Error! You cannot have 0 in the denominator!" << endl;
        cout << "Program terminating..." << endl;
        exit(1);
    }
    if (inNume < 0 && inDeno < 0) {
        inNume *= -1;
        inDeno *= -1;
    } else if (inNume > 0 && inDeno < 0) {
        inNume *= -1;
        inDeno *= -1;
    }
    fraction = Rational(inNume, inDeno);
    return inStream;
}

// a recursive function that calculates GCD;
int gcd(int numA, int numB)
{
    if (numB == 0) {
        return numA;
    } else {
        return gcd(numB, numA % numB);
    }
}
