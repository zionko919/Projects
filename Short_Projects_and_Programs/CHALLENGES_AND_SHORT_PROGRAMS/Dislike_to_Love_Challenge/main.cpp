/*********************************************************
 Purpose: <To get familiar with basics of C++: File I/O>
 
  A program that takes a text file, called “input.txt” 
  containing the text “I dislike C++ and dislike 
  programming!”. Then the program reads in the text 
  from the file and outputs each word to the console but 
  replaces any occurrence of “dislike” with “love.”
 ********************************************************/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* const argv[])
{
    string someText;

    // declaring an input stream variable
    ifstream inFile;

    // Connecting input stream variable to a text file
    inFile.open("input.txt");

    // Checking to see if the text file is valid.
    if (!inFile.is_open()) {
       cout << "Error! I cannot open file" << endl;
       exit(1);
    }

    // while loop to read every line of data.
    // If the word "dislike" are stored in the someText variable, replace it with "love."
    while (inFile >> someText) {
        if (someText == "dislike") {
            someText = "love";
        }
        // outputs each word to the console.
        // The instruction was not clear about the output format, so I just put newline on each word.
        cout << someText << endl;
    }

    // closing the file to release any resources that have been allocated in association with the file
    inFile.close();

    return 0;
}
