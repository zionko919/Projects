/*********************************************************
 Challenge:
 You have collected a file of movie ratings where each 
 movie is rated from 1 (bad) to 5 (excellent). The first 
 line of the file is a number that identifies how many 
 ratings are in the file. Each rating then consists of two 
 lines: the name of the movie followed by the numeric 
 rating from 1 to 5. 

 Write a program that reads in a file in this format, 
 calculates the average rating for each movie, and outputs 
 the average along with the number of reviews.
 ********************************************************/


#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <fstream>

using namespace std;
using std::map;
using std::pair;

int main (int argc, char* const argv[])
{
    // open the file
    ifstream inFile;
    inFile.open("/Users/zionko/movie_rating.txt");
    // If the program cannot open the file....exit out.
    if (inFile.fail()) {
        cout << "Error! Input file opening failed!" << endl;
        exit(1);
    }

    map <string, int> movieNumMap;
    map <string, double> movieRatingMap;
    map <string, double> avgRatingMap;
    int totalReviews;
    int rating;
    string title;
    // getting the number of total movie reviews on the first line
    inFile >> totalReviews;
//    cout << totalReviews << endl;
    inFile.ignore();

    // loop to store data into maps
    for (int i = 0; i < totalReviews; i++) {
        getline(inFile, title); // gets the title from .txt file
        inFile >> rating;   // get the rating from .txt file
        inFile.ignore();
//        cout << rating << endl;
//        movieRatingMap[title] = 0;
        movieRatingMap[title] += rating; // adds the total movie ratings into the map
        movieNumMap[title] += 1;    // adds how many reviews are made for that movie into the map
        avgRatingMap[title] = movieRatingMap[title]/movieNumMap[title]; // adds the average rating to the map
    }

    map <string, int>:: iterator iterMovieNumMap;
    map <string, double>:: iterator iterMovieRatingMap;
    map <string, double>:: iterator iterAvgRatingMap;
    // outputs the final result...
    for (iterMovieNumMap = movieNumMap.begin(); iterMovieNumMap != movieNumMap.end(); iterMovieNumMap++){
        for (iterAvgRatingMap = avgRatingMap.begin(); iterAvgRatingMap != avgRatingMap.end(); iterAvgRatingMap++) {
            cout << fixed << setprecision(1);
            cout << iterAvgRatingMap->first << ": " << iterMovieNumMap->second << " reviews, average of " <<
                 iterAvgRatingMap->second << " / 5" << endl;
            iterMovieNumMap++;
        }
        break;
    }

    // close the .txt file
    inFile.close();

    return 0;
}