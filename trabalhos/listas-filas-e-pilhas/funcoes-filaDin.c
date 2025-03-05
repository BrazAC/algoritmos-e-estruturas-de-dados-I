#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes-estruts-din.h"

//==Funcoes lista
est_pedido* alocaPedido(int numero, char *cliente, char *itens){
    //Alocar pedido
    est_pedido *novoPedido = (est_pedido*)malloc(sizeof(est_pedido));
    if (novoPedido == NULL) {
        return NULL;
    }
    
    //Cadastrando numero
    novoPedido->numero = numero;

    //Cadastrando strings
    int pos = 0;
    while (cliente[pos] != '\0') {
        novoPedido->cliente[pos] = cliente[pos];
        pos ++;
    }
    novoPedido->cliente[pos] = '\0';

    pos = 0;
    while (itens[pos] != '\0') {
        novoPedido->itens[pos] = itens[pos];
        pos ++;
    }
    novoPedido->itens[pos] = '\0';

    strncpy(novoPedido->status, "pendente", sizeof(novoPedido->status) - 1);
    novoPedido->status[sizeof(novoPedido->status) - 1] = '\0';

    //Cadastro prox ponteiro
    novoPedido->prox = NULL;
    
    return novoPedido;
}

int armazenaPedidoLista(est_pedido **prt_base, int numero, char *cliente, char *itens){
    if (*prt_base == NULL) {
        *prt_base = alocaPedido(numero, cliente, itens);
        if (*prt_base == NULL) {return -1;}
        return 0;
    }

    est_pedido *aux = *prt_base;
    while(aux->prox != NULL){
        aux = aux->prox;
    } 

    aux->prox = alocaPedido(numero, cliente, itens);
    if (*prt_base == NULL) {return -1;}
    return 0;

}

est_pedido* encontraPedido(est_pedido** prt_base, int numero){
    if (*prt_base == NULL) {
        return NULL;
    }

    est_pedido *aux = *prt_base;
    while (aux->prox != NULL && aux->numero != numero) {
        aux = aux->prox;
    }

    if (aux->numero == numero) {
        //Pedido esta na lista
        return aux;
    }else{
        //Pedido nao esta na lista
        return NULL;
    }
}

int mostraPedidosLista(est_pedido** prt_base){
    if (*prt_base == NULL) {
        return -1;
    }

    printf("----LISTA DE PEDIDOS----\n");

    est_pedido *aux = *prt_base;
    while (aux->prox != NULL) {
        printf("Numero: %d\n", aux->numero);
        printf("Cliente: %s\n", aux->cliente);
        printf("Itens: %s\n", aux->itens);
        printf("Status: %s\n\n", aux->status);
        aux = aux->prox;
    }
    printf("Numero: %d\n", aux->numero);
    printf("Cliente: %s\n", aux->cliente);
    printf("Itens: %s\n", aux->itens);
    printf("Status: %s\n", aux->status);

    printf("------------------------\n");

}

//==Funcoes fila
est_fila* alocaFila(est_pedido* pedido){
    est_fila *novoNo = (est_fila*)malloc(sizeof(est_fila));
    if (novoNo == NULL){
        return NULL;
    }

    novoNo->pedido = pedido;
    novoNo->prox = NULL;
    return novoNo;
}

int armazenaPedidoFila(est_fila** prt_baseFila, est_pedido **prt_baseLista, int numero){
    if (*prt_baseFila == NULL) {
        //Obter endereco do pedido
        est_pedido *pedido = encontraPedido(prt_baseLista, numero);

        if(pedido == NULL){return -1;}
        if(strcmp(pedido->status, "pendente") != 0){return -2;}

        //Atualizar status para "em preparo"
        strncpy(pedido->status, "em preparo", sizeof(pedido->status) - 1);
        pedido->status[sizeof(pedido->status) - 1] = '\0';

        //Criar novo noh fila
        est_fila *novoNoFila = alocaFila(pedido);

        //Cadastro novo noh na fila
        *prt_baseFila = novoNoFila;
        return 0;
    }

    est_fila *aux = *prt_baseFila;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    est_pedido *pedido = encontraPedido(prt_baseLista, numero);

    if(pedido == NULL){return -1;}
    if(strcmp(pedido->status, "pendente") != 0){return -2;}

    //Atualizar status para "em preparo"
    strncpy(pedido->status, "em preparo", sizeof(pedido->status) - 1);
    pedido->status[sizeof(pedido->status) - 1] = '\0';

    est_fila *novoNoFila = alocaFila(pedido);

    aux->prox = novoNoFila;
    return 0;
}

int mostraPedidosFila(est_fila** prt_base){
    if (*prt_base == NULL) {
        return -1;
    }

    printf("----LISTA DE PEDIDOS EM PREPARO----\n");

    est_fila *aux = *prt_base;
    while (aux->prox != NULL) {
        printf("Numero: %d\n", aux->pedido->numero);
        printf("Cliente: %s\n", aux->pedido->cliente);
        printf("Itens: %s\n", aux->pedido->itens);
        printf("Status: %s\n\n", aux->pedido->status);
        aux = aux->prox;
    }
    printf("Numero: %d\n", aux->pedido->numero);
    printf("Cliente: %s\n", aux->pedido->cliente);
    printf("Itens: %s\n", aux->pedido->itens);
    printf("Status: %s\n\n", aux->pedido->status);

    printf("-----------------------------------\n");

}

est_pedido* removePedidoFila(est_fila** prt_base){
    if (*prt_base == NULL) {
        return NULL;
    }

    est_fila *aux = *prt_base;
    est_pedido *pedidoRm = aux->pedido;

    *prt_base = aux->prox;
    free(aux);

    return pedidoRm;
}

//==Funcoes pilha
est_pilha* alocaPilha(est_pedido* pedido){
    est_pilha *novoNo = (est_pilha*)malloc(sizeof(est_pilha));
    if(novoNo == NULL){
        printf("Alocacao falhou!");
        return NULL;
    }

    novoNo->prox = NULL;
    novoNo->pedido = pedido;
    return novoNo;
}

int armazenaPedidoPilha(est_pilha** prt_basePilha, est_fila** prt_baseFila){
    est_pedido *pedidoRm = removePedidoFila(prt_baseFila);
    if(pedidoRm == NULL){return -1;}
    
    strncpy(pedidoRm->status, "Pronto", sizeof(pedidoRm->status));
    pedidoRm->status[sizeof(pedidoRm->status) - 1] = '\0';

    if (*prt_basePilha == NULL) {
        est_pilha *novoNoPilha = alocaPilha(pedidoRm);
        if(novoNoPilha == NULL){
            printf("SEXO\n");
            return -2;}

        *prt_basePilha = novoNoPilha;
        return 0;
    }

    est_pilha *novoNoPilha = alocaPilha(pedidoRm);
    if(novoNoPilha == NULL){return -2;}

    est_pilha *aux = *prt_basePilha;

    *prt_basePilha = novoNoPilha;
    novoNoPilha->prox = aux;
    return 0;

}

est_pedido* removePedidoPilha(est_pilha** prt_base, est_pedido** prt_baseLista){
    if (*prt_base == NULL) {
        return NULL;
    }
    
    est_pilha *aux = *prt_base;
    est_pedido *pedidoRm = (*prt_base)->pedido;

    //Atualizar status do pedido na lista
    //encontraPedido(prt_baseLista, pedidoRm->numero)->status
    strncpy(pedidoRm->status, "Entregue", sizeof(pedidoRm->status));
    pedidoRm->status[sizeof(pedidoRm->status) - 1] = '\0';

    //Remover pedido da pilha
    *prt_base = aux->prox;
    free(aux);
    return pedidoRm;
}

int mostraPedidosPilha(est_pilha** prt_base){
    if(*prt_base == NULL){
        return -1;
    }

    printf("----LISTA DE PEDIDOS PRONTOS----\n");

    est_pilha *aux = *prt_base;
    while(aux->prox != NULL){
        printf("Numero: %d\n", aux->pedido->numero);
        printf("Cliente: %s\n", aux->pedido->cliente);
        printf("Itens: %s\n", aux->pedido->itens);
        printf("Status: %s\n\n", aux->pedido->status);
        aux = aux->prox;
    }
    printf("Numero: %d\n", aux->pedido->numero);
    printf("Cliente: %s\n", aux->pedido->cliente);
    printf("Itens: %s\n", aux->pedido->itens);
    printf("Status: %s\n\n", aux->pedido->status);

    printf("--------------------------------\n");
    return 0;
}

