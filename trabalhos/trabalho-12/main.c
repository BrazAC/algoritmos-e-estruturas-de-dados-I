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
    //ab_mostraArvore(arv_produtos);

    //===============================================| Menu
    int op, id_categoria;
    char criterio;
    do {
        printf("\n");
        printf("---------------------------------------------------------\n");
        printf("=========================|MENU|==========================\n");
        printf("---------------------------------------------------------\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Listar os produtos com preços entre valores de x e y\n");
        printf("2 - Listar produtos de uma categoria\n");
        printf("3 - Listar os 5 produtos mais caros por categoria;\n");
        printf("4 - Listar os 5 produtos mais baratos por categoria;\n");
        printf("5 - Identificar categoria de um produto\n");
        printf("0 - Encerrar programa\n");
        printf("=> ");
        scanf("%d", &op);

        if (op == 1) {
            break;
        }
        else if(op == 2){
            printf("\n");
            printf("---------------------------------------------------------\n");
            printf("Insira o ID da categoria");
            printf("=> ");
            scanf("%d", &id_categoria);

            //Buscar categoria com o id desejado na arvore n-aria
            tipo_categoria* categoriaEncontrada = am_buscaCategoria(arv_categorias, id_categoria);
            if(categoriaEncontrada == NULL){
                printf("[ERRO] ID de categoria nao cadastrado\n");
            }else{
                printf("[%5d|%50s|%5d|%d]\n", categoriaEncontrada->id, categoriaEncontrada->nome, categoriaEncontrada->id_pai, categoriaEncontrada->possuiSubArvoreBin);
                //Criar se ainda nao foi criada a sub-arvore de produtos
                ab_carregaSubArvoreBin(categoriaEncontrada, arv_produtos);
                //Exibir produtos da sub-arvore
                ab_mostraArvore(categoriaEncontrada->sub_arv_bin);
            }
            
            printf("\nVoltar ao menu para verificar outro tipo de informacao?\n");
            printf("1 - Sim\n");
            printf("0 - Nao (Encerrar programa)\n");
            printf("=> ");
            scanf("%d", &op);
        }
        else if(op == 3){ //FALTA
            //Carregar todas as subarvores
            am_carregaTodasSubarvores(arv_categorias, arv_produtos);
            //Listar 5 produtos mais caros de cada subarvore
            

            printf("\nVoltar ao menu para verificar outro tipo de informacao?\n");
            printf("1 - Sim\n");
            printf("0 - Nao (Encerrar programa)\n");
            printf("=> ");
            scanf("%d", &op);
        }
        else if(op == 4){ //FALTA
            //Carregar todas as subarvores
            am_carregaTodasSubarvores(arv_categorias, arv_produtos);
            //Listar 5 produtos mais baratos de cada subarvore
            

            printf("\nVoltar ao menu para verificar outro tipo de informacao?\n");
            printf("1 - Sim\n");
            printf("0 - Nao (Encerrar programa)\n");
            printf("=> ");
            scanf("%d", &op);
        }
        else if(op == 5){ //FALTA
            char codigoProduto[MAX_CODIGO];
            printf("\n");
            printf("---------------------------------------------------------\n");
            printf("Insira o codigo do produto");
            printf("=> ");
            scanf("%s", codigoProduto);

            tipo_noh_ab* produto = ab_buscaProduto(arv_produtos, codigoProduto);
            tipo_categoria* categoriaEncontrada = am_buscaCategoria(arv_categorias, produto->categoria);
            printf("[%5d|%50s|%5d|%d]\n", categoriaEncontrada->id, categoriaEncontrada->nome, categoriaEncontrada->id_pai, categoriaEncontrada->possuiSubArvoreBin);
        }
        else if(op == 0){
            break;
        }
        else{
            printf("[ERRO] Insira uma opcao valida!\n");
        }
    }while(op);

    return 0;
}