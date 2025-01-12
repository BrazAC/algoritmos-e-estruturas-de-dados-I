#include <stdio.h>
#include <stdlib.h>

int main(){
    //Obter quantidade de picos/vales, guardar em n
    int n;
    scanf("%d", &n);

    //Obter alturas em uma mesma linha, guardar em alturas[n]
    int* alturas = NULL;
    int altura;
    int contador = 0;

    while(scanf("%d", &altura) != EOF){
        contador ++;
        alturas = realloc(alturas, contador * sizeof(int));
        alturas[contador - 1] = altura;

        if (getchar() == '\n') {
            break;
        }
    }

    //Criar variaveis sentinelas, uma para pico e outra para vale
    int pico, vale = 0;
    //Iterar por alturas[n] a partir da posicao 1
    for (int i = 1; i < n; i++) {
        //Se posicao == 1 avaliar a primeira posicao e a segunda posicao
        if (i == 1) {
            //Se altura atual for maior que a anterior
            if (alturas[i] > alturas[i - 1]) {
                //Altura atual = pico
                //Atura anterior = vale
                pico ++;
            }
            //Se altura atual for menor que a anterior
            else if (alturas[i] < alturas[i - 1]) {
                //Altura atual = vale   
                //Atura anterior = pico  
                vale ++;
            }  
            //Se altura atual for igual a anterior
            else if (alturas[i] == alturas[i - 1]) {
                //Alturas iguais, encerrar iteracao e printar 0
                printf("0\n");
                return 0;
            }
        //Caso contrario, avaliar a posicao atual em relacao a anterior   
        }else{
            //Se a altura atual for maior que a anterior
            if (alturas[i] > alturas[i - 1]) {
                //Altura atual = pico
                pico ++;
                vale = 0;
            }
            else if (alturas[i] < alturas[i - 1]) {
                //Altura atual = vale
                vale ++;
                pico = 0;
            //Caso contrario
            } else {
                //Alturas iguais, encerrar iteracao e printar 0
                printf("0\n");
                return 0;
            }
        }
        //Se vale ou pico for > 1, mostrar 1 e retornar 0; 
        if (vale > 1 || pico > 1) {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}