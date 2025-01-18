#include <stdio.h>
#include <stdlib.h>

//Tarefinha: Crie uma struct que carrega o vetor e sua capacidade
typedef struct vetorETamanho {
    int tamanho;
    int *vetor;
} vetorETamanho;


void preencheVetor(vetorETamanho);
int* copiaVetor(vetorETamanho);

int main(){
    //Declaracao do struct
    vetorETamanho vetorStruct;

    //Obter tamanho do vetor //Atualizar no dado tipo struct
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &vetorStruct.tamanho);

    //Alocar vetor, guardar em vetorStruct
    vetorStruct.vetor = (int*)malloc(vetorStruct.tamanho * sizeof(int));

    //Chamar funcao preencheVetor, passar vetOriginal por referencia
    preencheVetor(vetorStruct);

    //Criar ponteiro vetorCopia
    int *vetorCopia;

    //Chamar funcao copiaVetor, passar vetorCopia por copia
    vetorCopia = copiaVetor(vetorStruct);

    //Mostrar vetOriginal, mostrar vetorCopia
    /*
    for (int i = 0; i < N; i++) {

    }
    */
    return 0;
}

void preencheVetor(vetorETamanho vetorStruct){
    printf("Preenchendo o vetor:\n");
    for (int i = 0; i < vetorStruct.tamanho; i++) {
        printf("Insira um valor: ");
        scanf("%d", &vetorStruct.vetor[i]);
    }
}

int* copiaVetor(vetorETamanho vetorStruct){
    printf("Copiando o vetor!\n");

    int *vetorCopia = (int*)malloc(vetorStruct.tamanho * sizeof(int));

    for (int i = 0; i < vetorStruct.tamanho; i++) vetorCopia[i] = vetorStruct.vetor[i];

    return vetorCopia;
}