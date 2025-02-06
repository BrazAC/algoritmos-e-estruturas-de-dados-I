#ifndef __STACK_FUNCTIONS__
#define __STACK_FUNCTIONS__

#define MAXSIZE 10

typedef struct type_stack{
    int stack[MAXSIZE];
    int counter;
} type_stack;

void insertIntoStack(type_stack*, int);
int removeFromStack(type_stack*);
void showStackTop(type_stack);
void showStack(type_stack);

#endif //__STACK_FUNCTIONS__