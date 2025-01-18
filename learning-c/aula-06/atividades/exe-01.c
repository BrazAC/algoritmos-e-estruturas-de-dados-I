#include <stdio.h>
#include <stdlib.h>

//Tarefinha: Crie uma struct que carrega o vetor e sua capacidade

void preencheVetor(int*, int);
int* copiaVetor(int*, int);

int main(){
    //Obter tamanho do vetor
    int N;
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &N);

    //Alocar vetor, guardar em vetOriginal
    int *vetOriginal = (int*)malloc(N * sizeof(int));

    //Chamar funcao preencheVetor, passar vetOriginal por referencia
    preencheVetor(vetOriginal, N);

    //Criar ponteiro vetorCopia
    int *vetorCopia;

    //Chamar funcao copiaVetor, passar vetorCopia por copia
    vetorCopia = copiaVetor(vetOriginal, N);

    //Mostrar vetOriginal, mostrar vetorCopia
    /*
    for (int i = 0; i < N; i++) {

    }
    */
    return 0;
}

void preencheVetor(int *vetor, int tamanho){
    printf("Preenchendo o vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("Insira um valor: ");
        scanf("%d", &vetor[i]);
    }
}

int* copiaVetor(int *vetorOriginal, int tamanho){
    printf("Copiando o vetor!\n");

    int *vetorCopia = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) vetorCopia[i] = vetorOriginal[i];

    return vetorCopia;
}