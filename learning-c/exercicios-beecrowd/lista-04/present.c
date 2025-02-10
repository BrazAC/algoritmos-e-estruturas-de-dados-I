#include <stdlib.h>
#include <stdio.h>

int main(){
    int totalPedras, posPresente;
    scanf("%d %d", &totalPedras, &posPresente);

    //Declarando variaveis para o problema
    int contPulos, posSapo;
    char dirPulo;

    //Repetindo enquanto as entradas nao forem 0
    while(totalPedras != 0 && posPresente != 0){
        contPulos = 1;
        posSapo = 1;

        //Enquanto o sapo nao chegar no presente, e, estiver fora da margem do rio, repetir
        while (posSapo != posPresente && posSapo < (totalPedras + 1) && posSapo > 0) {
            //-- Mover sapo
            //Identificar a firecao do pulo
            dirPulo = (posPresente < posSapo) ? 't' : 'f';

            //Pular (atualizar a posicao do sapo)
            contPulos ++;
            if (dirPulo == 'f') {
                posSapo = posSapo + ((2 * contPulos) - 1);
            }
            else {
                posSapo = posSapo - ((2 * contPulos) - 1);
            }

            printf("Pulo: %d\n", contPulos);
            printf("Direcao do pulo: %c\n", dirPulo);
            printf("Posicao depois do pulo: %d\n", posSapo);
            
        }

        //Identificar se o sapo conseguiu ou nao
        if (posSapo == posPresente) {
            printf("Let me try!\n");
        }
        else{
            printf("Don't make fun of me!\n");
        }
        
        printf("Posicao final: %d\n", posSapo);

        //Pegando prox entrada
        scanf("%d %d", &totalPedras, &posPresente);
    }

    return 0;
}