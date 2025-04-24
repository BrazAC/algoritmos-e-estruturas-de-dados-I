#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main(){
    est_noArv *arvoreRaiz;
    arvoreRaiz = NULL;

    arv_insere(&arvoreRaiz, 30, 33);
    arv_insere(&arvoreRaiz, 91,73);
    arv_insere(&arvoreRaiz, 15, 33);
    arv_insere(&arvoreRaiz, 72, 87);
    arv_insere(&arvoreRaiz, 61, 12);
    arv_insere(&arvoreRaiz, 41, 54);
    arv_insere(&arvoreRaiz, 10, 23);
    arv_insere(&arvoreRaiz, 37, 23);
    arv_insere(&arvoreRaiz, 98, 23);
    arv_insere(&arvoreRaiz, 41, 23);
    arv_insere(&arvoreRaiz, 94, 23);
    arv_insere(&arvoreRaiz, 80, 23);
    arv_insere(&arvoreRaiz, 26, 23);
    arv_insere(&arvoreRaiz, 96, 23);
    arv_insere(&arvoreRaiz, 10, 23);
    


    //E IIMPORTANTE VERIFICAR A ARVORE NAO APENAS COM A ORDEM
    //A impressao que mostra a verdadeira sequencia é a pre ordem
    printf("Imprimindo em preOrdem\n");
    percurso_preOrdem(arvoreRaiz);
    printf("\n");

    printf("Imprimindo em Ordem\n");
    percurso_Ordem(arvoreRaiz);
    printf("\n");

    printf("Imprimindo em posOrdem\n");
    percurso_posOrdem(arvoreRaiz);
    printf("\n");

    int quatNos = arv_totalDeNos(arvoreRaiz);
    printf("Quantidade de nos: [%d]\n", quatNos);

    int quatFolhas = arv_totalDeFolhas(arvoreRaiz);
    printf("Quantidade de folhas: [%d]\n", quatFolhas);

    est_noArv* noEncontraco = arv_buscaNo(arvoreRaiz, 10);
    printf("Dado encontrado: [%d]\n", noEncontraco->dado);

    int eFolha =  arv_eFolha(arvoreRaiz, 72);
    if(eFolha){
        printf("E folha!\n");
    }
    else{
        printf("Nao e folha!\n");
    }

    int altura = arv_altura(arvoreRaiz);
    printf("Altura: [%d]\n", altura);

    imprime_arv_nivel(arvoreRaiz);

    est_noArv *menorDado = arv_menorVal(arvoreRaiz);
    printf("Menor dado: %d\n", menorDado->dado);

    

    return 0;
}