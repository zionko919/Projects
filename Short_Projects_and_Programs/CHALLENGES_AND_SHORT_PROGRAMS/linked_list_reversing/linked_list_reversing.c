/**********************************************************************
Reversing Linked List in C
Purpose: Reversing a linked data structure.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};


void reverse_list(Node* *head);
//declare your function here.


int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;

    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
        temp = (Node*)malloc(sizeof(Node));
        if (temp == NULL)
        {
            printf("out of memory?\n");
            exit(1);
        }
        temp->data = i;
        temp->next = head;
        head = temp;
    }

    reverse_list(&head);


    //print the reversed list.
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }


    Node* free_temp = head->next;
    while(free_temp != NULL){
        free_temp = head->next;
        free(head);
        head = free_temp;
    }


    return 0;
}

void reverse_list(Node* *tire_tread){
    Node* head = *tire_tread;
    Node* temp = head->next;
    head->next = NULL;
    Node* chemp;
    while (temp != NULL)
    {
        chemp = temp->next;
        temp->next = head;
        head = temp;
        temp = chemp;
    }
    *tire_tread = head;
}
