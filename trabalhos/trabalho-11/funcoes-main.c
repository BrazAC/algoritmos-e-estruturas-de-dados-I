#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void main_carregaHeap(tipo_heap *heap, tipo_no_lista *lista, char criterio){
    //Prt auxiliar para iterar pela lista
    tipo_no_lista *aux;
    aux = lista;

    //Determinar qual criterio de chave foi escolhido
    heap->criterioChave = criterio;

    //Inserir dados da lista no heap maximo conforme o criterio escolhido
    while(aux != NULL){
        //Inserir dados do noh atual no heap
        heap_inserePorCriterio(heap, *aux, heap->criterioChave);

        //Acancar para o proximo noh
        aux = aux->prox;
    }
}

void main_carregaLista(FILE *arquivo, tipo_no_lista **lista){
    //Criar noh auxiliar para a funcao de insercao
    tipo_no_lista nohAux;

    //Variaveis auxiliares
    char *tokens[10];
    char *token;
    int contTokens = 0;
    char tempLinha[251];

    //Mover cursor paraa segunda linha do arquivo
    while(1){
        if(fgetc(arquivo) == '\n') break;
    }

    //Extrair dados linha a linha e inserir na lista
    while(fgets(tempLinha, 251, arquivo) != NULL){
        //---Logica da funcao strtok
        //Inicializar token (pegar primeira string antes de "," o nome do pais)
        token = strtok(tempLinha, ",");
        //Guardar na lista de tokens
        tokens[contTokens] = token;
        //Obter resto dos dados da linha
        while (token != NULL) {
            //Extrair proximo token (proxima string)
            token = strtok(NULL, ",");
            
            //Extraindo apenas primeiras 10 strins dalinha
            contTokens ++;
            if(contTokens == 10){ 
                break;
            }
            else{
                //Guardar na lista de tokens
                tokens[contTokens] = token;
            } 
        }
        contTokens = 0;

        //---Guardar dados no nohAux, realizando as conversoes
        //Pais/regiao
        strcpy(nohAux.pais, tokens[0]);
        //Casos confirmados
        nohAux.confirmados = atoi(tokens[1]);
        //Casos de morte
        nohAux.mortes = atoi(tokens[2]);
        //Casos de recuperados
        nohAux.recuperados = atoi(tokens[3]);
        //Mortes / 100
        nohAux.mortes100 = atof(tokens[8]);
        //Recuperados / 100
        nohAux.recuperados100 = atof(tokens[9]);

        //---Inserir na lista    
        lista_insereInicio(lista, nohAux);
    }
}