#ifndef __FILADIN_FUNCOES_H__
#define __FILADIN_FUNCOES_H__

typedef struct tipo_no{
    struct tipo_no *prox;
    int dado;
} tipo_no;

//Visualizacao
int filaDin_mostra(tipo_no*);

//Insercao
tipo_no* criaNo(int);
int filaDin_insereInicio(tipo_no**, int);
int filaDin_inserePos(tipo_no**, int, int);
int filaDin_insereFinal(tipo_no**, int);

//Remocao
int filaDin_removeInicio(tipo_no**);
int filaDin_removeFim(tipo_no**);
int filaDin_removePos(tipo_no**, int);

#endif
