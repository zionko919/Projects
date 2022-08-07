#include "FibLFSR.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

FibLFSR::FibLFSR(string seed):seed(seed){}

int FibLFSR::step()
{
    // Get register length and if it is NOT 16-bits, print out error message and return my own number
    int reg_len = seed.length();
    if (reg_len < 16) {
        cout << "Error: Length of the Seed is LESS than 16-bits" << endl;
        return -777;
    } else if (reg_len > 16) {
        cout << "Error: Length of the Seed is GREATER than 16-bits" << endl;
        return -777;
    }

    // If Seed is not in binary format, print out error message and return my unique number.
    for (int i = 0; i < reg_len; i++) {
        if (seed[i] != '0' && seed[i] != '1' ) {
            cout << "Error: Seed is NOT in binary format" << endl;
            return -999;
        }
    }

    int leftest_val = seed[0] - 48; // Find the seed value at index 0 and then subtract ASCII value of '0' which is 48
    int tap_a = 2; // tap at 13's bit
    int tap_b = 3; // tap at 12's bit
    int tap_c = 5; // tap at 10's bit

    // Do XOR, starting with the left-most and 13's bit then 12's bit then 10's bit
    int result = ((leftest_val ^ (seed[tap_a] - 48)) ^ (seed[tap_b] - 48)) ^ (seed[tap_c] - 48);

    // use stringstream class to convert int to string
    ostringstream str1;
    string rightest_val;
    str1 << result;
    rightest_val = str1.str();

    // Get the next seed by taking off the very first bit, then append the result in string type
    seed = seed.substr(1, reg_len - 1) + rightest_val;

    // just to out put the seed and the result for step() function
    cout << seed << " " << rightest_val << endl;

    // return the result
    return result;
}

int FibLFSR::generate(int k)
{
    int bin_to_dec = 0;

    // Loop to simulating k number of steps of LFSR
    for (int i = 0; i < k; i++) {
        bin_to_dec = (bin_to_dec * 2) + step(); // double the variable and add the bit returned
    }

    // just to output the seed and the result for generate() function
    cout << seed << " " << bin_to_dec << endl;

    // return the converted integer
    return bin_to_dec;
}

// destructor
FibLFSR::~FibLFSR(){}

// String overload <<
ostream& operator<< (ostream &out, const FibLFSR &fibLfsr)
{
    out << fibLfsr.seed;
    return out;
}