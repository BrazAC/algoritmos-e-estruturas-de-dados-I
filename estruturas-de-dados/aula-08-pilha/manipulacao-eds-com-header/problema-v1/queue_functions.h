//Definicao de estruturas, prototipagem de funcoes, constantes, enumerates....

#ifndef __QUEUE_FUNCTIONS_H__
#define __QUEUE_FUNCTIONS_H__

#define MAXSIZE 5

//Queue data structure definition
struct type_queue{
    char queue[MAXSIZE];
    int counter;
};

typedef type_queue type_queue;

//Functions proto
void insertIntoQueue(type_queue *, char);
char removeFromQueue(type_queue *);
void showQueue(type_queue);

#endif //__QUEUE_FUNCTIONS_H__