#ifndef __FUNCOES_H__
#define __FUNCOES_H__

#include <stdlib.h>
#include <stdio.h>

#define TAM 100000

typedef struct lista_estatica{
    int vet[TAM];
    int contador;
} lista_estatica;

/**
 * @brief Recebe a quantidade de numeros a serem inseridos no arquivo
 * @param quantidade Quantidade de elementos a serem inseridos
 * @param lista Lista com valores a serem inseridos
 * @return Endereco do arquivo gerado
 */
FILE* arquivo_gera(int, lista_estatica*);

/**
 * @brief Recebe o endereco de uma lista estatica e a embaralha
 * @param lista Endereco da lista estatica
 */
int lista_embaralha(lista_estatica*);


int inserir_lista(lista_estatica*);
#endif