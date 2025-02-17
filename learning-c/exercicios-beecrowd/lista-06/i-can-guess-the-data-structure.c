#include <stdlib.h>
#include <stdio.h>

//Struct no
typedef struct tipo_no{
    int dado;
    struct tipo_no *proximo;
} tipo_no;

//Funcao para criar no
tipo_no* criaNo(int novoDado);
//Funcoes fila
void filaDin_insere(tipo_no**, int);
int filaDin_remove(tipo_no**);
int filaDin_mostra(tipo_no**);
//Funcoes pilha
void pilhaDin_insere(tipo_no**, int);
int pilhaDin_remove(tipo_no**);
int pilhaDin_mostra(tipo_no**);
void filaDinPrior_insere(tipo_no**, int);

int main(){
    int op, val, valRetirado, quantAcoes, jaTeveSaida = 0;
    //Criando estruturas
    tipo_no* prtBaseFila = NULL;
    tipo_no* prtBaseFilaOrd = NULL;
    tipo_no* prtBasePilha = NULL;

    //Obter quantidade de acoes, enquanto nao retorar EOF
    while (scanf("%d", &quantAcoes) != EOF) {
        printf("Iniciando novo for\n");
        for(int i = 0; i < quantAcoes; i++){
            //Obter op e val
            scanf("%d %d", &op, &val);

            if (jaTeveSaida == 0){
                if (op == 1) {
                    //Inserir val na pilha, fila e filaPrioriade
                    pilhaDin_insere(&prtBasePilha, val);
                    filaDin_insere(&prtBaseFila, val);
                    filaDinPrior_insere(&prtBaseFilaOrd, val);
                }
                else{
                    jaTeveSaida = 1;
                    int cont = 0, result;
                    //retirar valor de pilha
                    valRetirado = pilhaDin_remove(&prtBasePilha);
                    //valor retirado == val?
                    //Se Sim
                    if (valRetirado == val) {
                        //E pilha
                        result = 1;
                        cont ++;
                    }
                    //Se nao
                    else{
                        //Retirar valor de fila
                        valRetirado = filaDin_remove(&prtBaseFila);
                        //valor retirado == val?
                        //Se sim
                        if (valRetirado == val) {
                            //E fila
                            result = 2;
                            cont ++;
                        }
                        //Se nao
                        else{
                            //Retirar valor de fila prioridade
                            valRetirado = filaDin_remove(&prtBaseFilaOrd);
                            //Valor retirado == val?
                            //Se sim
                            if (valRetirado == val) {
                                //E filaPrioridade
                                result = 3;
                                cont ++;
                            }
                            //Se nao
                            else{
                                //E impossivel 
                                printf("impossible\n");
                            }
                        }
                    }
                    if (cont > 1){
                        printf("not sure\n");
                    }else{
                        if (result == 1) {
                            printf("stack\n");
                        }
                        else if(result == 2){
                            printf("queue\n");
                        }else{
                            printf("priority queue\n");
                        }
                    }
                }
            }
        }
    }

    return 0;
}

tipo_no* criaNo(int novoDado){
    tipo_no *novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    novoNo->dado = novoDado;
    (*novoNo).proximo = NULL;
    return novoNo;
}

void pilhaDin_insere(tipo_no** prtBase, int novoDado){
    if ((*prtBase) == NULL) {
        //Criar novo no com valor desejado
        //Atualizar o prtBase
        tipo_no *novoNo = criaNo(novoDado);
        *prtBase = novoNo;
    }
    else{
        //Inserindo elementos no comeco da pilha (tirar do comeco tambem)
        tipo_no *aux, *novoNo;
        novoNo = criaNo(novoDado);
        aux = (*prtBase);
        *prtBase = novoNo;
        (*prtBase)->proximo = aux;
    }
}

int pilhaDin_remove(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        printf("[ERRO] Tentando remover de pilha vazia");
        return -1;
    }

    tipo_no *aux = *prtBase;
    int dadoRm = (*prtBase)->dado;
    *prtBase = (*prtBase)->proximo;
    free(aux);
    return dadoRm;
}

int pilhaDin_mostra(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        printf("[AVISO] Tentando mostrar pilha vazia!\n");
        return -1;
    }

    tipo_no *aux = (*prtBase);
    while(aux->proximo != NULL){
        printf("[%d]", aux->dado);
        aux =  aux->proximo;
    }
    printf("[%d]\n", aux->dado);
    return 0;
}

void filaDin_insere(tipo_no** prtBase, int novoDado){
    if ((*prtBase) == NULL) {
        (*prtBase) = criaNo(novoDado);
    }
    else{
        tipo_no *aux;
        aux = (*prtBase);
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = criaNo(novoDado); 
    }
}

void filaDinPrior_insere(tipo_no** prtBase, int novoDado){
    if ((*prtBase) == NULL) {
        (*prtBase) = criaNo(novoDado);
    }
    else{
        //Inserir o elemento no comeco da fila
        tipo_no *aux;
        aux = (*prtBase);
        while(aux->proximo != NULL){
            aux = aux->proximo;
        }
        aux->proximo = criaNo(novoDado); 

        //Ordenar fila, maior -> menor
        int trocou;
        tipo_no *atual;
        tipo_no *ultimo = NULL; //Marca o ultimo nó que já está ordenado

        do {
            trocou = 0;
            atual = *prtBase;

            while (atual->proximo != ultimo) {
                if (atual->dado < atual->proximo->dado) {
                    //Troca os valores ao inves de mudar os ponteiros
                    int temp = atual->dado;
                    atual->dado = atual->proximo->dado;
                    atual->proximo->dado = temp;

                    trocou = 1; //Marca que houve troca
                }
                atual = atual->proximo;
            }
            //O ultimo no ja esta no lugar certo, então atualizar a marcação
            ultimo = atual;

        } while (trocou);
    }
}


int filaDin_remove(tipo_no** prtBase){
    //Verificar se a estrutura esta vazia
    if ((*prtBase) == NULL) {
        printf("[ERRO] Tentando remover de fila vazia\n");    
        return -1;
    }

    //Separar dados do primeiro elemento
    tipo_no *aux = (*prtBase);
    int dadoRm = (*prtBase)->dado;
    //Atualizar prtBase
    *prtBase = (*prtBase)->proximo;
    //Liberar antigo primeiro elemento
    free(aux);
    //Return dado removido
    return dadoRm;
}

int filaDin_mostra(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        printf("[ERRO] Tentando mostrar fila vazia");
        return -1;
    }

    tipo_no *aux = (*prtBase);
    printf("\n");
    while(aux->proximo != NULL){
        printf("[%d]", aux->dado);
        aux = aux->proximo;
    }
    printf("[%d]", aux->dado);
    printf("\n");
}