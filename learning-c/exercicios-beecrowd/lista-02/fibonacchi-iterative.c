#include <stdio.h>
#include <stdlib.h>

int main(){
    //Obter quantidade de entradas
    int n, pos;
    scanf("%d", &n);
    //Repetir a quantidade de entrada vezes:
    /*
    Obs: Ja testei guardar as entradas em um vetor e iterar retornando os valores correspondentes
    mas nao funciona de qualquer forma, o Gregorio tambem fez a mesma coisa e nao da certo em 
    com e sem o uso de um vetor pra guardar as entradas
    */
    for (int i = 0; i < n; i++){
        //Obter posicao da sequencia desejada
        scanf("%d", &pos);
        // - Analisar posicao, retornar de acordo
        if (pos == 0) {
            //se posicao == 0 retornar 0         
            printf("Fib(0) = 0\n");
        }else if (pos == 1) {
            //se posicao == 1 retornar 1   
            printf("Fib(1) = 1\n");
        }else{
            //caso contrario:
            //Criar vetor de inteiros do tamanho da posicao obtida
            long unsigned int *seq = (long unsigned int*)malloc((pos + 1) * sizeof(long unsigned int));
            //Colocar 0 na posicao 0, 1 na posicao 1 do vetor
            seq[0] = 0;
            seq[1] = 1;
            //Repetir de 2 ate posicao da sequencia:
            for (int j = 2; j <= pos; j++) {
                //posicao atual do vetor = vetor[i - 2] + vetor[i - 1]
                seq[j] = seq[j - 2] + seq[j - 1];
            }
            //Retornar o que esta na ultima posicao do vetor
            printf("Fib(%d) = %ld\n", pos, seq[pos]);
            //Liberar a memória alocada
            free(seq);
        }
    }

    return 0;
}