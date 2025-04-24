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

    return 0;
}