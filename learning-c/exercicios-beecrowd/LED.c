#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //Obter quantidade paineis, guardar em N
    int N;
    scanf("%d", &N);

    //- Cadastrar quantidade de leds necessarios por numero em ledsNum[10] de acordo com a posicao
    int ledsNum[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    //- Obter numeros que serao representados em leds, guardar em numeros[N]
    unsigned int *numeros = (unsigned int*)malloc(N * sizeof(unsigned int));
    for (int i = 0; i < N; i++) {
        scanf("%u", &numeros[i]);
    }

    //Inicializar somaLed com 0
    int somaLed = 0;
    //Repetir N vezes
    for (int i = 0; i < N; i++) {
        //- Obter numero que sera representado em leds, guardar em numero
        unsigned int val = numeros[i];
        
        //- Obter quantidade de leds, guardar em somaLed
        //Iterar pelos algarismos de numero, realizar somatorio dos valores armazenados na posicao algarismo em ledsNum[algarismo]
            //Seprar algarismo, atualizar numero, atualizar somaLed
                int cont = 0, algarismo;
                int valOperado = val;
                //1 Encontrar potencia 10
                while(valOperado != 0){
                    cont ++;
                    valOperado = valOperado / 10;
                }
                valOperado = val;
                //Repetir
                while (cont > 0) {
                    //2 Extrair algarismo
                    algarismo = valOperado / pow(10, cont - 1);
                    //2.1 Atualizar somaLed
                    somaLed += ledsNum[algarismo];
                    //3 Atualizar numero
                    valOperado = valOperado - (algarismo * pow(10, cont - 1));
                    //4 Atualizar contador
                    cont --;
                }
        //Mostrar valor armazenado em somaLed
        printf("%d leds\n", somaLed);
        //Zerar soma led
        somaLed = 0;
    }
    

    return 0;
}