#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //Obter quantidade de naves, guardar em N
    int N;
    scanf("%d", &N);

    //Alocar memoria para matriz de inteiros de dimensao Nx3, nomear mtzCoordenadas
    //Alocando linhas
    int **mtzCoordenadas = (int**)malloc(N * sizeof(int**));
    //Alocando colunas
    for (int i = 0; i < N; i++) {
        mtzCoordenadas[i] = (int*)malloc(3 * sizeof(int));
    }

    //Preencher mtzCoordenadas com inputs por linha
    //Fazer uma vez para cada linha
    for (int i = 0; i < N; i++) {
        int cont = 0, coordenada;
        while (scanf("%d", &coordenada) != EOF) {
            cont ++;
            mtzCoordenadas[i][cont - 1] = coordenada;
 
            //Quando apertar enter encerrar
            if (getchar() == '\n') {
                break;
            }
        }
    }
        
    //Classificar distancias entre A, M e B
        //Repetir N vezes (fazer para todas as linhas)
        for (int i = 0; i < N; i++) {
            //Alocar memoria e criar vetDistancias[N - 1]
            double *vetDistancias = (double*)malloc((N - 1) * sizeof(double));

            //Extrair coordenadas da nave atual, guardar em x, y, z
            int x = mtzCoordenadas[i][0];
            int y = mtzCoordenadas[i][1];
            int z = mtzCoordenadas[i][2];

            //Calcular distancias entre a nave atual e todas as outras, guardar em vetDistancias
            //Repetir de i = 0 enquanto i < N
            int cont = 0;
            for (int k = 0; k < N; k++) {
                //se i != N faca
                if (k != i) {
                    cont ++;
                    //Guardar distancias da nave alvo, guardar em xo, yo, zo
                    int xo = mtzCoordenadas[k][0];
                    int yo = mtzCoordenadas[k][1];
                    int zo = mtzCoordenadas[k][2];
                    vetDistancias[cont - 1] = sqrt((x - xo)*(x - xo) + (y - yo)*(y - yo) + (z - zo)*(z - zo));
                }     
            }
            
            //Encontrar a menor distancia em vetDistancias, guardar em menorDistancia
            int menorDistancia = vetDistancias[0];
            for (int j = 0; j < (N - 1); j++) {
                if (vetDistancias[j] < menorDistancia) {
                    menorDistancia = vetDistancias[j];
                }
            }

            //Classificar e mostrar a classificacao de menorDistancia (A, M ou B)
            if (menorDistancia <= 20) {
                printf("A\n");
            } else if (menorDistancia <= 50) {
                printf("M\n");
            }else{
                printf("B\n");
            }
        }
            

    return 0;
}