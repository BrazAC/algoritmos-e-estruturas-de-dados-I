#include <stdlib.h>
#include <stdio.h>

#define MAX 1001

//Struct no
typedef struct tipo_fila{
    int contador;
    int filaInt[MAX];
} tipo_fila;

typedef struct tipo_pilha{
    int contador;
    int pilhaInt[MAX];
} tipo_pilha;

typedef struct tipo_lista{
    int contador;
    int listaInt[MAX];
} tipo_lista;

//Funcoes fila
void fila_insere(tipo_fila*, int);
int fila_remove(tipo_fila*);
void fila_mostra(tipo_fila*);
//Funcoes pilha
void pilha_insere(tipo_pilha*, int);
int pilha_remove(tipo_pilha*);
void pilha_mostra(tipo_pilha*);

void lista_insere(tipo_lista*, int);
void listaMostra(tipo_lista*);
int lista_remove(tipo_lista*);

int main(){
    int op, val, valRetirado, quantAcoes, eFila, ePilha, eListaOrdenada, eImpossivel;

    //Obter quantidade de acoes, enquanto nao retorar EOF
    while (scanf("%d", &quantAcoes) != EOF) {
        //Criando estruturas de ate 1001 espacos
        tipo_fila fila;
        fila.contador = 0;
        tipo_pilha pilha;
        pilha.contador = 0;
        tipo_lista lista;
        lista.contador = 0;

        //Zerando vars de controle
        eFila = 0; ePilha = 0; eListaOrdenada = 0, eImpossivel = 0;

        //printf("Iniciando novo for\n");
        for(int i = 0; i < quantAcoes; i++){
            //Obter op e val
            scanf("%d %d", &op, &val);

            if (op == 1){
            //Inserir val na pilha, fila e filaPrioriade
            pilha_insere(&pilha, val);
            fila_insere(&fila, val);
            lista_insere(&lista, val);
            }
            else{
                if(eFila + eListaOrdenada + eImpossivel == 0){
                    //retirar valor de pilha
                    //valor retirado == val?
                    valRetirado = pilha_remove(&pilha);
                    //printf("Removeu da pilha: %d\n", valRetirado);
                    if(valRetirado == val){
                    //Se Sim
                        //E pilha
                        ePilha = 1;
                    }
                }
                if(ePilha + eListaOrdenada + eImpossivel == 0){
                //Se nao
                    //Retirar valor de fila
                    //valor retirado == val?
                    valRetirado = fila_remove(&fila);
                    //printf("Removeu da fila: %d\n", valRetirado);
                    if (valRetirado == val) {
                    //Se sim
                        //E fila
                        eFila = 1;
                    }
                }
                if(eFila + ePilha + eImpossivel == 0){
                    //Se nao
                    //Retirar valor de fila prioridade
                    //Valor retirado == val?
                    valRetirado = lista_remove(&lista);
                    //printf("Removeu da lista: %d\n", valRetirado);
                    if(valRetirado == val){
                    //Se sim
                        //E filaPrioridade
                        eListaOrdenada = 1;
                    }
                }
                if (eFila + ePilha + eListaOrdenada == 0) {
                    eImpossivel = 1;
                }
                
            }//Fim else (op == 1)
        }//Fim for

        //Determinar que estrutura
        if ((eFila + ePilha + eListaOrdenada + eImpossivel) > 1) {
            printf("not sure\n");
        }
        else{
            if(eFila){
                printf("queue\n");
            }else if(ePilha){
                printf("stack\n");
            }else if(eListaOrdenada){
                printf("priority queue \n");
            }else if (eImpossivel) {
                printf("impossible\n");
            }
        }
    }//Fim while
    
    return 0;
}           

void fila_insere(tipo_fila* fila, int novoDado){
    if (fila->contador == MAX) {
        printf("[ERRO] Tentando inserir em fila cheia\n");
        return;
    }
    fila->filaInt[fila->contador] = novoDado;
    fila->contador ++;
}

int fila_remove(tipo_fila* fila){
    if (fila->contador == 0) {
        printf("[ERRO] Tentando remover de fila vazia");
        return -1;
    }

    fila->contador --;
    int temp = fila->filaInt[0];
    for (int i = 0; i < fila->contador; i++) {
        fila->filaInt[i] = fila->filaInt[i + 1];
    }
    return temp;
}

void fila_mostra(tipo_fila* fila){
    if (fila->contador == 0) {
        printf("[WARNING] Tentando mostrar fila vazia\n");
        return;
    }

    for (int i = 0; i < fila->contador - 1; i++) {
        printf("[%d]", fila->filaInt[i]);
    }
    printf("\n");
}

void pilha_insere(tipo_pilha* pilha, int novoDado){
    if (pilha->contador == MAX) {
        printf("[ERRO] Tentando inserir em pilha cheia\n");
        return;
    }
    pilha->pilhaInt[pilha->contador] = novoDado;
    pilha->contador ++;
}

int pilha_remove(tipo_pilha* pilha){
    if (pilha->contador == 0) {
        printf("[ERRO] Tentando remover de pilha vazia");
        return -1;
    }

    pilha->contador --;
    return pilha->pilhaInt[pilha->contador];
}

void pilha_mostra(tipo_pilha* pilha){
    if (pilha->contador == 0) {
        printf("[WARNING] Tentando mostrar pilha vazia\n");
        return;
    }

    for (int i = 0; i < pilha->contador - 1; i++) {
        printf("[%d]", pilha->pilhaInt[i]);
    }
    printf("\n");
}

void lista_insere(tipo_lista* lista, int novoDado){
    if (lista->contador == MAX) {
        printf("[ERRO] Tentando inserir em lista cheia\n");
        return;
    }

    //SE a lista estiver vazia
    if (lista->contador == 0) {
        lista->listaInt[0] = novoDado;
    } 
    else {
        //Identificar a posição correta para inserir novoDado
        int i;
        for (i = 0; i < lista->contador; i++) {
            if (lista->listaInt[i] <= novoDado) break;
        }
        
        //Mover elementos para a direita para abrir espaço
        for (int j = lista->contador; j > i; j--) {
            lista->listaInt[j] = lista->listaInt[j - 1];  
        }
        
        //Inserir número na posição correta
        lista->listaInt[i] = novoDado;
    }

    lista->contador++;
}

int lista_remove(tipo_lista* lista){
    if (lista->contador == 0) {
        printf("[ERRO] Tentando remover de lista vazia");
        return -1;
    }

    lista->contador --;
    int temp = lista->listaInt[0];
    for (int i = 0; i < lista->contador; i++) {
        lista->listaInt[i] = lista->listaInt[i + 1];
    }
    return temp;
}

void listaMostra(tipo_lista* lista){
    if (lista->contador == 0) {
        printf("[WARNING] Tentando mostrar lista vazia\n");
        return;
    }

    for (int i = 0; i < lista->contador; i++) {
        printf("[%d]", lista->listaInt[i]);
    }
    printf("\n");
}