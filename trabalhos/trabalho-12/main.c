#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main(){
    //===============================================| Inicializacao das arvores
    tipo_noh_am *arv_categorias = NULL;

    //===============================================| Carregar categorias
    //---|Categorias principais
    //Abrir arquivo
    FILE *fcat_principais = fopen("./categorias_principais.csv", "r");
    if(fcat_principais == NULL){
        printf("[ERRO] fopen categorias_principais.csv retornou null");
        return 0;
    }
    //Extrair dados
    main_carregaPrincipais(fcat_principais, &arv_categorias);
    //Fechar arquivo
    fclose(fcat_principais);

    //---|Categorias secundarias/diversas
    FILE *fcat_secundarias = fopen("./amazon_categories_editado.csv", "r");
    if(fcat_secundarias == NULL){
        printf("[ERRO] fopen amazon_categories_editado.csv retornou null");
        return 0;
    }
    //Extrair dados
    main_carregaSecundarias(fcat_secundarias, &arv_categorias);
    //Fechar arquivo
    fclose(fcat_secundarias);

    /*
    printf("NIVEL 0\n");
    am_mostraNivel(arv_categorias, 0);
    printf("NIVEL 1\n");
    am_mostraNivel(arv_categorias, 1);
    printf("\n");
    */

    return 0;
}