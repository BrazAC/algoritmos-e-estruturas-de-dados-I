#include <stdio.h>

int main(){
    //Obter a quantidade de testes, guardar m N
    int N;
    scanf("%d", &N);

    //Repetir N vezes
    char primeiraStr[50], segundaStr[50], strFinal[100];
    for (int j = 0; j < N; j++) {
        //Obter primeira e segunda strings (50 characters)
        //guardar em primeiraStr e segundaStr
        scanf("%s %s", primeiraStr, segundaStr);

        //Identificar menor e maior string, guardar em menorStr e maiorStr
        char menorStr[50], maiorStr[50];
        int cont1 = 0, cont2 = 0, cont = 0;

        while (primeiraStr[cont1] != '\0') {
            cont1 ++;
        }
        while (segundaStr[cont2] != '\0') {
            cont2 ++;
        }

        int sizeMaiorString, sizeMenorString;

        if (cont1 > cont2) {
            for (int j = 0; j <= cont1; j++) {
                maiorStr[j] = primeiraStr[j];
            }
            for (int j = 0; j <= cont2; j++) {
                menorStr[j] = segundaStr[j];
            }

            //Descrobrir sizeMaiorString
            sizeMaiorString = cont1;
            sizeMenorString = cont2;
        }else{
            for (int j = 0; j <= cont2; j++) {
                menorStr[j] = primeiraStr[j];
            }
            for (int j = 0; j <= cont1; j++) {
                maiorStr[j] = segundaStr[j];
            }

            //Descrobrir sizeMaiorString
            sizeMaiorString = cont2;
            sizeMenorString = cont1;
        }

        printf("%d\n", sizeMaiorString);

        //Iterar de 0 ate (sizeMaiorString - 1) passo 2
        int cont3 = 0, sentinel = 1, sinalStr, i = 0;
        while (cont3 < sizeMaiorString) {
            //Identificar quando e qual string acabou
            if (primeiraStr[cont3] == '\0' || segundaStr[cont3] == '\0'){
                sentinel = 0;
                if (primeiraStr[cont3] == '\0'){
                    sinalStr = 2;
                }else if (segundaStr[cont3] == '\0'){
                    sinalStr = 1;
                }
            }
            //Concatenar characters em strFinal  
            //Sequencia alternante
            if (sentinel == 1) {
                strFinal[i] = primeiraStr[cont3];
                strFinal[i + 1] = segundaStr[cont3];
                printf("%c ", primeiraStr[cont3]);
                printf("%c ", segundaStr[cont3]);
            //Sequencia direta
            }else{
                if (sinalStr == 2) {
                    //Concatenar o resto de segundaStr em strFinal
                    strFinal[cont3] = segundaStr[cont3];
                    printf("%c ", strFinal[cont3]);
                }else{
                    //Concatenar o resto de primeiraStr em strFinal
                    strFinal[cont3] = primeiraStr[cont3];
                    printf("%c\n", strFinal[cont3]);
                }
            }
            cont3 ++;
            i += 2;
        }
        printf("\n");
        for (int i = 0; i < cont3; i++) {
            printf("%c", strFinal[i]);
        }
        printf("\n");
    }
        

            

    return 0;
}