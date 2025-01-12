#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Essa versao 2 funciona para qualquer caso pois atua com os characteres da string que representa
o numero informado.
*/ 

int main(){
    //Obter quantidade paineis, guardar em N
    int N;
    scanf("%d", &N);

    //- Cadastrar quantidade de leds necessarios por numero em ledsNum[10] de acordo com a posicao
    int ledsNum[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    //- Obter numeros que serao representados em leds, guardar em numeros Nx1
    char **mtzNumeros = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        mtzNumeros[i] = (char*)malloc(101 * sizeof(char));
    }
    //Obtendo valores
    for (int i = 0; i < N; i++) {
        scanf("%s", mtzNumeros[i]);
    }

    //- Calculando o total de leds
    int somaLed = 0;
    //Repetir para cada numero (linha da matriz)
    for (int i = 0; i < N; i++) {
        int cont = 0;
        char numero = mtzNumeros[i][cont];
        while (numero != '\0') {
            //Avaliar numero e atualizas somaLed
            int numeroInt;
            if (numero == '0') {
                somaLed += ledsNum[0];
                numeroInt = 0;
            } else if (numero == '1'){
                somaLed += ledsNum[1];
                numeroInt = 1;
            } else if (numero == '2'){
                somaLed += ledsNum[2];
                numeroInt = 2;
            } else if (numero == '3'){
                somaLed += ledsNum[3];
                numeroInt = 3;
            } else if (numero == '4'){
                somaLed += ledsNum[4];
                numeroInt = 4;
            } else if (numero == '5'){
                somaLed += ledsNum[5];
                numeroInt = 5;
            } else if (numero == '6'){
                somaLed += ledsNum[6];
                numeroInt = 6;
            } else if (numero == '7'){
                somaLed += ledsNum[7];
                numeroInt = 7;
            } else if (numero == '8'){
                somaLed += ledsNum[8];
                numeroInt = 8;
            } else if (numero == '9'){
                somaLed += ledsNum[9];
                numeroInt = 9;
            }
            //printf("%d\n", numeroInt);
            //Pegar proximo valor
            cont ++;
            numero = mtzNumeros[i][cont];
        }
        
        //Mostrar somaLed
        printf("%d leds\n", somaLed);

        //Zerar somaLed
        somaLed = 0;
    }
    
    return 0;
}