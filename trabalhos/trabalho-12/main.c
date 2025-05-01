#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main(){
    tipo_noh_am *arv_categorias = NULL;

    am_inserePorIdPai(&arv_categorias, 1, 0, "Casa");
    am_inserePorIdPai(&arv_categorias, 2, 0, "Pessoal");
    am_inserePorIdPai(&arv_categorias, 3, 0, "Automotivo");

    am_inserePorIdPai(&arv_categorias, 65, 2, "Oral higiene");
    am_inserePorIdPai(&arv_categorias, 17, 3, "Automotive Tools");

    am_mostraNivel(arv_categorias, 1);
    //am_preOrdem(arv_categorias);
    printf("\n");

    return 0;
}