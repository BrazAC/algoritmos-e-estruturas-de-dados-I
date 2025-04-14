#ifndef __FUNCOES_H__
#define __FUNCOES_H__

//Constantes
#define MAX_CHAR_COUNTRY 100

//======================================================-Lista encadeada
typedef struct est_no_lista{
    struct est_no_lista *prox;

    //Dados para criterio de selecao
    unsigned int confirmados;
    unsigned int mortes;
    unsigned int recuperados;

    //Dados gerais
    char pais[MAX_CHAR_COUNTRY];
    unsigned int mortes100;
    unsigned int recuperados100; 

} tipo_no_lista;

/**
 * @brief Aloca novo no na memoria
 * @param novoNoh Endereco do ponteiro da lista
 * @return Endereco do no alocado se sucesso, NULL se alocacao falhar
 */
tipo_no_lista* alocaNo(tipo_no_lista novoNoh);

/**
 * @brief Insere noh na lista encadeada
 * @param lista Endereco do ponteiro da lista
 * @param dado Noh a ser inserido
 * @return 0 se sucesso, -1 se alocacao falhar
 */
int lista_insereInicio(tipo_no_lista **lista, tipo_no_lista novoNoh);

/**
 * @brief Remove noh da lista encadeada
 * @param lista Endereco do ponteiro da lista
 * 
 * @return noh removido ou noh "vazio" se a lista estiver vazia
 */
tipo_no_lista lista_removeInicio(tipo_no_lista **lista);

//======================================================-Heap
/**
 * @brief Remove e mostra X's elementos da raiz do heap 
 * @param heap Heap a ser realizada a remocao  
 * @param quant Quantidade de nos a serem exibidos
 * @param criterio Criterio selecionado para chave do heap, 'c' confirmados, 'm' mortes, 'r' recuperados 
 */
void heap_removeEmostraX(tipo_heap heap, int quant, char criterio);



#endif