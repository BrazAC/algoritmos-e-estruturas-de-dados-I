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
    novaCat.possuiSubArvoreBin = 0;
    novaCat.sub_arv_bin = NULL;

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
            (*noh)->dados[(*noh)->cont].sub_arv_bin = NULL;
            (*noh)->dados[(*noh)->cont].possuiSubArvoreBin = 0;

            (*noh)->cont ++;
        }
        //printf("%d\n", (*noh)->cont);
    }else{
        //Encontrar a posicao da categoria pai procurada
        int pos = 0;
        while(pos < (*noh)->cont && (*noh)->dados[pos].id != id_pai_cat) pos ++;

        //Acessar noh esquerdo da categoria pai e inserir a nova categoria
        tipo_noh_am *nohFilho = (*noh)->filhos[pos];

        if(nohFilho == NULL){
            (*noh)->filhos[pos] = alocaNohAm(id_cat, id_pai_cat, nome_cat);
            //printf("%d\n", (*noh)->filhos[pos]->cont);
        }else{
            nohFilho->dados[nohFilho->cont].id = id_cat;
            nohFilho->dados[nohFilho->cont].id_pai = id_pai_cat;
            strcpy(nohFilho->dados[nohFilho->cont].nome, nome_cat);
            nohFilho->dados[nohFilho->cont].possuiSubArvoreBin = 0;
            nohFilho->dados[nohFilho->cont].sub_arv_bin = NULL;
            nohFilho->cont ++;
            //printf("%d\n", nohFilho->cont);
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
                printf("[%5d|%50s|%5d|%d]\n", noh->dados[i].id, noh->dados[i].nome, noh->dados[i].id_pai,noh->dados[i].possuiSubArvoreBin);
            }
        }
        else{
            for(int j = 0; j <= noh->cont; j++){
                am_mostraNivel(noh->filhos[j], nivel - 1);
            }
        }
    }
}

tipo_categoria* am_buscaCategoria(tipo_noh_am *arvore, int id_categoria){
    //iterar por todas subcategorias
    for(int j = 0; j < arvore->cont; j++){
        //Referencia do filo esquerdo
        tipo_noh_am *filhoEsquerdo = arvore->filhos[j];

        //Se tiver filho esquerdo nao e subcategoria (as subcategorias estao no filho esquerdo)
        if(filhoEsquerdo != NULL){
            //Procurar nas subcategorias do filho esquerdo
            for(int i = 0; i < filhoEsquerdo->cont; i++){
                //Se o id da categoria procurada for igual ao id da categoria atual
                if(filhoEsquerdo->dados[i].id == id_categoria){
                    //Retornar endereco da categoria
                    return &(filhoEsquerdo->dados[i]);
                }
            }
        }
        //Se nao tiver filho esquerdo, a categoria atual e subcategoria
        else{
            //Se o id da categoria procurada for igual ao id da categoria atual
            if(arvore->dados[j].id == id_categoria){
                //Retornar endereco da subcategoria
                return &(arvore->dados[j]);
            }
        }
    }

    //Iterou por todos as categorias e nao encontrou a desejada (id de categoria invalido)
    return NULL;
}

void am_carregaTodasSubarvores(tipo_noh_am *arvore, tipo_noh_ab* arv_produtos){
    //iterar por todas subcategorias
    for(int j = 0; j < arvore->cont; j++){
        //Referencia do filo esquerdo
        tipo_noh_am *filhoEsquerdo = arvore->filhos[j];

        //Se tiver filho esquerdo, nao e subcategoria (as subcategorias estao no filho esquerdo)
        if(filhoEsquerdo != NULL){
            //Procurar nas subcategorias do filho esquerdo
            for(int i = 0; i < filhoEsquerdo->cont; i++){
                ab_carregaSubArvoreBin(&(filhoEsquerdo->dados[i]), arv_produtos);
            }
        }
        //Se nao tiver filho esquerdo, a categoria atual e subcategoria
        else{
            ab_carregaSubArvoreBin(&arvore->dados[j], arv_produtos);
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

