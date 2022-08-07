#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;
   // use appropriate location
   // example: /Users/Zion_Ko/Documents/input.txt";
   fptr = fopen("/Users/Zion_Ko/Documents/input.txt","w");
   if(fptr == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   int i;
   int random;

   printf("How many random numbers do you need?: ");
   scanf("%d", &num);

   for (i = 0; i < num/2; i++) {
      random = rand(); 
      fprintf(fptr, "%d\n", random);
      fprintf(fptr, "%d\n", random);
   }
   fprintf(fptr, "-1");

   fclose(fptr);
   return 0;
}