/*
UFMT - Araguaia
Aluno: Braz Amorim Campos
Professor: Ivairton Santos
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue_functions.h"
#include "stack_functions.h"

int main(){
    type_queue myQueue;
    myQueue.counter = 0;    

    type_stack myStack;
    myStack.counter = 0;

    //Get numbers
    char newChars[MAXSIZE];
    scanf("%c %c %c %c %c", &newChars[0], &newChars[1], &newChars[2], &newChars[3], &newChars[4]);
    
    //Insert numbers in queue
    for (int i = 0; i < MAXSIZE; i++){
        insertIntoQueue(&myQueue, newChars[i]);
    }
  
    //Queue -> Stack
    char movedChar;
    for (int i = 0; i < MAXSIZE; i++){
        movedChar = removeFromQueue(&myQueue);
        insertIntoStack(&myStack, movedChar);
    }

    //Stack -> inverse order -> terminal
    char removedChar;
    for (int i = 0; i < MAXSIZE; i++){
        removedChar = removeFromStack(&myStack);
        printf("%c\n", removedChar);
    }

    return 0;
}