#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5 #endif

typedef struct type_queue{
    char queue[MAXSIZE];
    int counter;
} type_queue;

//Queue functions
void insertIntoQueue(type_queue *, char);
char removeFromQueue(type_queue *);
void showQueue(type_queue);

int main(){
    type_queue myQueue;
    myQueue.counter = 0;

    //Get chars
    char newChars[MAXSIZE], newChar;
    scanf("%c %c %c %c %c", &newChars[0], &newChars[1], &newChars[2], &newChars[3], &newChars[4]);
    return 0;
}

void insertIntoQueue(type_queue* myQueue, char newChar){
    myQueue->queue[(myQueue->counter)++];
}

char removeFromQueue(type_queue* myQueue){
    myQueue->counter --;
    //Not empty queue 
    if (myQueue->counter > 0) {
        //Save data to be returned
        char dataToReturn = myQueue->queue[0];
        //Realocate data
        for (int i = 0; i < myQueue->counter; i++) {
            myQueue->queue[i] = myQueue->queue[i + 1];
        }
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
        printf("[%c", myQueue.queue[0]);
        for (int i = 1; i < myQueue.counter; i++) {
            printf(", %c", myQueue.queue[i]);
        }
        printf("]\n");
    }
    else {
        printf("Empty queue\n");
    }
}