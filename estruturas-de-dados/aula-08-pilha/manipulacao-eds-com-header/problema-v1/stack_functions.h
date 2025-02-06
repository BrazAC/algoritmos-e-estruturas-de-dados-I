#ifndef __STACK_FUNCTIONS__
#define __STACK_FUNCTIONS__

#define MAXSIZE 5

typedef struct type_stack{
    char stack[MAXSIZE];
    int counter;
} type_stack;

void insertIntoStack(type_stack*, char);
char removeFromStack(type_stack*);
void showStackTop(type_stack);
void showStack(type_stack);

#endif //__STACK_FUNCTIONS__