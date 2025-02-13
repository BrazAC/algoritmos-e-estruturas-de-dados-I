#include <stdlib.h>
#include <stdio.h>

/*
typedef struct tipo_no{
    tipo_de_dado dado;
    tipo_no *prox;

} tipo_no;
*/

typedef struct tipo_no{
    int dado;
    tipo_no *prox;
} tipo_no;

void* alocaNo(int);
void insere_fila_din(tipo_no**, int);
int remove_fila_din(tipo_no**);
int primeiro_fila_din(tipo_no*);
void mostra_fila_din(tipo_no*);

int main(){
    //Referencia (ponteiro) da base da fila (os nos se empilham aqui em cima)
    tipo_no* prt_base_fila;

    return 0;
}

void insere_fila_din(tipo_no **prt_prt_base_fila, int novoInt){
    //A fila esta vazia (ponteiro da base esta vazio)
    //*prt_prt_base_fila == prt_base_fila
    if (*prt_prt_base_fila == NULL) {
        //Criar novo no (criar por chamada da funcao alocaNo())

        //Guardar endereco do novo no na base da fila (em *prt_prt_base_fila)
    }
    //A fila nao esta vazia (ponteiro da base aponta pra alguma coisa)
    else{
        //-- Avancar ate o ultimo no
        //Criar ponteiros auxiliares

        //Posicionar ponteiro auxiliar no ultino no

        //Alocar novo noh, cadastrar seu endereco no ultimo no (criar no e encadear na estrutura)

    }
}

