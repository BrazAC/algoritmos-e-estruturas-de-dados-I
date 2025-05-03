#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"
#include <time.h>

int main(){
    //===============================================| Inicializacao das arvores
    tipo_noh_am *arv_categorias = NULL;
    tipo_noh_ab *arv_produtos = NULL;

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
    am_mostraNivel(arv_categorias, 0);
    am_mostraNivel(arv_categorias, 1);
    //===============================================| Carregar produtos
    //Abrir arquivo
    FILE *fproducts = fopen("./amazon_products.csv", "r");
    if(fproducts == NULL){
        printf("[ERRO] fopen amazon_products.csv retornou null");
        return 0;
    }
    //Extrair dados
    clock_t inicio, fim;
    double tempo_gasto;
    inicio = clock();
    main_carregaProdutos(fproducts, &arv_produtos);
    fim = clock();
    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo gasto carregamento arvore binaria: %f segundos\n", tempo_gasto);
    //Fechar arquivo
    fclose(fproducts);

    //===============================================| Menu
    

    return 0;
}