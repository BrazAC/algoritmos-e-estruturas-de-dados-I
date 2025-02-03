#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 5

typedef struct typeLista {
    int lista[MAXSIZE];
    int contador;
} typeLista;

void passaPorRef(int *);
void insertInList(typeLista *, int);

int main(){
    int var = 5;
    int vetor[3] = {1, 2, 3};

    passaPorRef(vetor);

    printf("%d\n", vetor[0]);

    typeLista minhaLista;
    minhaLista.contador = 0;


    return 0;
}

void passaPorRef(int *var0){
    var0[0] = 2;
}

void insertInList(typeLista *fila, int valor){
    if (fila->contador >= MAXSIZE) {
        printf("[ERRO] Fila cheia\n");
    }
    else{
        fila->lista[fila->contador] = valor;
        fila->contador ++;
    }
}