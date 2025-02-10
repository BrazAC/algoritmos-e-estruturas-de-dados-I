#include <stdlib.h>
#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    getchar();

    char sandAndDiamonds[1001];

    for (int i = 0; i < N; i++) {
        //Obter string
        fgets(sandAndDiamonds, sizeof(sandAndDiamonds), stdin);
        
        //Retirar '\n'
        int cont = 0;
        while (sandAndDiamonds[cont] != '\0'){
            cont ++;
        }
        cont --;
        if (sandAndDiamonds[cont - 1] == '\n') {
            sandAndDiamonds[cont - 1] = '\0';
        }

        //Contar diamantes
        int contDiamantes = 0;
        for (int i = 0; i < cont; i++) {
            //Procurar por um '<', se  encontrar:
            if (sandAndDiamonds[i] == '<') {
                //Procurar por um '>', se encontrar: contDiamantes ++
                for (int j = i + 1; j < cont; j++) {
                    if (sandAndDiamonds[j] == '>') {
                        contDiamantes ++;
                        sandAndDiamonds[j] = '.';
                        break;
                    }
                }
            }
            
        } 
        printf("%d\n", contDiamantes);
    }


    return 0;
}