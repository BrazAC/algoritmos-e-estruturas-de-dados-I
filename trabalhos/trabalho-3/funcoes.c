#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"


FILE* arquivo_gera(lista_estatica* lista){
    //==ALOCAR ARQUIVO
    //Alocar arquivo no heap (vazio)
    
    //==PREENCHER ARQUIVO COM DADOS DA LISTA EMBARALHADA
    //Repetir quantValores vezes
        //Inserir dado atual de lista no final do arquivo

    //Retornar o endereco do arquivo
}

int inserir_lista(lista_estatica* lista){
    int valorInserido = lista_embaralhada(lista);
    lista->vet[lista->contador] = 0;
    lista->contador++;
    return 0;
}

int lista_embaralha(lista_estatica* lista, int quantElementosInt){
    //Repetir quantElementos vezes

    //faca
    while (1){
        if (lista->contador == quantElementosInt){
            return -1;
        } else {
            srand(time(NULL));
            int numAleatorio = rand() % 1000000;
            for (int i = 0; i < lista->contador; i++){
                if (lista->vet[i] == numAleatorio){
                    break;
                }
            }
        }
    }
        //Gera valor aleatorio
        //Itera pela lista conferindo se ha o numero aleatorio
    //enquanto (valor gerado existir na lista)
    //Inserir no final da lista o valor aleatorio gerado
}

    