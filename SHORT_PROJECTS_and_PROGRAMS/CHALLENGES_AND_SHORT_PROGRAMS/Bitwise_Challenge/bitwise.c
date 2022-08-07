/***********************************************************
Purpose: <To practice bitwise operators and shifts>
************************************************************/

#include <stdio.h>

void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);


int main(int argc, char* argv[])
{
   int flag_holder = 0;
   int i;

   set_flag(&flag_holder, 3);
   set_flag(&flag_holder, 16);
   set_flag(&flag_holder, 31);

   for(i=31; i>=0; i--)
   {
       printf("%d", check_flag(flag_holder, i));
       if(i%4 == 0)
       {
           printf(" ");
       }
   }
   printf("\n");
   return 0;
}


void set_flag(int* flag_holder, int flag_position)
{
   int temp_1 = 0;
   temp_1 = (1|temp_1);     // 1 or 0, this would always give out 1.
   temp_1 = temp_1<<flag_position;  // left shifts by the value of the flag_position
   *flag_holder = temp_1|*flag_holder;  /* temp_1(left shifted value) or flag_holder(0)
                                        this would store temp_1 value into *flag_holder */
}

int check_flag(int flag_holder, int flag_position)
{
   int temp_2;
   flag_holder = flag_holder >> flag_position;  // right shifts flag_holder by the value of flag_postion
   if(flag_holder%2==0) {
       temp_2 = 0;
   }
   else temp_2 = 1;     // if-else is checking to flag_holder value is 0 or 1
   return temp_2;
}