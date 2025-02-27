#ifndef __FUNCOES_FILADINDUPLA__
#define __FUNCOES_FILADINDUPLA__

typedef struct tipo_no{
    int dado;
    struct tipo_no *prox;
    struct tipo_no *ant;
} tipo_no;

//Inserir
tipo_no* alocaNo(int);
int listaDinDupla_insereInicio(tipo_no**, int);
int listaDinDupla_inserePos(tipo_no**, int, int);

//Visualizar
int listaDinDupla_mostrar(tipo_no**);


#endif