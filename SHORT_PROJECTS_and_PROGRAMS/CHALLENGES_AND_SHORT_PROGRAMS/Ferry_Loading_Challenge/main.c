/**********************************************************************
    Ferry Loading - Challenege Question
    
    Purpose:
    To learn, use, and implement queue structure with linked-list
    
    There is an l-meter-long ferry that crosses the river. 
    A car may arrive at either river bank to be transported by the ferry
    to the opposite bank. The ferry travels continuously back and forth 
    between the banks so long as it is carrying a car or there is at 
    least one car waiting at either bank. Whenever the ferry arrives at 
    one of the banks, it unloads its cargo and loads up cars that are 
    waiting to cross as long as they fit on its deck. The cars are 
    loaded in the order of their arrival and the ferry's deck 
    accommodates only one lane of cars. The ferry is initially on the 
    left bank where it had mechanical problems and it took quite some 
    time to fix it. In the meantime, lines of cars formed on both banks 
    that wait to cross the river.
    The first line of input contains c, the number of test cases. 
    Each test case begins with the number l, a space and then the number 
    m. m lines follow describing the cars that arrive in this order to 
    be transported. Each line gives the length of a car (in centimeters), 
    and the bank at which the car awaits the ferry ("left" or "right").

***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct cars Cars;

struct cars {
    Cars* previous;
    Cars* next;
    int car_length;

};

void ferry(void);
void clear_keyboard_buffer(void);
void push_car(Cars** head_car, int car_centimeters);
int pop_car(Cars* left_car, Cars* right_car, int ferry_length);

int main (int argc, char* argv[])
{
    int count;
    scanf("%d", &count);
    int i;
    for (i = 0; i < count ;i++)
    {
        ferry();
    }
    return 0;
}

void ferry(void)
{
    int ferry_length;
    scanf("%d", &ferry_length);
    ferry_length *= 100;
    int number_of_vehicles;
    scanf("%d", &number_of_vehicles);
    int i;
    Cars* left_head_car = NULL;
    Cars* right_head_car = NULL;
    int car_centimeters;
    char location;
    for (i = 0; i < number_of_vehicles ;i++)
    {
        scanf("%d", &car_centimeters);
        scanf(" %c", &location);
        clear_keyboard_buffer();
        if(location == 'l')
        {
            push_car(&left_head_car, car_centimeters);
        }
        if(location == 'r')
        {
            push_car(&right_head_car, car_centimeters);
        }
    }
    int number_of_crossings = pop_car(left_head_car, right_head_car, ferry_length);
    printf("%d\n", number_of_crossings);

}

int pop_car(Cars* left_car, Cars* right_car, int ferry_length)
{
    Cars* left_head_car = left_car;
    Cars* right_head_car = right_car;
    int number = 0;
    int side = 0;
    while(1)
    {
        if(left_head_car == NULL && right_head_car == NULL)
        {
            break;
        }
        if(side == 0)
        {
            if(left_head_car != NULL){
                int i = 0;
                int size = 0;
                Cars* temp = left_head_car;
                while (size < ferry_length)
                {
                    size += temp->car_length;
                    if (size >= ferry_length)
                    {
                        size -= temp->car_length;
                        break;
                    }
                    i++;
                    Cars* new_variable = temp;
                    temp = temp->next;
                    free(new_variable);
                    if (temp == NULL)
                    {
                        break;
                    }
                }
                left_head_car = temp;
            }
            side = 1;
            number++;
        }
        if(left_head_car == NULL && right_head_car == NULL)
        {
            break;
        }
        if(side == 1)
        {
            if(right_head_car != NULL){
                int i = 0;
                int size = 0;
                Cars* temp = right_head_car;
                while (size < ferry_length)
                {
                    size += temp->car_length;
                    if (size >= ferry_length)
                    {
                        size -= temp->car_length;
                        break;
                    }
                    i++;
                    Cars* new_variable = temp;
                    temp = temp->next;
                    free(new_variable);
                    if (temp == NULL)
                    {
                        break;
                    }
                }
                right_head_car = temp;
            }
            side = 0;
            number++;
        }
        if(left_head_car == NULL && right_head_car == NULL)
        {
            break;
        }
    }
    return number;
}

void push_car(Cars** head_car, int car_centimeters)
{
    Cars* temp = malloc(sizeof(Cars));
    if(!temp)
    {
        printf("Queue Failed\n");
        exit(1);
    }
    temp->car_length = car_centimeters;
    temp->next = *head_car;
    *head_car = temp;
}

void clear_keyboard_buffer(void){
    char c;
    do {
        scanf("%c", &c);
    } while (c != '\n');
}