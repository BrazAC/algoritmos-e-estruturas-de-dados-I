//Definicao de estruturas, prototipagem de funcoes, constantes, enumerates....

#ifndef __QUEUE_FUNCTIONS_H__
#define __QUEUE_FUNCTIONS_H__

#define MAXSIZE 10

//Queue data structure definition
typedef struct type_queue{
    int queue[MAXSIZE];
    int counter;
} type_queue;

//Functions proto
void insertIntoQueue(type_queue *, int);
int removeFromQueue(type_queue *);
void showQueue(type_queue);

#endif //__QUEUE_FUNCTIONS_H__