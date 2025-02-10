#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//0.000200
typedef struct tipo_filaVets{
    int** filaVets;
    int contador;
    int capacidade;

} tipo_filaVets;

void fila_insere(tipo_filaVets *, int *);
int* fila_remove(tipo_filaVets *);
void fila_mostra(tipo_filaVets);

int main(){
    //TEMPO: Registra o tempo inicial
    clock_t inicio = clock();

    //Inicializando fila
    tipo_filaVets fila;
    fila.contador = 0;
    fila.capacidade = 20;
    fila.filaVets = (int**)malloc(sizeof(int*) * fila.capacidade);

    //Obtendo inteiros
    int numero, numeroAlvo, quantOps = 0, possiveisOps = 7;
    scanf("%d %d", &numero, &numeroAlvo);

    //Cadastrando primeira tupla
    int primeiraTupla[2] = {numero, quantOps};
    fila_insere(&fila, primeiraTupla);

    //Logica BFS - Busca em largura
    int continuar = 1;
    while (continuar) {
        //Remover primeira tupla da fila
        int* primeiraTuplaDaFila = fila_remove(&fila);

        //Separando info da primeiraTuplaDaFila
        int numero = primeiraTuplaDaFila[0];
        quantOps = primeiraTuplaDaFila[1];

        //Gerar possiveisOps tuplas e guardar na fila
        quantOps ++;
        //Calcular valores e gerar tuplas 
        int* novaTuplaOp1 = (int*)malloc(sizeof(int) * 2);
        novaTuplaOp1[0] = numero * 2;
        novaTuplaOp1[1] = quantOps;

        int* novaTuplaOp2 = (int*)malloc(sizeof(int) * 2);
        novaTuplaOp2[0] = numero * 3;
        novaTuplaOp2[1] = quantOps;

        int* novaTuplaOp3 = (int*)malloc(sizeof(int) * 2);
        novaTuplaOp3[0] = numero / 2;
        novaTuplaOp3[1] = quantOps;

        int* novaTuplaOp4 = (int*)malloc(sizeof(int) * 2);
        novaTuplaOp4[0] = numero / 3;
        novaTuplaOp4[1] = quantOps;

        int* novaTuplaOp5 = (int*)malloc(sizeof(int) * 2);
        novaTuplaOp5[0] = numero + 7;
        novaTuplaOp5[1] = quantOps;

        int* novaTuplaOp6 = (int*)malloc(sizeof(int) * 2);
        novaTuplaOp6[0] = numero - 7;
        novaTuplaOp6[1] = quantOps;

        //Se um dos numeros calculador for igual ao numeroAlvo, encerrar
        if (novaTuplaOp1[0] == numeroAlvo || novaTuplaOp2[0] == numeroAlvo || 
            novaTuplaOp3[0] == numeroAlvo || novaTuplaOp4[0] == numeroAlvo || 
            novaTuplaOp5[0] == numeroAlvo || novaTuplaOp6[0] == numeroAlvo) {
            break;
        }

        //--Analisar e adicionar tuplas com valores nao existentes a fila
        int podeEntrar1 = 1, podeEntrar2 = 1, podeEntrar3 = 1;
        int podeEntrar4 = 1, podeEntrar5 = 1, podeEntrar6 = 1;

        //Verificar quais valores existem na fila
        for (int j = 0; j < fila.contador; j++) {
            if (novaTuplaOp1[0] == fila.filaVets[j][0]) {
                podeEntrar1 = 0;
            }
            if (novaTuplaOp2[0] == fila.filaVets[j][0]) {
                podeEntrar2 = 0;
            }
            if (novaTuplaOp3[0] == fila.filaVets[j][0]) {
                podeEntrar3 = 0;
            }
            if (novaTuplaOp4[0] == fila.filaVets[j][0]) {
                podeEntrar4 = 0;
            }
            if (novaTuplaOp5[0] == fila.filaVets[j][0]) {
                podeEntrar5 = 0;
            }
            if (novaTuplaOp6[0] == fila.filaVets[j][0]) {
                podeEntrar6 = 0;
            }
        }

        //Inserindo os valores nao existentes na fila
        if(podeEntrar1){
            fila_insere(&fila, novaTuplaOp1);
        }
        if(podeEntrar2){
            fila_insere(&fila, novaTuplaOp2);
        }
        if(podeEntrar3){
            fila_insere(&fila, novaTuplaOp3);
        }
        if(podeEntrar4){
            fila_insere(&fila, novaTuplaOp4);
        }
        if(podeEntrar5){
            fila_insere(&fila, novaTuplaOp5);
        }
        if(podeEntrar6){
            fila_insere(&fila, novaTuplaOp6);
        } 
    }

    printf("%d\n", quantOps);

    //TEMPO:
    // Registra o tempo final
    clock_t fim = clock();
    
    // Calcula o tempo gasto em segundos
    double tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    // Exibe o tempo de execução
    printf("Tempo de execução: %f segundos\n", tempo_gasto);

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