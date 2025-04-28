#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main(){
    est_noArv *arvoreRaiz;
    arvoreRaiz = NULL;

    arv_insere(&arvoreRaiz, 10, 0);
    arv_insere(&arvoreRaiz, 12, 0);
    arv_insere(&arvoreRaiz, 7, 0);
    arv_insere(&arvoreRaiz, 4, 0);
    arv_insere(&arvoreRaiz, 9, 0);
    arv_insere(&arvoreRaiz, 11, 0);
    arv_insere(&arvoreRaiz, 13, 0);
    arv_insere(&arvoreRaiz, 8, 0);
    arv_insere(&arvoreRaiz, 3, 0);


    imprime_arv_nivel(arvoreRaiz);
    remove_no(&arvoreRaiz, 9);
    printf("\n");
    imprime_arv_nivel(arvoreRaiz);

    //E IIMPORTANTE VERIFICAR A ARVORE NAO APENAS COM A ORDEM
    //A impressao que mostra a verdadeira sequencia é a pre ordem
    /*
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
    */

    

    return 0;
}