/***********************************************
Purpose: To learn about stack in C and us stack
 data structures to solve problems.
***********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_stack.h"


struct stack
{
    int size;
    int capacity;
    char* data;
};
typedef struct stack Stack;

STACK stack_init_default(void)
{
    Stack* pStack;
    pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack != NULL){
        pStack->size = 0;
        pStack->capacity = 8;
        pStack->data = (char*)malloc(sizeof(char) * pStack->capacity);
        if (pStack->data == NULL){
            free(pStack);
            return NULL;
        }
    }
    return pStack;
}

Status stack_push(STACK hStack, char value)
{
    Stack* pStack = (Stack*)hStack;
    char* temp;
    int i;

    //if there is not room then make room
    if(pStack->size >= pStack->capacity){
        temp = (char*)malloc(sizeof(char) * pStack->capacity * 2);
        if(temp == NULL){
            return FAILURE;
        }
        for(i = 0; i < pStack->size; i++){
            temp[i] = pStack->data[i];
        }
        free(pStack->data);
        pStack->data = temp;
        pStack->capacity *= 2;
    }
    pStack->data[pStack->size] = value;
    pStack->size++;
    return SUCCESS;
}

Status stack_pop(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;

    if(pStack->size <= 0){
        return FAILURE;
    }
    pStack->size--;
    return SUCCESS;
}

char stack_top(STACK hStack, Status* pStatus) // Tells two things: 1. what's at the top. 2. Did it work or not?
{
    Stack* pStack = (Stack*)hStack;

    if(!stack_empty(hStack)){
        if(pStatus != NULL){
            *pStatus = SUCCESS;
        }
        return pStack->data[pStack->size - 1];
    }
    else{
        if(pStatus != NULL){
            *pStatus = FAILURE;
        }
        return 'F';
    }
}

Boolean stack_empty(STACK hStack)
{
    Stack* pStack = (Stack*)hStack;
    if(pStack->size <= 0){
        return TRUE;
    }
    return FALSE;
}

Boolean stack_char_checker(STACK hStack, char input[]) {
    Stack *pStack = (Stack *) hStack;
    int i;
    if (pStack == NULL) {
        printf("Failed to allocate space for stack object!\n");
        exit(1);
    }
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '[' || input[i] == '{' || input[i] == '(') {
            stack_push(pStack, input[i]);
//            printf("%d : %c\n", i, input[i]);
        }
        if (input[i] == ']') {
            if (stack_top(pStack, NULL) == '[') {
                stack_pop(pStack);
//                printf("%d : %c\n", i, input[i]);
            } else {
                printf("No\n");
//                printf("%d : %c\n", i, input[i]);
                return FALSE;
            }
        }
        if (input[i] == '}') {
            if (stack_top(pStack, NULL) == '{') {
                stack_pop(pStack);
//                printf("%d : %c\n", i, input[i]);
            } else {
                printf("No\n");
//                printf("%d : %c\n", i, input[i]);
                return FALSE;
            }
        }
        if (input[i] == ')') {
            if (stack_top(pStack, NULL) == '(') {
                stack_pop(pStack);
//                printf("%d : %c\n", i, input[i]);
            } else {
                printf("No\n");
//                printf("%d : %c\n", i, input[i]);
                return FALSE;
            }
        }
    }
    if (stack_empty(pStack) == TRUE) {
        printf("Yes\n");
        return TRUE;
    } else if (stack_empty(pStack) == FALSE) {
        while (stack_empty(pStack) != TRUE) {
            stack_pop(pStack);
        }
        printf("No\n");
        return FALSE;
    }
    return FALSE;
}

void stack_destroy(STACK* phStack)
{
    Stack* pStack = (Stack*) *phStack;
    free(pStack->data);
    free(pStack);
    *phStack = NULL;
}

void clear_keyboard_buffer(void)
{
    char c;
    do{
        scanf("%c", &c);
    }while(c != '\n');
}