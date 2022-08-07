/***********************************************
    Self Learning C - Basic 27

 	This program will simulate ToxicCo's
 	controller program that maintains temperature 
 	and voltage at safe levels.
 ***********************************************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int count = 1;
	int lower_bound_safe; // unsafe = 0(false), safe = 1(true)
	int higher_bound_safe; // unsafe = 0(false), safe = 1(true)
	int numOfDataSets;
	float a_firstLow; float b_firstLow; float c_firstLow;
	float a_secondLow; float b_secondLow; float c_secondLow;
	float a_firstHigh; float b_firstHigh; float c_firstHigh;
	float a_secondHigh; float b_secondHigh; float c_secondHigh;
	float t; float v;
	scanf("%d", &numOfDataSets);
	// while loop is contiuned untill the count reaches the equal  number of data sets
	while(count <= numOfDataSets){
		scanf("%f %f %f", &a_firstLow, &b_firstLow, &c_firstLow);
		scanf("%f %f %f", &a_secondLow, &b_secondLow, &c_secondLow);
		scanf("%f %f %f", &a_firstHigh, &b_firstHigh, &c_firstHigh);
		scanf("%f %f %f", &a_secondHigh, &b_secondHigh, &c_secondHigh);
		scanf("%f %f", &t, &v);
		printf("\n");

		// lower bound comparision
		if((a_firstLow * t + b_firstLow * v >= c_firstLow) && (a_secondLow * t + b_secondLow * v >= c_secondLow)){
			lower_bound_safe = 1;
		}
		else{
			lower_bound_safe = 0;
		}

		// higher bound comparison
		if((a_firstHigh * t + b_firstHigh * v <= c_firstHigh) && (a_secondHigh * t + b_secondHigh * v <= c_secondHigh)){
			higher_bound_safe = 1;
		}
		else{
			higher_bound_safe = 0;
		}

		// Both lower and higher bounds has to be safe. 
		// if else statement below checks to see if both lower and higher bounds are safe
		if((lower_bound_safe == 1) && (higher_bound_safe == 1)){
			printf("%d SAFE\n", count);
		}
		else{
			printf("%d UNSAFE\n", count);
		}
		count += 1;
	}
	return 0;
}
	
