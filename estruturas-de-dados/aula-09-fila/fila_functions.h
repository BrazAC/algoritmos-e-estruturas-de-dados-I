#ifndef __FILA_FUNCTIONS_H__
#define __FILA_FUNCTIONS_H__

#define TAMMAX 5

typedef struct tipo_fila{
    int filaInts[5];
    int contador;
} tipo_fila;


void fila_insereInicio(tipo_fila*, int);
void fila_insereFinal(tipo_fila*, int);
void fila_inserePosEspecifico(tipo_fila*, int, int);
void fila_mostrar(tipo_fila);
int fila_removeInicio(tipo_fila*);
int fila_removeFim(tipo_fila*);
int fila_removePosEspecifica(tipo_fila*, int);
int fila_removeValEspecifico(tipo_fila*, int);
int fila_ordenar(tipo_fila*);

#endif