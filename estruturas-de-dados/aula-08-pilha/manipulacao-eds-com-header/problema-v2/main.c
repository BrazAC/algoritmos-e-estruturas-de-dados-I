/*
UFMT - Araguaia
Aluno: Braz Amorim Campos
Professor: Ivairton Santos
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue_functions.h"
#include "stack_functions.h"

int main(int argc, char* argv[]){
    type_queue myQueue;
    myQueue.counter = 0;    

    type_stack myStack;
    myStack.counter = 0;

    //Get numbers from file
    //open FILE read mode
    FILE* originFile = fopen(argv[1], "r");
    
    //Insert numbers in queue 
    //read FILE line-per-line, store in queue
    int number;
    while(fscanf(originFile, "%d", &number) != -1){
        insertIntoQueue(&myQueue, number);
    }


    //Queue -> Stack
    char movedChar;
    for (int i = 0; i < MAXSIZE; i++){
        movedChar = removeFromQueue(&myQueue);
        insertIntoStack(&myStack, movedChar);
    }

    //Stack -> inverse order -> file
    //edit/create output file
    FILE* outputFile = fopen(argv[2], "w");
    //fill output file
    int removedInt;
    for (int i = 0; i < MAXSIZE; i++){
        removedInt = removeFromStack(&myStack);
        //TODO: Insert removedInt in FILE line-by-line
        //use fprints
        fprintf(outputFile, "%d\n", removedInt);
    }

    //TODO: Close FILE

    return 0;
}