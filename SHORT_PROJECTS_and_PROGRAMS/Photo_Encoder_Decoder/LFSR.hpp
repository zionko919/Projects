/* **************************************************************************
 * Description: A program that encrypt and decrypt a photo with seed input.
 * **************************************************************************/

#ifndef _FIBLFSR_H
#define _FIBLFSR_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class FibLFSR {
public:
    FibLFSR(string seed);
    int step();
    int generate(int k);
    ~FibLFSR();
    friend ostream& operator<< (ostream &out, const FibLFSR &fibLfsr);
private:
    string seed;
};


#endif