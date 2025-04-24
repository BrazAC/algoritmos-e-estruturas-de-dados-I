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
int listaDinDupla_insereFim(tipo_no**, int);
int listaDinDupla_inserePos(tipo_no**, int, int);

//Remover
int listaDinDupla_removeInicio(tipo_no**);
int listaDinDupla_removeFinal(tipo_no**);
int listaDinDupla_removePos(tipo_no**, int);
int listaDinDupla_removeValor(tipo_no**, int);

//Buscar
tipo_no* listaDinDupla_buscaElemento(tipo_no**, int);

//Visualizar
int listaDinDupla_mostrar(tipo_no**);


#endif