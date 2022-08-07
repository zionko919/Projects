/***********************************************
Purpose: To learn about priority queue in C
and implement it using heaps.
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{

    PRIORITY_QUEUE  hP_q = NULL;
    hP_q = priority_queue_init_default();

    if(hP_q == NULL) {
        printf("failed to allocate the space for the PRIORITY_QUEUE.\n");
        exit(1);
    }

//    priority_queue_insert(hP_q, 21, 10);
//    priority_queue_insert(hP_q, 35, 5);
//    priority_queue_service(hP_q);
//    printf("%d\n", priority_queue_front(hP_q, NULL));   // should print out 5

    int i;  // priority level
    int k = 1;  // value
    //inserting 1 ~ 100;
    for (i = 100; i >= 1; i--) {
        priority_queue_insert(hP_q, i, k++);
    }
    printf("%d\n", priority_queue_front(hP_q, NULL));   // should print out 1 with priority_level 100;

    //servicing 1 ~ 50;
    for (i = 0; i < 50; i++) {
        priority_queue_service(hP_q);
    }
    printf("%d\n", priority_queue_front(hP_q, NULL));   // should print out 51

    priority_queue_insert(hP_q, 599, 777);
    printf("%d\n", priority_queue_front(hP_q, NULL)); // should print out 777;

    int count = 0;
    for(i = 100; i < 1000; i++) {
        priority_queue_insert(hP_q, i, rand());
        if (priority_queue_front(hP_q, NULL) == 777) {
            count += 1;
        }
    }
    printf("777 printed out %d times\n", count);

    priority_queue_destroy(&hP_q);
    return 0;
}