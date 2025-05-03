#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
#include <string.h>

tipo_noh_ab* alocaNoh(float preco, char codigo[], char titulo[], float avaliacao, int categoria){
    tipo_noh_ab *novoNoh = (tipo_noh_ab*)malloc(sizeof(tipo_noh_ab));
    novoNoh->preco = preco;
    strcpy(novoNoh->codigo, codigo);
    strcpy(novoNoh->titulo, titulo);
    novoNoh->avaliacao = avaliacao;
    novoNoh->categoria = categoria;
    novoNoh->esq = NULL;
    novoNoh->dir = NULL;
    return novoNoh;
}

void ab_insere(tipo_noh_ab **noh, float preco, char codigo[], char titulo[], float avaliacao, int categoria){
    if(*noh == NULL){
        *noh = alocaNoh(preco, codigo, titulo, avaliacao, categoria);
        //printf("[%-7.2f|%10s|%3d|%2.1f|%200s]\n", (*noh)->preco, (*noh)->codigo, (*noh)->categoria, (*noh)->avaliacao, (*noh)->titulo);
    }else{
        if(preco > (*noh)->preco){
            ab_insere(&((*noh)->dir), preco, codigo, titulo, avaliacao, categoria);
        }else{
            ab_insere(&((*noh)->esq), preco, codigo, titulo, avaliacao, categoria);
        }
    }
}

void ab_carregaSubArvoreBin(tipo_categoria *categoria, tipo_noh_ab* arv_produtos){
    if(categoria->possuiSubArvoreBin == 1){
        return;
    }else{
        //Procurar na arvore bin de produtos todos aqueles com o id em questao, e cadastrar na sub arvore
        ab_buscaTodosEcadastra(&(categoria->sub_arv_bin), arv_produtos, categoria->id);
    }
}

void ab_buscaTodosEcadastra(tipo_noh_ab **sub_arv_bin, tipo_noh_ab *arv_produtos, int id_categoria){
    if(arv_produtos == NULL){
        //Quando chegar a um extremo retorne
        return;
    }else{
        //Se a categoria do produto atual for a procurada
        if(arv_produtos->categoria == id_categoria){
            //Cadastre os dados na sub-arvore
            ab_insere(sub_arv_bin, arv_produtos->preco, arv_produtos->codigo, arv_produtos->titulo, arv_produtos->avaliacao, arv_produtos->categoria);
        }
        else{
            //Chame recursivamente para os filhos
            ab_buscaTodosEcadastra(sub_arv_bin, arv_produtos->esq, id_categoria);
            ab_buscaTodosEcadastra(sub_arv_bin, arv_produtos->dir, id_categoria);
        }
    }
}

void ab_mostraNivel(tipo_noh_ab *noh, int nivel){
    if(noh == NULL){
        return;
    }else{
        if(nivel == 0){
            printf("[%-7.2f|%10s|%3d|%2.1f|%200s]\n", 
            noh->preco,
            noh->codigo,
            noh->categoria,
            noh->avaliacao,
            noh->titulo);
        }else{
            ab_mostraNivel(noh->esq, nivel - 1);
            ab_mostraNivel(noh->dir, nivel - 1);
        }
    }
}