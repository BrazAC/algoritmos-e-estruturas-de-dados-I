#include <stdlib.h>
#include <stdio.h>

#define CAPACIDADE 5

//Definir estrutura da fila
typedef struct minhaFila {
    char vetor[CAPACIDADE];
    int contador;
} minhaFila;

//Prototipagem
void insereNaFila(minhaFila *, char);
void imprimeFila(minhaFila *);
void removeDaFila(minhaFila *);
void mostraQuantosNaFila(minhaFila *);

int main(){
    //Criando uma estrutura do tipo minhaFila
    minhaFila filaDeLetras;
    filaDeLetras.contador = 0;

    //Chamando funcoes
    insereNaFila(&filaDeLetras, 'f');
    mostraQuantosNaFila(&filaDeLetras);
    imprimeFila(&filaDeLetras);

    insereNaFila(&filaDeLetras, 'g');
    mostraQuantosNaFila(&filaDeLetras);
    imprimeFila(&filaDeLetras);

    insereNaFila(&filaDeLetras, 's');
    mostraQuantosNaFila(&filaDeLetras);
    imprimeFila(&filaDeLetras);

    insereNaFila(&filaDeLetras, 'a');
    mostraQuantosNaFila(&filaDeLetras);
    imprimeFila(&filaDeLetras);

    insereNaFila(&filaDeLetras, 'k');
    mostraQuantosNaFila(&filaDeLetras);
    imprimeFila(&filaDeLetras);
    
    removeDaFila(&filaDeLetras);
    mostraQuantosNaFila(&filaDeLetras);
    imprimeFila(&filaDeLetras);

    removeDaFila(&filaDeLetras);
    mostraQuantosNaFila(&filaDeLetras);
    imprimeFila(&filaDeLetras);
    
    return 0;
}

//Implementando insercao
void insereNaFila(minhaFila *filaDeLetras, char letra){
    //Antes de inserir, verificar se a fila esta cheia
    //Se estiver avisar
    if (filaDeLetras->contador >= CAPACIDADE) {
        printf("[ERRO] Fila cheia!\n");
    }
    //Se nao estiver, inserir dado
    else {
        filaDeLetras->vetor[filaDeLetras->contador] = letra;
        filaDeLetras->contador ++;
    } 
}

//Implementando remocao
void removeDaFila(minhaFila *fila){
    char primeiroDaFila = fila->vetor[0];
    for (int i = 0; i < (fila->contador - 1); i++){
        fila->vetor[i] = fila->vetor[i + 1];
    }
    fila->contador --;
}

//Implementando impressao
void imprimeFila(minhaFila *fila){
    printf("[%c", fila->vetor[0]);
    for (int i = 1; i < fila->contador; i++) {
        printf(", %c", fila->vetor[i]);
    }
    printf("]\n");
}

void mostraQuantosNaFila(minhaFila * fila){
    printf("Existem %d na fila\n", fila->contador);
}