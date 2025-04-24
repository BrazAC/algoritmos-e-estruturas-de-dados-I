#include "funcoes-filadindupla.h"
#include <stdlib.h>
#include <stdio.h>

//Inserir
tipo_no* alocaNo(int novoDado){
    tipo_no *novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    novoNo->dado = novoDado;
    novoNo->prox = NULL;
    novoNo->ant = NULL;

    return novoNo;
}

int listaDinDupla_insereInicio(tipo_no **prt_base, int novoDado){
    //Se estiver vazia
    if ((*prt_base) == NULL) {
        *prt_base = alocaNo(novoDado);
        return 0;
    }

    tipo_no *novoNo = alocaNo(novoDado);
    novoNo->prox = *prt_base;
    novoNo->prox->ant = novoNo;

    novoNo->ant = NULL; //ERRO
    *prt_base = novoNo;
    return 0;
}

int listaDinDupla_insereFim(tipo_no **prt_base, int novoDado){
    if ((*prt_base) == NULL) {
        (*prt_base) = alocaNo(novoDado);
        return 0;
    }

    tipo_no *aux = *prt_base;
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }

    aux->prox = alocaNo(novoDado);
    aux->prox->ant = aux;
    return 0;
}

int listaDinDupla_inserePos(tipo_no **prt_base, int novoDado, int posicao){
    /*CASOS ESPECIAIS
    1 - Insercao na posicao 0 ou em lista vazia
    2 - Insercao na primeira posicao nao existente apos o final da lista
    */

    posicao --;

    //CASO ESPECIAL 1
    if ((*prt_base) == NULL || posicao == 0) {
        listaDinDupla_insereInicio(prt_base, novoDado);
        return 0;
    }

    int cont = 0;
    tipo_no *aux = *prt_base;

    while (aux->prox != NULL && cont < posicao) {
        aux = aux->prox;
        cont ++;
    }

    //CASO ESPECIAL 2
    if (aux->prox == NULL && cont+1 == posicao) {
        //Nao usar:
        //listaDinDupla_insereFim(prt_base, novoDado);
        //Pois essa funcao corre novamente pela lista
        //Usar:
        tipo_no *novoNo = alocaNo(novoDado);
        novoNo->ant = aux;
        aux->prox = novoNo;
    }
    //Se for uma posicao valida qualquer
    else if (cont == posicao){
        tipo_no *novoNo = alocaNo(novoDado);
        novoNo->prox = aux;
        novoNo->ant = aux->ant;

        novoNo->prox->ant = novoNo;
        novoNo->ant->prox = novoNo;
    }
    //Se for posicao invalida
    else {
        //Erro, posicao fora dos limites
        printf("[ERRO] Tentando inserir em posicao fora dos limites\n");
        return -1;
    }
}

//Remover
int listaDinDupla_removeInicio(tipo_no** prt_base){ //CASO ESPECIAL
    if ((*prt_base) == NULL) {
        printf("[ERRO] Tentando remover do inicio de lista vazia\n");
        return -1;
    }

    tipo_no *aux = *prt_base;
    int dadoRm = aux->dado;

    //CASO ESPECIAL (o primeiro elemento e o unico da lista)
    if (aux->prox == NULL) {
        int dadoRm = aux->dado;
        *prt_base = NULL;
        free(aux);
        return dadoRm;
    }
    else{
        *prt_base = aux->prox;
        aux->prox->ant = NULL;
        free(aux);
        return dadoRm;
    }   
}

int listaDinDupla_removeFinal(tipo_no** prt_base){ //CASO ESPECIAL
    if ((*prt_base) == NULL) {
        printf("[ERRO] Tentando remover de final de lista vazia\n");
        return -1;
    }

    tipo_no *aux = *prt_base;
    while(aux->prox != NULL){
        aux=aux->prox;
    }

    //CASO ESPECIAL (removendo primeiro elemento: anterior = NULL)
    if (aux->ant == NULL) {
        int dadoRm = aux->dado;
        *prt_base = NULL;
        free(aux);
        return dadoRm;
    }
    else{
        int dadoRm = aux->dado;
        aux->ant->prox = NULL;
        free(aux);
        return dadoRm;
    }
    

}

int listaDinDupla_removePos(tipo_no** prt_base, int posicao){ //CASO ESPECIAL
    /*CASOS ESPECIAIS
    1 - Remover do inicio
    2 - Remover do fim
    3 - Remover unico elemento da lista
    */
    if (*prt_base == NULL){
        printf("[ERRO] Tentando remover por posicao de lista vazia\n");
        return -1;
    }

    posicao --;

    //CASO ESPECIAL 1
    if (posicao == 0) {
        listaDinDupla_removeInicio(prt_base);
        return 0;
    }

    tipo_no *aux = *prt_base;
    int cont = 0;
    while(aux->prox != NULL && cont < posicao){
        aux = aux->prox;
        cont++;
    }

    //CASO ESPECIAL 2
    if (aux->prox == NULL) {
        int dadoRm = aux->dado;
        aux->ant->prox = NULL;
        free(aux);
        return dadoRm;
    }
    //CASO ESPECIAL 3
    else if(aux->ant == NULL){
        listaDinDupla_removeInicio(prt_base);
    }
    //CASO Normal
    else if(cont == posicao){
        int dadoRm = aux->dado;

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;

        free(aux);
        return dadoRm;
    }
    //Posicao invalida
    else{
        printf("[ERRO] Tentando remover por posicao em posicao invalida");
        return -1;
    }
}

int listaDinDupla_removeValor(tipo_no** prt_base, int valor){
    if (*prt_base == NULL) {
        printf("[ERRO] Tentando remover valor de lista vazia\n");
        return -1;
    }

    tipo_no *aux = *prt_base;
    while(aux->prox != NULL && aux->dado != valor){
        aux = aux->prox;
    }

    if (aux->prox == NULL && aux->dado != valor) {
        printf("[WARNING] Tentando remover valor que nao esta na lista\n");
    }
    else if(aux->ant == NULL && aux->dado == valor){
        listaDinDupla_removeInicio(prt_base);
    }
    else if(aux->prox == NULL && aux->dado == valor){
        listaDinDupla_removeFinal(prt_base);
    }
    else{
        int dadoRm = aux->dado;

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;

        free(aux);
        return dadoRm;
    }


}

//Buscar 
//TODO (recebe um dado, retorna o endereco do no que contem esse dado)
tipo_no* listaDinDupla_buscaElemento(tipo_no** prt_base, int valor){

}

//Mostrar
int listaDinDupla_mostrar(tipo_no** prt_base){
    if ((*prt_base) == NULL) {
        printf("[WARNING] Tentando mostrar lista vazia\n");
        return -1;
    }

    tipo_no *aux = *prt_base;
    while (aux->prox != NULL)
    {
        printf("[%d]", aux->dado);
        aux=aux->prox;
    }
    printf("[%d]\n", aux->dado);
    
}

