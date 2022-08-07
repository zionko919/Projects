/***********************************************
Purpose: To learn about stack in C and us stack
 data structures to solve problems.
***********************************************/
#ifndef MY_STACK_H
#define MY_STACK_H

#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);

Status stack_push(STACK hStack, char value);

Status stack_pop(STACK hStack);

char stack_top(STACK hStack, Status* pStatus);

Boolean stack_empty(STACK hStack);

void stack_destroy(STACK* phStack);

Boolean stack_char_checker(STACK hStack, char input[]);

void clear_keyboard_buffer(void);

#endif
