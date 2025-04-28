#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

//Primeira parte da aula
est_noArv* alocaNo(int chave, int dado){
    est_noArv *novoNo = (est_noArv*)malloc(sizeof(est_noArv));
    novoNo->chave = chave;
    novoNo->dado = dado;
    novoNo->esq = NULL;
    novoNo->dir = NULL;

    return novoNo;
}

void arv_insere(est_noArv** noArv, int chave, int valor){
    est_noArv *novoNo;
    if (*noArv == NULL){
        novoNo = alocaNo(chave, valor);
        *noArv = novoNo;
    }
    else{
        if (chave < (*noArv)->chave){
            arv_insere(&((*noArv)->esq), chave, valor);
        }
        else{
            arv_insere(&((*noArv)->dir), chave, valor);
        }
    }
}

void percurso_preOrdem(est_noArv *noArv){
    if (noArv == NULL) {
       return;
    }
    else{
        printf("[%d]", noArv->chave);
        percurso_preOrdem(noArv->esq);
        percurso_preOrdem(noArv->dir);
    }
}

void percurso_Ordem(est_noArv *noArv){
    if (noArv == NULL) {
        return;
    }
    else{
        percurso_Ordem(noArv->esq);
        printf("[%d]", noArv->chave);
        percurso_preOrdem(noArv->dir);
    }
}

void percurso_posOrdem(est_noArv *noArv){
    if (noArv == NULL) {
        return;
    }
    else{
        percurso_Ordem(noArv->esq);
        percurso_preOrdem(noArv->dir);
        printf("[%d]", noArv->chave);
    }
}

//Segunda parte da aula
int arv_totalDeNos(est_noArv *noArv){
    if (noArv == NULL) {
        return 0;
    }
    else{
        return 1 + arv_totalDeNos(noArv->esq) + arv_totalDeNos(noArv->dir);
    }
}

int arv_totalDeFolhas(est_noArv *noArv){
    //E nulo?
    if(noArv == NULL){
        return 0;
    }
    else{
        //E uma folha?
        if (noArv->esq == NULL && noArv->dir == NULL) {
            return 1;
        }
        else{
            return arv_totalDeFolhas(noArv->esq) + arv_totalDeFolhas(noArv->dir);
        }
    }
}

est_noArv* arv_buscaNo(est_noArv *noArv, int chave){
    //E nulo?
    if (noArv == NULL){
        return NULL;
    }
    else{
        //A chave alvo e igual a chave do no?
        if (chave == noArv->chave) {
            return noArv;
        }
        else{
            //A chave alvo ta a esquerda da chave atual?
            if(chave < noArv->chave){
                return arv_buscaNo(noArv->esq, chave);
            }
            else{
                return arv_buscaNo(noArv->dir, chave);
            }
        }
    }
}

int arv_eFolha(est_noArv *noArv, int chave){
    //E nulo?
    if (noArv == NULL){
        return 0;
    }
    else{
        //A chave atual e igual a chave alvo
        if (noArv->chave == chave) {
            //E folha?
            if (noArv->esq == NULL && noArv->dir == NULL){
                return 1;
                
            }
            else{
                return 0;
            }
        }
        else{
            //Chamar recursivamente na direcao correta
            if (chave < noArv->chave) {
                return arv_eFolha(noArv->esq, chave);
            }
            else{
                return arv_eFolha(noArv->dir, chave);
            }
        }
    }
}

int arv_altura(est_noArv *noArv){
    if(noArv == NULL){
        return -1;
    }
    else{
        int h_esq = arv_altura(noArv->esq);
        int h_dir = arv_altura(noArv->dir);
        
        if (h_esq > h_dir){
            return h_esq + 1;
        }
        else{
            return h_dir + 1;
        }
    }
}

void imprime_nivel(est_noArv *noArv, int nivel, int max_nivel){
    if (noArv != NULL) {
        if (nivel == max_nivel){
            printf("[%d|%d]", noArv->chave, noArv->dado);
        }
        else{
            imprime_nivel(noArv->esq, nivel + 1, max_nivel);
            imprime_nivel(noArv->dir, nivel + 1, max_nivel);
        }
    }
}

void imprime_arv_nivel(est_noArv *noArv){
    int h = arv_altura(noArv);
    int nivel = 0;

    for (nivel = 0; nivel <= h; nivel++) {
        printf("Nivel %d: ", nivel);
        imprime_nivel(noArv, 0, nivel);
        printf("\n");
    }
}

int contabiliza_nos_nivel(est_noArv *noArv, int nivel){
    if (noArv == NULL) {
        return 0;
    }
    else if(nivel == 0){
        return 1;
    }
    else{
        return contabiliza_nos_nivel(noArv->esq, nivel - 1) + contabiliza_nos_nivel(noArv->dir, nivel - 1);
    }
}

void imprime_rota(est_noArv *noArv, int chave){
    //Se o valor nao existir
    //Melhor usar uma flag pra evitar a busca pelo valor a toda chamada da funcao
    if(arv_buscaNo(noArv, chave) == NULL){
        printf("No com chave %d nao encontrado\n", noArv->chave);
    }
    else{
        printf("[%d|%d]\n", noArv->chave, noArv->dado);
        
        if(chave < noArv->chave){
            imprime_rota(noArv->esq, chave);
        }
        else if (chave > noArv->chave){
            imprime_rota(noArv->dir, chave);
        }
        else{
            printf("FIM!\n");
        }
    }
}

est_noArv* arv_menorVal(est_noArv *noArv){ 
    //Busca é identificando o melhor caminho
    if (noArv == NULL) {    
        return NULL;
    }
    else{
        if (noArv->esq == NULL) {
            return noArv;
        }
        else{
            return arv_menorVal(noArv->esq);
        }
    }
}
est_noArv* arv_maiorVal(est_noArv *noArv){ 
    //Busca é identificando o melhor caminho
    if (noArv == NULL) {    
        return NULL;
    }
    else{
        if (noArv->dir == NULL) {
            return noArv;
        }
        else{
            return arv_menorVal(noArv->dir);
        }
    }
}

est_noArv remove_no(est_noArv **noArv, int chave){
    if (*noArv != NULL) {
        if((*noArv)->chave == chave){
            est_noArv dadoRm = *(*noArv);
            if((*noArv)->esq == NULL && (*noArv)->dir == NULL){
                free(*noArv);
                *noArv = NULL;
            }
            else if((*noArv)->esq == NULL && (*noArv)->dir != NULL) {
                est_noArv *filho = (*noArv)->dir;
                free(*noArv);
                *noArv = filho;
            }
            else if((*noArv)->dir == NULL && (*noArv)->esq != NULL) {
                est_noArv *filho = (*noArv)->esq;
                free(*noArv);
                *noArv = filho;
            }
            else{
                est_noArv *temp = arv_menorVal((*noArv)->dir);
                (*noArv)->chave = temp->chave;
                (*noArv)->dado = temp->dado;
                remove_no(&((*noArv)->dir), temp->chave);
            }
            return dadoRm;
        }
        else{
            if(chave > (*noArv)->chave){
                remove_no(&((*noArv)->dir), chave);
            }
            else{
                remove_no(&((*noArv)->esq), chave);
            }
        }
    }
}
/*
est_noArv arv_removeNo(est_noArv **noArv, int chave){
    if (*noArv == NULL) {
        est_noArv nullNode;
        nullNode.chave = -1;
        return nullNode;
    }
    else{
        if (chave == (*noArv)->chave) {
            //Referencia o removido
            est_noArv noRm = *(*noArv);

            //1-Se for uma folha
            if ((*noArv)->esq == NULL && (*noArv)->dir == NULL){
                //Atualiza prt esq ou dir do pai (que aponta para o no atual, portanto é o nó atual)
                *noArv = NULL;
                //Libera o noh
                free(*noArv);
                //Retorna o removido
                return noRm;
            }
            //2-Se o nó só tiver um filho
            if ((*noArv)->esq == NULL && (*noArv)->dir != NULL) {//So tem o direito
                //Atualizar prt do pai
                *noArv = (*noArv)->dir;
                //Retorna o removido
                return noRm;
            }
            else if ((*noArv)->dir == NULL && (*noArv)->esq != NULL) {//So tem o esquerdo
                //Atualizar prt do pai
                *noArv = (*noArv)->esq;
                //Retorna o removido
                return noRm;
            }
            //3-Se o nó tem duas folhas
            //Busca o maior a esquerda ou o menor a direita
            //Atualiza o prt que aponta para o no removido
            //retorna o removido
        }
        else{
            if (chave < (*noArv)->chave){
                return arv_removeNo((*noArv)->esq, chave);
            }
            else{
                return arv_removeNo((*noArv)->dir, chave);
            }
        }
    }
}

//Versão professor
est_noArv *remove_no(est_noArv *no, int chave){
    est_noArv *temp;
    if (no == NULL) {
        return NULL;
    }
    else{
        if (chave < no->chave){
            no->esq = remove_no(no->esq, chave);
        }
        else if (chave > no->chave){
            no->dir = remove_no(no->dir, chave);
        }
        else{
            //1 - Se for uma folha
            if (no->esq == NULL && no->dir == NULL) {
                free(no);
                no = NULL;
            }
            //2 - So tem um filho
            else if(no->esq == NULL && no->dir != NULL){
                temp = no;
                no = no->dir;
                free(temp);
            }
            else if(no->dir == NULL && no->esq != NULL){
                temp = no;
                no = no->esq;
                free(temp);
            }
            //3 - tem dois filhos
            else{
                //Temp reccebe o maior valor do filho esquerdo
                est_noArv *temp = busca_maior_no(no->esq);
                no->chave = temp->chave;
                no->dado = temp->dado;
                no->esq = remove_no(no->esq, temp->chave);
            }
        }
    }
}
*/

