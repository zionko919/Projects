/**************************************************************
    Self Learning C - Basic 26

    This program computes average grades for a course
    from input files and outputs it into a new file.
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaring functions
void readFileInput(FILE *input, char firstName[], char lastName[], int scores[]);
void writeFileOutput(FILE *output, char firstName[], char lastName[], int scores[]);

// main function
int main(int argc, char const *argv[])
{
    // file pointers
    FILE *fp_in;
    FILE *fp_out;

    //Open files: input in read mode, output in write mode
    fp_in = fopen("quiz.txt", "r");
    fp_out = fopen("average.txt", "w");

    //declaring variables
    char firstName[20], lastName[20];
    int noc;
    char name;
    int quiz[10];

    //Checks to see if the file opens or not
    if (fp_in == NULL)
    {
        printf("Error: Unable to open the file.\n");
        exit(1);
    }

    //function calls
    while (!feof(fp_in)) {
        readFileInput(fp_in, firstName, lastName, quiz);
        writeFileOutput(fp_out, firstName, lastName, quiz);
    }

    //Always Close both the files
    fclose(fp_in);
    fclose(fp_out);

    return 0;
}

//definition of the function readFile() - reads the data from the input file
void readFileInput(FILE *input, char firstName[], char lastName[], int scores[])
{
    int i;
    //Initializes the quiz scores to zero
    for (i = 0; i < 10; i++)
        scores[i] = 0;
    //Read the first name then last name
    fscanf(input, "%s %s", firstName, lastName);

    //Read the 10 Quiz scores
    for (i = 0; i < 10; i++)
        fscanf(input, "%d", &scores[i]);
}

//definition of the function writeFile() - ti write the data into the output file
void writeFileOutput(FILE *output, char firstName[], char lastName[], int scores[])
{
    int i;
    int sum = 0;
    double average;
    int len1;
    int len2;
    int j = 0;
    int k = 0;
    char name[20];

    len1 = strlen(lastName);
    // lastName to name array for the full name
    for (j = 0; j < len1; ++j)
    {
        name[j] = lastName[j];
    }
    name[j] = ',';	//adding a comma
    j += 1;
    name[j] = ' ';	//adding a space
    j += 1;

    len2 = strlen(firstName);
    //append the firstName 
    for (k = 0; k < len2; ++k, ++j) {
        name[j] = firstName[k];
    }
    name[j] = '\0';     //assign the last character of name is null


    //Writes Last name then first name with specified size and alignment
    fprintf(output, "%-20s", name);

    //Writes the 10 quiz scores 
    for (i = 0; i < 10; i++) {
        fprintf(output, "%4d", scores[i]);
        sum += scores[i];
    }
    average = (double)sum / 10;
    fprintf(output, "%10.2f", average);
    fprintf(output, "\n");
}


