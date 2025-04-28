#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main(){
    tipo_no_arvM *arvMultNo = NULL;

    //Insercao
    arvMultNo_insere(&arvMultNo, 'c', 7);
    arvMultNo_insere(&arvMultNo, 'd', 1);
    arvMultNo_insere(&arvMultNo, 'a', 2);
    arvMultNo_insere(&arvMultNo, 'h', 9);
    arvMultNo_insere(&arvMultNo, 'e', 3);
    arvMultNo_insere(&arvMultNo, 'u', 4);
    arvMultNo_insere(&arvMultNo, 'l', 5);
    arvMultNo_insere(&arvMultNo, 'z', 6);
    arvMultNo_insere(&arvMultNo, 'z', 0);
    arvMultNo_insere(&arvMultNo, 'j', 10);
    arvMultNo_insere(&arvMultNo, 'j', 23);

    //Percurso
    arvMultNo_preOrdem(arvMultNo);
    //arvMultNo_posOrdem(arvMultNo);
    //arvMultNo_Ordem(arvMultNo);

    //Gerais
    int totalNos;
    totalNos = arvMultNo_totalNos(arvMultNo);
    printf("Total de nós: %d\n", totalNos);

    int totalFolhas;
    totalFolhas = arvMultNo_totalFolhas(arvMultNo);
    printf("Total de folhas: %d\n", totalFolhas);

    tipo_no_arvM *noProcurado;
    noProcurado = arvMultNo_buscaNo(arvMultNo, 0);
    if (noProcurado == NULL) {
        printf("Noh nao encontrado!\n");
    }
    else{
        printf("Primeiro elemento do encontrado: [%c|%d]\n", noProcurado->dados[0].dado, noProcurado->dados[0].chave);
    }

    tipo_dado *dadoProcurado;
    dadoProcurado = arvMultNo_buscaDado(arvMultNo, 1);
    if (dadoProcurado == NULL) {
        printf("Dado nao encontrado!\n");
    }
    else{
        printf("Dado encontrado: [%c|%d]\n", dadoProcurado->dado, dadoProcurado->chave);
    }

    //Remocao
    tipo_dado dadoRm = arvMultNo_remove(&arvMultNo, 23);
    printf("Primeiro dado do elemento removido: [%d|%c]\n", dadoRm.chave, dadoRm.dado);
    arvMultNo_preOrdem(arvMultNo);

    return 0;
}