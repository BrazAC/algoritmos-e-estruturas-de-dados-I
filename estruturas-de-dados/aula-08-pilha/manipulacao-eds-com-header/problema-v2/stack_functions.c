#include "stack_functions.h"
#include <stdio.h>
#include <stdlib.h>

void insertIntoStack(type_stack * myStack, int newInt){
    myStack->stack[(myStack->counter)++] = newInt;
}

int removeFromStack(type_stack * myStack){
    //Return action status and removed data
    //Stack not empty
    if (myStack->counter > 0) {
        myStack->counter --;
        return myStack->stack[myStack->counter];
    }
    //Stack empty
    else {
        printf("[ERROR] Cannot remove from empty stack\n");
    }
}

void showStackTop(type_stack myStack){
    if (myStack.counter > 0) {
        printf("At the top: %d\n", myStack.stack[myStack.counter - 1]);
    }
    else {
        printf("Empty stack\n");
    }
    
}

void showStack(type_stack myStack){
    if (myStack.counter > 0) {
        printf("[%d", myStack.stack[0]);
        for (int i = 1; i < myStack.counter; i++) {
            printf(", %d", myStack.stack[i]);
        }
        printf("]\n");
    }
    else {
        printf("Empty stack\n");
    }
}