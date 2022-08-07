/***********************************************
Purpose: To learn about priority queue in C
and implement it using heaps.
***********************************************/
#include <stdlib.h>
#include <stdio.h>
#include "priority_queue.h"

struct pair_nums {
    int priority_level;
    int value;

}; typedef struct pair_nums Pair_nums;

struct priority_queue {
    int size;
    int capacity;
    Pair_nums* data;
    int front;
    int back;
}; typedef struct priority_queue Priority_queue;

PRIORITY_QUEUE priority_queue_init_default(void)
{
    Priority_queue* pP_q;
    pP_q = (Priority_queue*)malloc(sizeof(Priority_queue));
    if (pP_q != NULL) {
        pP_q->size = 0;
        pP_q->capacity = 4;
        pP_q->front = 0;
        pP_q->back = 0;
        pP_q->data = (Pair_nums*)malloc(sizeof(Pair_nums) * pP_q->capacity);
        if (pP_q->data == NULL) {
            free(pP_q);
            pP_q = NULL;
        }
    }
    return pP_q;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
    Priority_queue* pP_q = (Priority_queue*)hQueue;
    Pair_nums* temp1, temp2;
    int i;
    if (pP_q->size >= pP_q->capacity) {
        temp1 = (Pair_nums*)malloc(sizeof(Pair_nums) * 2 * pP_q->capacity);
        if (temp1 == NULL) {
            return FAILURE;
        }
        for (i = 0; i < pP_q->size; i++) {
            temp1[i] = pP_q->data[i];
        }
        pP_q->capacity *= 2;
        free(pP_q->data);
        pP_q->data = temp1;
    }
    i = pP_q->size;
    (pP_q->data[i]).priority_level = priority_level;
    (pP_q->data[i]).value = data_item;
    int index_parent;
    index_parent = (i - 1) / 2;
    while (i >= 1 && ((pP_q->data[i]).priority_level > (pP_q->data[index_parent]).priority_level)) {
        temp2 = pP_q->data[index_parent];
        pP_q->data[index_parent] = pP_q->data[i];
        pP_q->data[i] = temp2;
        i = index_parent;
        index_parent = (i - 1) / 2;
    }
    pP_q->size++;
    pP_q->front = 0;
    pP_q->back = pP_q->size - 1;

    return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
    Priority_queue* pP_q = (Priority_queue*)hQueue;
    if (priority_queue_is_empty(pP_q)) {
        printf("Queue is empty! I cannot service.\n");
        return FAILURE;
    }
    Pair_nums temp; 
    temp = pP_q->data[pP_q->front];
    if(pP_q->back == pP_q->front) {
        pP_q->size--;
    } else {
        pP_q->front = (pP_q->front + 1) % pP_q->capacity;
    }
    return SUCCESS;
}

// Status priority_queue_service(PRIORITY_QUEUE hQueue)
// {
//     Priority_queue* pP_q = (Priority_queue*)hQueue;
//     Pair_nums* temp1;
//     Pair_nums* temp2;
//     int i;
//     temp1 = (Pair_nums*)malloc(sizeof(Pair_nums));
//     temp2 = (Pair_nums*)malloc(sizeof(Pair_nums));
//     if (priority_queue_is_empty(pP_q)) {
//         printf("The queue is empty! I CANNOT SERVICE!\n");
//         return FAILURE;
//     }
//     *temp1 = pP_q->data[0];
//     pP_q->data[0] = pP_q->data[pP_q->back];
//     pP_q->data[pP_q->back] = *temp1;
//     pP_q->size--;
//     i = 0;
//     int indicator = 1;
//     int index_left_child = (2 * i) + 1;
//     int index_right_child = (2 * i) + 2;
//     while (index_left_child < pP_q->size && indicator == 1) {
//         indicator = 0;
//         if (index_right_child < pP_q->size &&
//             ((pP_q->data[index_right_child]).priority_level > (pP_q->data[index_left_child]).priority_level)) {
//             if ((pP_q->data[index_right_child]).priority_level > (pP_q->data[i]).priority_level) {
//                 *temp2 = pP_q->data[i];
//                 pP_q->data[i] = pP_q->data[index_right_child];
//                 pP_q->data[index_right_child] = *temp2;
//                 i = index_right_child;
//                 index_left_child = (2 * i) + 1;
//                 index_right_child = (2 * i) + 2;
//                 indicator = 1;
//             }
//         }   else {
//                 if ((pP_q->data[index_left_child]).priority_level > (pP_q->data[i]).priority_level) {
//                     *temp2 = pP_q->data[i];
//                     pP_q->data[i] = pP_q->data[index_left_child];
//                     pP_q->data[index_left_child] = *temp2;
//                     i = index_left_child;
//                     index_left_child = (2 * i) + 1;
//                     index_right_child = (2 * i) + 2;
//                     indicator = 1;
//                 }
//             }
//         }
//     pP_q->back = pP_q->size - 1;
//     return SUCCESS;
// }

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
    Priority_queue* pP_q = (Priority_queue*)hQueue;
    if (priority_queue_is_empty(pP_q)) {
        if (pStatus != NULL) {
            *pStatus = FAILURE;
        }
        return -777;
    }
    if(pStatus != NULL) {
        *pStatus = SUCCESS;
    }
    return (pP_q->data[pP_q->front]).value;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
    Priority_queue* pP_q = (Priority_queue*)hQueue;
    return (Boolean)(pP_q->size == 0);
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
    Priority_queue* pP_q = (Priority_queue*)*phQueue;
    free(pP_q->data);
    free(pP_q);
    *phQueue = NULL;
}
