//Implementação das funcoes
#include "queue_functions.h"
#include <stdio.h>
#include <stdlib.h>

void insertIntoQueue(type_queue* myQueue, int newInt){
    myQueue->queue[(myQueue->counter)++] = newInt;
}

int removeFromQueue(type_queue* myQueue){
    //Not empty queue 
    if (myQueue->counter > 0) {
        //Save data to be returned
        int dataToReturn = myQueue->queue[0];
        //Realocate data
        for (int i = 0; i < myQueue->counter; i++) {
            myQueue->queue[i] = myQueue->queue[i + 1];
        }

        myQueue->counter --;

        //Return data
        return dataToReturn;
    }
    //Empty queue
    else{
        printf("[ERROR] Cannot remove from empty queue\n");
    }
}

void showQueue(type_queue myQueue){
    if (myQueue.counter > 0) {
        printf("[%d", myQueue.queue[0]);
        for (int i = 1; i < myQueue.counter; i++) {
            printf(", %d", myQueue.queue[i]);
        }
        printf("]\n");
    }
    else {
        printf("Empty queue\n");
    }
}