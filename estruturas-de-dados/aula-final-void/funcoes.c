#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
#include <string.h>

tipo_noh* alocaNoh(int chave, int rga, char nome[]){
    //Alocar dado
    tipo_aluno* novoDado = (tipo_aluno*)malloc(sizeof(tipo_aluno));
    strcpy(novoDado->nome, nome);
    novoDado->rga = rga;

    //Alocar noh
    tipo_noh* novoNoh = (tipo_noh*)malloc(sizeof(tipo_noh));
    novoNoh->chave = chave;
    novoNoh->esq = NULL;
    novoNoh->dir = NULL;
    //Casting para adicionar o dado generico
    novoNoh->dado = (tipo_aluno*) novoDado;

    return novoNoh;
}

void ab_insere(tipo_noh **noh, int chave, int rga, char nome[]){
    if(*noh == NULL){
        *noh = alocaNoh(chave, rga, nome);
    }else{
        if(chave > (*noh)->chave){
            ab_insere(&((*noh)->dir), chave, rga, nome);
        }else{
            ab_insere(&((*noh)->esq), chave, rga, nome);
        }
    }
}

void ab_mostraNivel(tipo_noh *noh, int nivel){
    if(noh == NULL){
        return;
    }else{
        if(nivel == 0){
            //Casting para acessar o dado generico
            tipo_aluno *dado = (tipo_aluno*)noh->dado;
            printf("[%d|%d|%s]", noh->chave, dado->rga, dado->nome);
        }else{
            ab_mostraNivel(noh->esq, nivel - 1);
            ab_mostraNivel(noh->dir, nivel - 1);
        }
    }
}