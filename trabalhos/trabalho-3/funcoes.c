#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"

FILE* arquivo_gera(lista_estatica* lista, char nomeArquivo[]){
    //==ALOCAR ARQUIVO
    //Alocar arquivo já na pasta "./arquivos"
    FILE* arquivo = fopen(nomeArquivo, "w");
    
    //==PREENCHER ARQUIVO COM DADOS DA LISTA EMBARALHADA
    //Repetir quantValores (ou tamanho da lista) vezes
    for (int i = 0; i < lista->contador; i++) {
        //Inserir dado atual de lista no final do arquivo
        fprintf(arquivo, "%d\n",lista->vet[i]);
    }

    //Retornar o endereco do arquivo
    return arquivo;
}

int inserir_lista(lista_estatica* lista, int valor){
    lista->vet[lista->contador] = valor;
    lista->contador++;
    return 0;
}

int lista_inicializaEmbaralha(lista_estatica* lista, int quantElementosInt){
    //Mostrando que o programa está gerando as listas para o usuário
    printf("Gerando...\n");

    //Repetir quantElementos vezes
    //faca
    while (1){
        if (lista->contador == quantElementosInt){
            //Lista Cheia
            printf("Finalizado\n");
            return -1;
        } else {
            
            //Gera valor aleatorio 
            int numAleatorio = rand() % 1000000;
            int encontrado = 0;

            //Itera pela lista conferindo se ha o numero aleatorio
            for (int i = 0; i < lista->contador; i++){
                if (lista->vet[i] == numAleatorio){
                    //Valor encontrado
                    encontrado = 1;
                    break;
                }
            }
            //Se o valor não existir na lista
            if (encontrado == 0){
                //Inserir no final da lista o valor aleatorio gerado
                inserir_lista(lista, numAleatorio);
            }
        }
    }
}

    