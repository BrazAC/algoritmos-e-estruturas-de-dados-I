/*
Universidade Federal de Mato Grosso
Curso: Ciencia da computacao
Atividade: Trabalho - Aplicacao de listas, pilha e fila
Aluno: Braz Amorim Campos

"Changelog"
v0 - Tudo joia
v1 - Essa edicao do trabalho tem um menu (esqueci na primeira)
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes-estruts-din.h"

int main(){
    //Inicializando estr
    int op; 

    est_pedido *listaPedidos;
    listaPedidos = NULL;

    est_fila *filaPreparo;
    filaPreparo = NULL;

    est_pilha* pilhaPronto;
    pilhaPronto = NULL;
    
    system("clear");
    do
    {
        //Se a lista nao estiver vazia, mostrar pedidos acima do menu
        mostraPedidosLista(&listaPedidos);

        //Mostrar menu
        printf("========================================\n");
        printf("==========CONTROLE RESTAURANTE==========\n");
        printf("========================================\n");
        printf("1 - Cadastrar pedido\n");
        printf("2 - Começar a preparar um pedido\n");
        printf("3 - Marcar primeiro pedido da lista em preparo, como pronto\n");
        printf("4 - Marcar ultimo pedido da pilha de prontos, como entregue\n");
        printf("0 - Finalizar programa\n");
        printf("========================================\n");
        printf("-> ");
        scanf("%d", &op);
        //Limpar buffer (consumir '\n')
        getchar();

        //Limpar terminal
        system("clear");

        switch (op)
        {
        case 1:
            printf("========================================\n");
            printf("----------CADASTRO DE PEDIDO------------\n");
            printf("========================================\n");
            
            int numero; 
            char cliente[51];
            char itens[101];

            printf("INFORME:");
            printf("\n");
            printf("Numero: ");
            scanf("%d", &numero);
            getchar();

            printf("Cliente: ");
            fgets(cliente, 51, stdin);
            for(int i = 0; i < 51; i++){
                if (cliente[i] == '\n'){
                    cliente[i] = '\0';    
                    break;
                }
            }
            
            printf("Itens: ");
            fgets(itens, 101, stdin);
            for(int i = 0; i < 101; i++){
                if (itens[i] == '\n'){
                    itens[i] = '\0';    
                    break;
                }
            }

            //Inserir pedido na lista e retornar status
            printf("\n========================================\n");
            if(armazenaPedidoLista(&listaPedidos, numero, cliente, itens) == 0){
                printf("[SUCESSO] Pedido cadastrado!\n");
            }
            else{
                printf("[ERRO] Alocacao para insersao falhou!\n");
            }
            printf("\n");

            printf("Pressione Enter para continuar -> ");
            getchar();

            //Limpar terminal
            system("clear");

            break;
        case 2:
            //Se a lista nao estiver vazia, mostrar pedidos acima para referencia
            mostraPedidosLista(&listaPedidos);

            printf("========================================\n");
            printf("-------INICIAR PREPARO DE PEDIDO--------\n");
            printf("========================================\n");

            int numeroPedido; 

            printf("INFORME:\n");
            printf("Numero do pedido a ser preparado: ");
            scanf("%d", &numeroPedido);
            getchar();

            //Inserir (ou nao) pedido na fila e retornar status
            int status = armazenaPedidoFila(&filaPreparo, &listaPedidos, numeroPedido);

            printf("\n========================================\n");
            if(status== 0){
                printf("[SUCESSO] Comecou o preparo do pedido!\n");
            }
            else if(status == -1){
                printf("[ERRO] Nao existe pedido cadastrado com esse numero!\n");
            }
            else if(status == -2){
                printf("[ERRO] O status do pedido nao e pendente!\n");
            }
            printf("\n");

            printf("Pressione Enter para continuar -> ");
            getchar();

            system("clear");
        
            break;
        case 3:
            //Se a lista nao estiver vazia, mostrar pedidos acima para referencia
            mostraPedidosLista(&listaPedidos);

            //Inserir (ou nao) pedido na pilha e retornar status
            int status1 = armazenaPedidoPilha(&pilhaPronto, &filaPreparo);

            printf("\n========================================\n");
            if(status1== 0){
                printf("[SUCESSO] Pedido marcado como pronto!\n");
            }
            else if(status1 == -1){
                printf("[ERRO] Nao existem pedidos em preparo!\n");
            }
            else if(status1 == -2){
                printf("[ERRO] Alocaco para insercao na pilha falhou!\n");
            }
            printf("\n");

            printf("Pressione Enter para continuar -> ");
            getchar();

            system("clear");
            break;
        case 4:
            //Se a lista nao estiver vazia, mostrar pedidos acima para referencia
            mostraPedidosLista(&listaPedidos);

            //Remover (ou nao) pedido da pilha e retornar status
            est_pedido *status2 = removePedidoPilha(&pilhaPronto, &listaPedidos);

            printf("\n========================================\n");
            if(status2 != NULL){
                printf("[SUCESSO] Pedido entregue!\n");
            }
            else{
                printf("[ERRO] Nao existem pedidos prontos!\n");
            }
            printf("\n");

            printf("Pressione Enter para continuar -> ");
            getchar();

            system("clear");
            
            break;
        case 0:
            break;
        default:
            //Se a lista nao estiver vazia, mostrar pedidos acima para referencia
            mostraPedidosLista(&listaPedidos);

            printf("========================================\n");
            printf("[ERRO] Escolha uma opcao valida!\n");

            printf("Pressione Enter para continuar -> ");
            getchar();

            system("clear");
            break;
        }


    } while (op != 0);
    
    //Limpar terminal
    system("clear");

    printf("PROGRAMA ENCERRADO\n");



    /*
    est_pedido *listaPedidos;
    listaPedidos = NULL;

    est_fila *filaPreparo;
    filaPreparo = NULL;

    est_pilha* pilhaPronto;
    pilhaPronto = NULL;

    //Inserindo pedidos na lista
    armazenaPedidoLista(&listaPedidos, 123, "Jose", "Camarao e vinho");
    armazenaPedidoLista(&listaPedidos, 321, "Andre", "Bife e fritas");
    armazenaPedidoLista(&listaPedidos, 312, "Pedro ruim de date", "O mais barato");
    armazenaPedidoLista(&listaPedidos, 151, "Carlos", "gelo");

    mostraPedidosLista(&listaPedidos);

    //Inserindo na fila de preparacao
    armazenaPedidoFila(&filaPreparo, &listaPedidos, 123);
    armazenaPedidoFila(&filaPreparo, &listaPedidos, 321);
    
    mostraPedidosFila(&filaPreparo);

    //Movendo da fila de preparacao para pilha de prontos
    armazenaPedidoPilha(&pilhaPronto, &filaPreparo);

    mostraPedidosPilha(&pilhaPronto);

    //Mostrando lista de pedidos ao final
    //(Demonstrar que a lista foi sendo atualizada durante o processo)
    mostraPedidosLista(&listaPedidos);
    */
    
    return 0;
}