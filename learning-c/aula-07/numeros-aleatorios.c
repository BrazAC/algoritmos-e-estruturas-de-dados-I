#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    //Gerar a semente com srand()
    time_t tAtual;
    tAtual = (unsigned)time(&tAtual);
    srand(tAtual);

    //Gerar numeros aleatorios
    int i = rand() % 10;
    printf("Aleatorio: %d\n", i);

    int i2 = rand() % 10;
    printf("Aleatorio: %d\n", i2);

    int i3 = rand() % 10;
    printf("Aleatorio: %d\n", i3);

    return 0;
}