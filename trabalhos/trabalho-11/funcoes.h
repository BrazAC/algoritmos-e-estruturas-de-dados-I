#ifndef __FUNCOES_H__
#define __FUNCOES_H__

//Constantes
#define MAX_CHAR_COUNTRY 100
#define MAX_HEAP 187

//======================================================-Lista encadeada
typedef struct est_no_lista{
    struct est_no_lista *prox;

    //Dados para criterio de selecao
    unsigned int confirmados;
    unsigned int mortes;
    unsigned int recuperados;

    //Dados gerais
    char pais[MAX_CHAR_COUNTRY];
    float mortes100;
    float recuperados100; 

} tipo_no_lista;

/**
 * @brief Aloca novo no na memoria
 * @param nohAux Endereco do ponteiro da lista
 * @return Endereco do no alocado se sucesso, NULL se alocacao falhar
 */
tipo_no_lista* alocaNo(tipo_no_lista nohAux);

/**
 * @brief Insere noh na lista encadeada
 * @param lista Endereco do ponteiro da lista
 * @param nohAux Noh auxiliar com os dados para inserscao
 * @return 0 se sucesso, -1 se alocacao falhar
 */
int lista_insereInicio(tipo_no_lista **lista, tipo_no_lista nohAux);

/**
 * @brief Remove noh da lista encadeada
 * @param lista Endereco do ponteiro da lista
 * 
 * @return noh removido ou noh "vazio" se a lista estiver vazia
 */
tipo_no_lista lista_removeInicio(tipo_no_lista **lista);

/**
 * @brief Mostra elemento da lista
 * @param lista Ponteiro da lista  
 */
void lista_mostra(tipo_no_lista *lista);
//======================================================-Heap Maximo
typedef struct est_dado_heap{
    //Chave
    unsigned int chave;

    //Dados para criterio de selecao
    unsigned int confirmados;
    unsigned int mortes;
    unsigned int recuperados;

    //Dados gerais
    char pais[MAX_CHAR_COUNTRY];
    float mortes100;
    float recuperados100; 
} tipo_dado_heap;

typedef struct est_heap{
    char criterioChave;
    tipo_dado_heap heap[MAX_HEAP];
    int cont;
} tipo_heap;

/**
 * @brief Insere um elemento no heap a partir de um no vindo de uma lista escolhendo o criterio de selecao de chave
 * @param heap Endereco do heap para insersao do dado
 * @param novoDado Noh da lista com os dados
 * @param criterio Criterio para definir qual chave sera usada, 'c' confirmados, 'm' mortes, 'r' recuperados 
 * @return -1 se o heap estiver cheio, 0 se sucesso
 */
int heap_inserePorCriterio(tipo_heap *heap, tipo_no_lista novoNohDado, char criterio);
void heap_sobeHeap(tipo_heap *heap, int pos);

/**
 * @brief Remove e mostra X's elementos da raiz do heap 
 * @param heap Endereco do heap a ser realizada a remocao  
 * @param quant Quantidade de elementos a serem removidos e exibidos
 */
void heap_removeEmostraX(tipo_heap *heap, int quant);

/**
 * @brief Remove elemento da raiz heap passado
 * @param heap Endereco do heap para remocao
 * @return Elemento removido
 */
tipo_dado_heap heap_removeRaiz(tipo_heap *heap);
void heap_desceHeap(tipo_heap *heap, int pos);

//======================================================-Logica principal
/**
 * @brief Carrega todos os dados da lista no heap cadastrando a chave de acordo com o criterio escolhido
 * @param heap Endereco do heap
 * @param lista Endereco da lista
 * @param criterio Criterio para definir qual chave sera usada, 'c' confirmados, 'm' mortes, 'r' recuperados 
 */
void main_carregaHeap(tipo_heap *heap, tipo_no_lista *lista, char criterio);

/**
 * @brief Carrega todos os dados do arquivo na lista
 * @param arquivo Endereco do arquivo
 * @param lista Endereco do ponteiro da lista
 */
void main_carregaLista(FILE *arquivo, tipo_no_lista **lista);


#endif