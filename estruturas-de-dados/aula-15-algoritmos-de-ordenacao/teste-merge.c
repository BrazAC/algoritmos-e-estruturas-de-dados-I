#include <stdlib.h>
#include <stdio.h>

void merge_sort(int[], int e, int d);
void merge(int[], int e, int meio, int d);

void merge_sort(int vet[], int e, int d){
    if (d > e){
        int meio = (e + d) / 2;
        merge_sort(vet, e, meio);
        merge_sort(vet, meio + 1, d);
        merge(vet, e, meio, d);
    }
}

void merge(int vet[], int e, int meio, int d){
    int i = 0, j = 0, k = e;

    //Calcular tamanho vetores auxialiress
    int n1 = meio - e + 1;
    int n2 = d - meio;
    int L[n1], R[n2];

    //Preencher vetores auxiliares
    for (int i = 0; i < n1; i++){
        L[i] = vet[e + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = vet[meio + 1 + j];
    }

    //Mesclar L[] e R[]
    while(i < n1 && j < n2){
        if (L[i] < R[j]) {
            vet[k] = L[i];
            i ++;
        }
        else{
            vet[k] = R[j];
            j++;
        }
        k++;
    }

    //Copiar elementos restantess em L se existir
    while(i < n1){
        vet[k] = L[i];
        i++;
        k++;
    }
    //Copiar os elementos restantes em R se existir
    while(j < n2){
        vet[k] = R[j];
        j ++;
        k++;
    }

}

int main(){
    int vet[10] = {3, 5, 5, 8, 2, 3, 1, 9, 2, 7};

    for (int i = 0; i < 10; i++) {
        printf("[%d]",vet[i]);
    }
    printf("\n");

    merge_sort(vet, 0, 10 - 1);

    for (int i = 0; i < 10; i++) {
        printf("[%d]",vet[i]);
    }
    printf("\n");

    return 0;
}