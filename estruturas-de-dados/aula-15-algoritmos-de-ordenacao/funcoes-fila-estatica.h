#ifndef __FUNCOES_FILA_ESTATICA_H__
#define __FUNCOES_FILA_ESTATICA_H__

#define MAX_SIZE 10

typedef struct est_listaEstatica{
    int vetInt[MAX_SIZE];
    int cont;
} est_listaEstatica;

int insere_comecolistaEstatica(est_listaEstatica*, int);
int mostra_listaEstatica(est_listaEstatica*);

//==METODOS DE ORDENACAO
//BUBBLE SORT - O pior de todos
int ordenaBubble_listaEstatica(est_listaEstatica*);

//SHELL SORT - Mesma coisa que bubble, mas com uma etapa de preparação
//Faz comparacoes não com o proximo, mas com o elemento após um salto, e decrementa o salto
//Salto = tamanhoTotal // 2
int ordenaShell_listaEstatica(est_listaEstatica*);

//INSERT SORT - Antes de inserir, analisar a posicao correta
//Da pra fazer com um vetor auxiliar, ou sem
int ordenaInsert_listaEstatica(est_listaEstatica*);

#endif