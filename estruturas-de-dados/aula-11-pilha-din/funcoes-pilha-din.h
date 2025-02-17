#ifndef __FUNCOES_PILHA_DIN_H__
#define __FUNCOES_PILHA_DIN_H__

typedef struct tipo_no{
    int valor;
    struct tipo_no *proximo;
} tipo_no;

tipo_no* criaNo(int);
void pilhaDin_insere(tipo_no**, int);
int pilhaDin_remove(tipo_no**);
int pilhaDin_mostra(tipo_no**);
int pilhaDinRec_mostra(tipo_no**);


#endif //__FUNCOES_PILHA_DIN_H__