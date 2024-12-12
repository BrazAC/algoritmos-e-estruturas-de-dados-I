/*
Aluno: Braz Amorim
Curso: Ciencia da computacao
Disciplina: Estrutura de dados I

Dado dois vetores some os valores do vet1 com vet2, considerando as respectivas posições
e armazene num vetor de resultado. Imprima o resultado
*/

#include <stdio.h>
#include <stdlib.h>

//Declarando e inicializando constante
#define TAM_VET 5

int main(){
    //Declarando vetores
    int vet1[TAM_VET], vet2[TAM_VET], vetSoma[TAM_VET];

    //Inicializando vetores
    printf("Insira valores para o vetor1:\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &vet1[i]);
    }

    printf("Insira valores para o vetor2:\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &vet2[i]);
    }

    //Somando valores e guardando em vetSoma
    for(int i = 0; i<5; i++){
        vetSoma[i] = vet1[i] + vet2[(TAM_VET - 1) - i];
    }

    //Encontrar maior e menor valor do vetor soma
    int maior = vetSoma[0];
    int menor = vetSoma[0];
    for(int j = 0; j < 5; j++){
        //Descobrindo maior
        if(maior < vetSoma[j]){
            maior = vetSoma[j];
        }

        //Descobrindo menor
        if(menor > vetSoma[j]){
            menor = vetSoma[j];
        }
    }

    //Mostrando vetores
    printf("Vet1: ");
    for(int i = 0; i < 5; i++){
        printf("| %d ",vet1[i]);
    }
    printf("|\n");

    printf("Vet2: ");
    for(int i = 0; i < 5; i++){
        printf("| %d ",vet2[i]);
    }
    printf("|\n");

    printf("Soma: ");
    for(int i = 0; i < 5; i++){
        printf("| %d ",vetSoma[i]);
    }
    printf("|\n");

    printf("O maior valor do vetor soma: %d\n", maior);
    printf("O menor valor do vetor soma: %d\n", menor);

    return 0;
}