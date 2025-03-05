#ifndef __FUNCOES_ESTRUTS_DIN_H__
#define __FUNCOES_ESTRUTS_DIN_H__

typedef struct est_pedido{
    int numero;
    char cliente[51];
    char itens[101];
    char status[20];
    struct est_pedido *prox;
} est_pedido;

typedef struct est_fila{
    est_pedido *pedido;
    struct est_fila *prox;
} est_fila;

typedef struct est_pilha{
    est_pedido *pedido;
    struct est_pilha *prox;
} est_pilha;

//==FUNCOES LISTA
/**
 * @brief Aloca novo pedido na memoria
 * 
 * @param numero Numero do pedido
 * @param cliente Nome do cliente
 * @param itens Itens do pedido
 * @param status Status do pedido
 * 
 * @return Retorna o endereco do pedido alocado ou NULL se alocacao falhar
 */
est_pedido* alocaPedido(int, char*, char*);

/**
 * @brief Adiciona pedido ao final da lista de pedidos com status de pendente
 * 
 * @param endereco Endereco do ponteiro do primeiro elemento da lista
 * @param numero Numero do pedido
 * @param cliente Nome do cliente
 * @param itens Itens do pedido
 *  
 * @return 0 se sucesso -1 se a alocacao para insercao falhar
 */
int armazenaPedidoLista(est_pedido**, int, char*, char*);

/**
  * @brief Retorna endereco de pedido de acordo com o numero passado
  * 
  * @param endereco Endereco do ponteiro do primeiro elemento da lista
  * @param numero Numero do pedido
  * 
  * @return Endereco do pedido ou NULL se o pedido nao for encontrado
  */
est_pedido* encontraPedido(est_pedido**, int);

/**
 * @brief Mostra os pedidos cadastrados na lista
 * 
 * @param endereco Endereco do primeiro elemento da lista
 * 
 * @return -1 se a lista estiver vazia
 */
int mostraPedidosLista(est_pedido**);

//==FUNCOES FILA
/**
 * @brief Aloca novo noh para fila
 * @param novoPedido Endereco do pedido a ser cadastrado no noh
 * 
 * @return Endereco do novo no alocado ou NULL se a alocacao falhar
 */
est_fila* alocaFila(est_pedido*);

/**
 * @brief Adiciona pedido a lista de preparo caso ele exista na fila e esteja com status pendente
 * 
 * @param endereco Endereco do ponteiro do primeiro elemento da fila
 * @param enderecoLista Endereco do ponteiro do primeiro elemento da lista
 * @param numero Numero do pedido a ser adicionado a fila
 * 
 * @return 0 se sucesso, -1 se o pedido nao existe, -2 se o status do pedido nao e pendente
 */
int armazenaPedidoFila(est_fila**, est_pedido**,int);

/**
 * @brief Mostra pedidos em preparo, cadastrados na fila
 * 
 * @param endereco Endereco do ponteiro do primeiro elemento da fila
 * 
 * @return -1 se a fila estiver vazia
 */
int mostraPedidosFila(est_fila**);

/**
 * @brief Remove o primeiro elemento da fila
 * 
 * @param endereco Endereco do ponteiro do primeiro elemento da fila
 * 
 * @return O primeiro elemento da fila ou NULL se ela estiver vazia
 */
est_pedido* removePedidoFila(est_fila**);

//==FUNCOES PILHA
/**
 * @brief Aloca novo noh para pilha
 * @param novoPedido Endereco do pedido a ser cadastrado no noh
 * 
 * @return Endereco do novo no alocado ou NULL se a alocacao falhar
 */
est_pilha* alocaPilha(est_pedido*);

/**
 * @brief Adiciona pedido a pilha de pedidos prontos, retira da fila de pedidos em preparo
 * 
 * @param enderecoPilha Endereco do ponteiro do primeiro elemento da pilha
 * @param enderecoFila Endereco do ponteiro do primeiro elemento da fila
 * 
 * @return 0 se sucesso, -1 se a fila de pedidos em preparo estiver vazia, -2 se a alocacao falhar
 */
int armazenaPedidoPilha(est_pilha**, est_fila**);

/**
 * @brief Remove pedido da pilha e atualiza status para "entregue"
 * 
 * @param endereco Endereco do ponteiro do ultimo elemento da pilha
 * @param enderecoLista Endereco do ponteiro do primeiro elemento da lista
 * 
 * @return O endereco do pedido removido ou NULL se a pilha estiver vazia
 * 
 */
est_pedido* removePedidoPilha(est_pilha**, est_pedido**);

/**
 * @brief Mostra pedidos em preparo, cadastrados na pilha
 * 
 * @param endereco Endereco do ponteiro do primeiro elemento da pilha
 * 
 * @return -1 se a pilha estiver vazia
 */
int mostraPedidosPilha(est_pilha**);

#endif