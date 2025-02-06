//[' ', ' ', ' ', ' ', ' ', '\n', '\n', '\n', '4', '5', ' ', ' ', ' ', '\n']
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

typedef struct type_stack{
    char stack[MAXSIZE];
    int counter;
} type_stack;

//Stack functions
void insertIntoStack(type_stack*, char);
char removeFromStack(type_stack*);
void showStackTop(type_stack);
void showStack(type_stack);

int main(){
    type_stack myStack;
    myStack.counter = 0;

    //Get chars
    char newChars[MAXSIZE], newChar;
    scanf("%c %c %c %c %c", &newChars[0], &newChars[1], &newChars[2], &newChars[3], &newChars[4]);

    //Fill up stack
    for (int i = 0; i < MAXSIZE; i++) {
        newChar = newChars[i];
        insertIntoStack(&myStack, newChar);
    }
    //Remove from stack
    removeFromStack(&myStack);
    removeFromStack(&myStack);
    removeFromStack(&myStack);
    removeFromStack(&myStack);
    removeFromStack(&myStack);
    removeFromStack(&myStack);
    //Show all stack 
    showStack(myStack);
    //Show top of stack
    showStackTop(myStack);

    return 0;
}

//Stack functions
void insertIntoStack(type_stack * myStack, char newChar){
    myStack->stack[(myStack->counter)++] = newChar;
}

char removeFromStack(type_stack * myStack){
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
        printf("At the top: %c\n", myStack.stack[myStack.counter - 1]);
    }
    else {
        printf("Empty stack\n");
    }
    
}

void showStack(type_stack myStack){
    if (myStack.counter > 0) {
        printf("[%c", myStack.stack[0]);
        for (int i = 1; i < myStack.counter; i++) {
            printf(", %c", myStack.stack[i]);
        }
        printf("]\n");
    }
    else {
        printf("Empty stack\n");
    }
}