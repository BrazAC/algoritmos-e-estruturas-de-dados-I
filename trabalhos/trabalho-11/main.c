#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main(){
    //====Criar estruturas
    tipo_no_lista *listaPrincipal = NULL;
    tipo_heap heapPrincipal;
    heapPrincipal.cont = 0;

    //====Extrair dados do arquivo e carregar na lista dinamica
    //Abrir arquivo
    FILE *arquivo = fopen("./country_wise_latest.xls", "r");

    //Verificar se o programa conseguiu abriu o arquivo
    if(arquivo == NULL){
        printf("[ERRO] fopen() retornou NULL\n");
        return 0;
    }

    //Carregar dados na lista
    main_carregaLista(arquivo, &listaPrincipal);

    //Fechar arquivo
    fclose(arquivo);

    //====Menu
    int op, quantDados;
    char criterio;
    do {
        printf("\n");
        printf("---------------------------------------------------------\n");
        printf("=========================|MENU|==========================\n");
        printf("---------------------------------------------------------\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Escolher criterio de visualizacao\n");
        printf("0 - Encerrar programa\n");
        printf("=> ");
        scanf("%d", &op);

        if (op == 1) {
            printf("\n");
            printf("Escolha um criteio:\n");
            printf("c - Numero de casos de Covid-19\n");
            printf("m - Numero de mortes por Covid-19\n");
            printf("r - Nmero de pessoas recuperadas da Covid-19\n");
            printf("x - Voltar ao menu\n");
            printf("=> ");
            scanf(" %c", &criterio);

            if(criterio == 'c' || criterio == 'm' || criterio == 'r'){
                printf("Informe a quantidade de dados para visualizar:\n");
                printf("=> ");
                scanf(" %d", &quantDados);

                //Carregar dados no heap
                main_carregaHeap(&heapPrincipal, listaPrincipal, criterio);

                //Remover e mostrar a quantidade informada
                heap_removeEmostraX(&heapPrincipal, quantDados);

                //Esvaziar heap para a possivel proxima leitura
                heapPrincipal.cont = 0;

                //Perguntar se quer voltar ao menu
                printf("\nVoltar ao menu para verificar outro tipo de informacao?\n");
                printf("1 - Sim\n");
                printf("0 - Nao (Encerrar programa)\n");
                printf("=> ");
                scanf("%d", &op);

            }else if(criterio == 'x'){
                printf("\n");
            }
            else{
                printf("[ERRO] Informe um criterio valido!\n");
            }
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