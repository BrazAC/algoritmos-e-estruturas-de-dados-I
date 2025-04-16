#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include <time.h>

int main(){
    //====Criar estruturas
    tipo_no_lista *listaPrincipal = NULL;
    tipo_heap heapPrincipal;
    heapPrincipal.cont = 0;

    srand(time(NULL));

    //====Extrair dados do arquivo e carregar na lista dinamica
    for(int i = 1; i <= 5; i++){
        //Criando noh temporario para armazenar os dados extraidos
        tipo_no_lista tempNoh;

        //Extrair dados do arquivo, inserindo no noh temporario
        tempNoh.confirmados = (rand() % 100) + 1;
        strcpy(tempNoh.pais, "teste yupi");

        //Inserir informacoes do noh temporario na lista
        lista_insereInicio(&listaPrincipal, tempNoh);
    }

    lista_mostra(listaPrincipal);

    //====Menu


    /*
    FUNCAO QUE INSERE CADA ELEMENTO DA LISTA (SEM REMOVER DELA) NO HEAP

    //Prt auxiliar para iterar pela lista
    tipo_no_lista *aux;
    aux = listaPrincipal;

    //Determinar qual criterio de chave foi escolhido
    heapPrincipal.criterioChave = 'c';

    //Inserir dados da lista no heap maximo conforme o criterio escolhido
    while(aux != NULL){
        //Inserir dados do noh atual no heap
        heap_inserePorCriterio(&heapPrincipal, *aux, heapPrincipal.criterioChave);

        //Acancar para o proximo noh
        aux = aux->prox;
    }
    */




    
    heap_removeEmostraX(&heapPrincipal, 10);

    return 0;
}