/***********************************************
Self Learning C - Basic 15

This program merges the numbers in two
files. The program reads input from two different
files, and writes the output to a third file.
***********************************************/

#include <stdio.h>
#include <stdlib.h>

FILE * fp1;
FILE * fp2;
FILE * fp3;

int main(int argc, char* argv[])
{
    int file1_placeholder;
    int file2_placeholder;
    int status1;
    int status2;

    fp1 = fopen("numbers1.txt", "r");
    fp2 = fopen("numbers2.txt", "r");
    fp3 = fopen("output.txt", "w");

    if(fp1 == NULL)
    {
        printf("Error: %s was not found", fp1);
        exit(1);
    }

    if(fp2 == NULL)
    {
        printf("Error: %s was not found", fp2);
        exit(1);
    }

    status1 = fscanf(fp1, "%d", &file1_placeholder);
    status2 = fscanf(fp2, "%d", &file2_placeholder);

    while (status1 == 1 && status2 == 1){

        if (file1_placeholder < file2_placeholder){
            fprintf(fp3, "%d\n", file1_placeholder);
            status1 = fscanf(fp1, "%d", &file1_placeholder);
        }
        else {
            fprintf(fp3, "%d\n", file2_placeholder);
            status2 = fscanf(fp2, "%d", &file2_placeholder);
        }
    }

    while (status1 == 1){
        fprintf(fp3, "%d\n", file1_placeholder);
        status1 = fscanf(fp1, "%d", &file1_placeholder);
    }

    while(status2 == 1){
        fprintf(fp3, "%d\n", file2_placeholder);
        status2 = fscanf(fp2, "%d", &file2_placeholder);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}