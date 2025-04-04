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
 * @param lista Lista com valores a serem inseridos
 * @return Endereco do arquivo gerado
 */
FILE* arquivo_gera(lista_estatica*, char[]);

/**
 * @brief Recebe o endereco de uma lista estatica e a embaralha
 * @param lista Endereco da lista estatica
 */
int lista_inicializaEmbaralha(lista_estatica*, int);

/**
 * @brief Insere um elemento na lista estatica
 * @param lista Endereco da lista estatica
 * @param valor Valor a ser inserido
 */
int inserir_lista(lista_estatica*, int);
#endif