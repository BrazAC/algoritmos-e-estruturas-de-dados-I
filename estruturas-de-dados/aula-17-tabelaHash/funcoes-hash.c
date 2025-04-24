#include <stdlib.h>
#include <stdio.h>
#include "funcoes-hash.h"

//==Lista dinamica
est_no_hash* alocaNoHash(int chave, int dado1, int dado2){
    est_no_hash *novoNo = (est_no_hash*)malloc(sizeof(est_no_hash));
    novoNo->dado1 = dado1;
    novoNo->dado2 = dado2;
    novoNo->chave = chave;
    return novoNo;
}

void listaDin_insereInicio(est_no_hash** lista, est_no_hash *novoNo){
    if (*lista == NULL) {
        *lista = novoNo;
        return;
    }

    novoNo->prox = *lista;
    *lista = novoNo;
    return;
}

int listaDin_RemovePorChave(est_no_hash **lista, int chave){
    if (*lista == NULL) return -1; //Nenhum dado cadastrado com essa chave

    est_no_hash *aux = *lista, *aut = NULL;
    while (aux->prox != NULL){
        if (aux->chave == chave) break;
        aut = aux;
        aux = aux->prox;
    }

    //Ultimo no (talvez tenha a chave!)
    if (aux->prox == NULL){
        if (aux->chave == chave){
            //Removo noh
            int dado1Rm = aux->dado1;
            free(aux);
            aut->prox = NULL;
            return dado1Rm;
        }
        else{
            return -2; //Nenhum dado cadastrado com essa chave 
        }
    }
    //Outro no (tem a chave!)
    else{
        //Removo noh
        int dado1Rm = aux->dado1;
        *lista = aux->prox;
        free(aux);
        return dado1Rm;
    }
}

est_no_hash* listaDin_buscaPorChave(est_no_hash** lista, int chave){
    if (*lista == NULL) return NULL; //Chave nao cadastrada

    est_no_hash *aux = *lista, *aut = NULL;
    while(aux->prox != NULL && aux->chave != chave){
        aut = aux;
        aux = aux->prox;
    }

    //Se estiver no ultimo no
    if(aux->prox == NULL){
        if (aux->chave != chave){
            return NULL;
        }
        else{
            return aux;
        }
    }
    //Se nao estiver no ultimo no
    else{
        return aux;
    }
}

void listaDin_mostra(est_no_hash* lista){
    if (lista == NULL){
        printf("NULL\n");
        return;
    }

    est_no_hash *aux = lista;
    while(aux->prox != NULL){
        printf("[%d]", aux->dado1);
        aux = aux->prox;
    }
    printf("[%d]\n", aux->dado1);
}

//==Tabela hash
int fHash(int chave){
    int indice = chave % MAX_HASH;
    return indice;
}

void inicializaTabHash(est_tabelaHash* tabHash){
    for (int i = 0; i < MAX_HASH; i++){
        tabHash->tabela[i] = NULL;
    }
    tabHash->cont = 0;
}

void insereTabHash(est_tabelaHash* tabHash, int chave, int dado1, int dado2){
    //Verificar se a chave ja esta cadastrada na tabela
    if(buscaTabHash(tabHash, chave) != NULL){
        printf("já esta cadastrada\n");
        return;
    }

    //Alocar e inicializar no
    est_no_hash *novoNo = alocaNoHash(chave, dado1, dado2);

    //Identificar indice
    int indice = fHash(chave);

    //Acessar indice
    est_no_hash **listaDin = &(tabHash->tabela[indice]);
    
    //Tratar colisão e inserir dado
    listaDin_insereInicio(listaDin, novoNo);
}

int removeTabHash(est_tabelaHash* tabHash, int chave){
    //Identificar indice
    int indice = fHash(chave);

    //Acessar indice
    est_no_hash *listaDin = tabHash->tabela[indice];

    //Tratar colisão e remover dado
    int dado1Rm = listaDin_RemovePorChave(&listaDin, chave);

    //Tratar retorno
    if (dado1Rm < 0) {
        return -1;
    }
    else{
        return dado1Rm;
    } 
}

est_no_hash* buscaTabHash(est_tabelaHash* tabHash, int chave){
    //Identificar indice
    int indice = fHash(chave);

    //Acessar indice
    est_no_hash *listaDin = tabHash->tabela[indice];

    //Tratar colisao, buscar pelo noh
    est_no_hash *nohEncontrado = listaDin_buscaPorChave(&listaDin, chave);

    //Tratar retorno
    if (nohEncontrado == NULL){
        return NULL;
    }
    else{
        return nohEncontrado;
    }
}

void mostraTabHash(est_tabelaHash tabHash){
    //Para cada listaDin da tabela hash
    for (int i = 0; i < MAX_HASH; i++) {
        printf("[%d] - ", i);
        listaDin_mostra(tabHash.tabela[i]);
    }
}   