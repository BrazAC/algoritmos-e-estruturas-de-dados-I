#include <stdlib.h>
#include <stdio.h>

/*
N = 1
(N,0)
M
dist = 2 * i - 1

Operacoes:
N = N + (2 * i - 1)
N = N - (2 * i - 1)

A cada geração de tuplas:
Se um dos N's calculados >= margem direita || N calculado <= margem esquerda, descartar o tal N (nao inserir na lista)
Se ambos N's calculados >= margem direita || ambos N's calculado <= margem esquerda, encerrar programa com falso
Quando encontrar um N == M, encerrar programa com verdadeiro
*/

typedef struct tipo_filaVets{
    int** filaVets;
    int contador;
    int capacidade;

} tipo_filaVets;

void fila_insere(tipo_filaVets *, int *);
int* fila_remove(tipo_filaVets *);
void fila_mostra(tipo_filaVets);

int main(){
    //Inicializar fila
    tipo_filaVets filaBFS;
    filaBFS.contador = 0;
    filaBFS.capacidade = 20;
    filaBFS.filaVets = (int**)malloc(sizeof(int*) * filaBFS.capacidade);

    //Obter dados
    int totalPedras, posPresente, totalPulos = 1, posicao = 1, repetir = 1;
    scanf("%d %d", &totalPedras, &posPresente);

    //Se o presente estiver na pedra 1 encerrar programa
    if (posPresente == 1) {
        repetir = 0;
        printf("Let me try!\n");
    }
    
    //Cadastrar tupla inicial
    int tuplaInicial[2] = {posicao, totalPulos};
    fila_insere(&filaBFS, tuplaInicial);

    //Logica - BFS Busca em largura
    while(repetir){
        //Remover o primeiro elemento de filaBFS
        int* primeiraTupla = fila_remove(&filaBFS);

        //Incrementar totalPulos
        totalPulos++;

        //Realizar calculos, armazenar nas tuplas
        //N = N + (2 * i - 1)
        int* tuplaOp1 = (int*)malloc(sizeof(int) * 2);
        tuplaOp1[0] = posicao + (2 * totalPulos - 1);
        tuplaOp1[1] = totalPulos;
        //N = N - (2 * i - 1)
        int* tuplaOp2 = (int*)malloc(sizeof(int) * 2);
        tuplaOp2[0] = posicao - (2 * totalPulos - 1);
        tuplaOp2[1] = totalPulos;

        //Avaliar resultados, determinar se o programa continua ou encerra
        if (tuplaOp1[0] <= 0 && tuplaOp2[0] <= 0) {
            printf("Don't make fun of me!\n");
            break;
        }
        if (tuplaOp1[0] >= (totalPedras + 1) && tuplaOp2[0] >= (totalPedras + 1)) {
            printf("Don't make fun of me!\n");
            break;
        }
        if (tuplaOp1[0] == posPresente || tuplaOp1[0] == posPresente) {
            printf("Let me try! \n");
            break;
        }

        //Determinar quais calculos podem entrar no filaBFS
        int podeEntrar1 = 1, podeEntrar2 = 1;
        if (tuplaOp1[0] <= 0 || tuplaOp1[0] >= (totalPedras + 1)) {
            podeEntrar1 = 0;
        }
        if (tuplaOp2[0] <= 0 || tuplaOp2[0] >= (totalPedras + 1)) {
            podeEntrar2 = 0;
        }

        //Inserir tuplas em filaBFS
        if (podeEntrar1) {
            fila_insere(&filaBFS, tuplaOp1);
        }
        if (podeEntrar2) {
            fila_insere(&filaBFS, tuplaOp2);
        }
    }

    return 0;
}

void fila_insere(tipo_filaVets* fila, int* novoVet){
    //Logica pra so usar realloc apenas quando uma certa capacidade for alcancada
    //Se alcancar a capacidade maxima
    if (fila->capacidade == fila->contador) {
        //Duplicar a capacidade
        fila->capacidade *= 2;
        //Realocar memoria para nova capacidade
        fila->filaVets = (int**)realloc(fila->filaVets, sizeof(int*) * fila->capacidade); 
    }
    
    //Se estiver dentro da capacidade
    fila->filaVets[fila->contador] = novoVet;
    fila->contador ++;
}

int* fila_remove(tipo_filaVets* fila){
    int* vetRemovido = fila->filaVets[0];
    
    fila->contador --;

    for (int i = 0; i < fila->contador; i++) {
        fila->filaVets[i] = fila->filaVets[i + 1];
    }

    //fila->filaVets = (int**)realloc(fila->filaVets, sizeof(int*) * fila->contador);

    return vetRemovido;
}

void fila_mostra(tipo_filaVets fila){
    for (int i = 0; i < fila.contador; i++) {
        if (i == 0) {
            printf("(%d, %d)", fila.filaVets[i][0], fila.filaVets[i][1]);
        }
        else if(i == fila.contador - 1){
            printf(" (%d, %d)\n", fila.filaVets[i][0], fila.filaVets[i][1]);
        }
        else{
            printf(" (%d, %d)", fila.filaVets[i][0], fila.filaVets[i][1]);
        }
    }
}