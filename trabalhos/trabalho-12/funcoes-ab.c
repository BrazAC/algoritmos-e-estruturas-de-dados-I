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
        //Atualizar flag
        categoria->possuiSubArvoreBin = 1;
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
            //printf("Cadastrado: [%d|%s]\n", arv_produtos->categoria,arv_produtos->titulo);
            //Chame recursivamente para os filhos
            ab_buscaTodosEcadastra(sub_arv_bin, arv_produtos->esq, id_categoria);
            ab_buscaTodosEcadastra(sub_arv_bin, arv_produtos->dir, id_categoria);
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
        //printf("Cadastrado: [%s]\n", noh->titulo);
        if(nivel == 0){
            //printf("Cadastrado: [%s]\n", noh->titulo);
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

int ab_calculaAltura(tipo_noh_ab *noh){
    if(noh == NULL){
        return -1;
    }else{
        int h_esq = ab_calculaAltura(noh->esq);
        int h_dir = ab_calculaAltura(noh->dir);

        if(h_esq > h_dir){
            return 1 + h_esq;
        }else{
            return 1 + h_dir;
        }
    }
}

void ab_mostraArvore(tipo_noh_ab *noh){
    int altura = ab_calculaAltura(noh);
    
    for (int i = 0; i <= altura; i++) {
        printf("MOSTRANDO NIVEL %d\n", i);
        ab_mostraNivel(noh, i);
    }
}

tipo_noh_ab* ab_buscaProduto(tipo_noh_ab *noh, char codigoProduto[]){
    if(noh != NULL){
        if(strcmp(codigoProduto, noh->codigo) == 0){
            return noh;
        }else{
            return ab_buscaProduto(noh->esq, codigoProduto);
            return ab_buscaProduto(noh->dir, codigoProduto);
        }
    }else{
        return NULL;
    }
}