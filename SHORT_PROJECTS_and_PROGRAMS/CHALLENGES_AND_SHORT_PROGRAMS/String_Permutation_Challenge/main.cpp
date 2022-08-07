/**********************************************************************************************
 **********************************************************************************************/


#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

list<string> generate_permutations(list<string> aInputList);
void print_permutations(list<string> aList);

int main(int argc, char *const argv[])
{
    list<string> inputList;
    string aLine, aString;

    // read in strings from stdin
    cout << "Enter strings, separated by a space: ";
    getline(cin, aLine);    // read a line from keyboard
    istringstream iss(aLine);   // convert aLine to an istringstream obj

    // parse each string
    while(iss >> aString) {
        inputList.push_back(aString);
    }

    auto permutations = generate_permutations(inputList);

    // print permutations to stdout
    print_permutations(permutations);

    return 0;
}

/************************************************************************************
My approach:
 step 1. Sort the list
 step 2. Remove duplicates in the list. (Extra Credit)
 step 3. Generate all permutations with looping.
 step 4. Store those permutations into a string list.
 step 5. Print all elements in the list.
************************************************************************************/
list<string> generate_permutations(list<string> aInputList)
{
    // step 1.
    aInputList.sort();  // sort the list: http://www.cplusplus.com/reference/list/list/sort/

    // step 2.
    aInputList.unique(); // Removes duplicates: http://www.cplusplus.com/reference/list/list/unique/

    // step 3.
    list<string> aPermList; // Creating a  new list object to store all permutations.
    string permString; // Initializing an array for permutations.
    list<string>::iterator b, e;
    b = aInputList.begin();
    e = aInputList.end();
    do {
        permString = "";
        for (auto i = b; i != e; i++) {
            permString += *i + " ";
        }
        aPermList.push_back(permString);    // <-step 4.
    } while (next_permutation(b, e)); /* http://www.cplusplus.com/reference/algorithm/next_permutation/
                                       * next_permutation: This will rearrange(permutation) the elements in the list.*/

    return aPermList;   // returns a list with all permutations
}

void print_permutations(list<string> aList)
{
    list<string>::iterator b, e;
    b = aList.begin();
    e = aList.end();
    int i = 1;
    // numbers and prints out all permutations on the screen.
    cout << "Permutations are: " << endl;
    for (auto j = b; j != e; i++, j++) {
        cout << i << ". " << *j << endl;
    }
}