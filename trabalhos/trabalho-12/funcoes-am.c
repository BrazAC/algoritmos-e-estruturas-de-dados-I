#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
#include <string.h>

tipo_noh_am* alocaNohAm(int id_cat, int id_pai_cat, char nome_cat[]){
    tipo_noh_am *novoNoh = (tipo_noh_am*)malloc(sizeof(tipo_noh_am));
    
    for (int j = 0; j < (MAX_DADOS_CAT + 1); j++) {
        novoNoh->filhos[j] = NULL;
    }

    tipo_categoria novaCat;
    novaCat.id = id_cat;
    novaCat.id_pai = id_pai_cat;
    strcpy(novaCat.nome, nome_cat);
    novoNoh->dados[0] = novaCat;

    novoNoh->cont = 1;

    return novoNoh;
}

void am_inserePorIdPai(tipo_noh_am **noh, int id_cat, int id_pai_cat, char nome_cat[]){
    if(id_pai_cat == 0){
        if(*noh == NULL){
            *noh = alocaNohAm(id_cat, id_pai_cat, nome_cat);
        }else{
            (*noh)->dados[(*noh)->cont].id = id_cat;
            (*noh)->dados[(*noh)->cont].id_pai = id_pai_cat;
            strcpy((*noh)->dados[(*noh)->cont].nome, nome_cat);
            (*noh)->cont ++;
        }
    }else{
        //Encontrar a posicao da categoria pai procurada
        int pos = 0;
        while(pos < (*noh)->cont && (*noh)->dados[pos].id != id_pai_cat) pos ++;

        //Acessar noh esquerdo da categoria pai e inserir a nova categoria
        tipo_noh_am *nohFilho = (*noh)->filhos[pos];

        if(nohFilho == NULL){
            (*noh)->filhos[pos] = alocaNohAm(id_cat, id_pai_cat, nome_cat);
        }else{
            nohFilho->dados[nohFilho->cont].id = id_cat;
            nohFilho->dados[nohFilho->cont].id_pai = id_pai_cat;
            strcpy(nohFilho->dados[nohFilho->cont].nome, nome_cat);
            nohFilho->cont ++;
        }  
    }
}

void am_mostraNivel(tipo_noh_am *noh, int nivel){
    if(noh == NULL){
        return;
    }
    else{
        if(nivel == 0){
            for(int i = 0; i < noh->cont; i++){
                printf("[%d|%s|%d]\n", noh->dados[i].id, noh->dados[i].nome, noh->dados[i].id_pai);
            }
        }
        else{
            for(int j = 0; j <= noh->cont; j++){
                am_mostraNivel(noh->filhos[j], nivel - 1);
            }
        }
    }
}

void am_preOrdem(tipo_noh_am *noh){
    if(noh == NULL){
        return;
    }
    else{
        for(int i = 0; i < noh->cont; i++){
            printf("[%d|%s|%d]", noh->dados[i].id, noh->dados[i].nome, noh->dados[i].id_pai);
            
        }
        printf("\n");

        for(int j = 0; j <= noh->cont; j++){
            am_preOrdem(noh->filhos[j]);
        }
    }
}