#include <stdio.h>
#include <stdlib.h>

int main(){
    //Criar sentinela vazia (tamanho da matriz)
    int mtzSize;
    
    //1 - Obter tamanhos das matrizes
    //Inicializando contador para alocacao dinamica de memoria
    int cont = 1;

    //Criar vetor para guardar os tamanhos de matriz
    int *sizes = (int*)malloc(cont * sizeof(int));

    //Obter primeiro valor de tamanho da matriz (sentinela)
    scanf("%d", &mtzSize);

    //Equanto a tamanho da matriz for diferente de 0
    while (mtzSize != 0){
        //Guardar o tamanho da matriz no final do vetor
        sizes[cont - 1] = mtzSize;
        //Obter valor da tamanho da matriz (sentinela)
        scanf("%d", &mtzSize);
        //Atualizar contador
        cont ++;
        //Se o tamanho for diferente de zero aumentar o tamanho do vetor
        if (mtzSize != 0) {
            int *temp = (int*)realloc(sizes, cont * sizeof(int));
            sizes = temp;
        }
    }

    //2 - Criar e mostrar matrizes
    for (int i = 0; i < cont; i++) {
        //Obtendo tamanho da matriz da vez
        mtzSize = sizes[i];
        
        //Criar matriz de inteiros do tamanho da sentinela
        //Criar linhas (vetor de ponteiros)
        int **mtz = (int**)malloc(mtzSize * sizeof(int**));
        //Criar colunas (vetores de inteiros)
        for (int k = 0; k < mtzSize; k++) {
            mtz[k] = (int*)malloc((mtzSize) * sizeof(int));
        }

        //Preencher a matriz como uma matriz identidade
        for (int i = 0; i < mtzSize; i++) {
            for (int j = 0; j < mtzSize; j++) {
                if (i == j) {
                    mtz[i][j] = 1;
                }else{
                    mtz[i][j] = 0;
                }
            }
        }

        //Transformar matriz identidade em uma matriz simetrica
        //Iterar pela parte superior da matriz da esquerda para direita:
        for (int i = 0; i < (mtzSize - 1) ; i++) {
            for (int j = (i + 1); j < mtzSize; j++) {
                //mtz[i][j] = mtz[i][j - 1] + 1
                mtz[i][j] = mtz[i][j - 1] + 1;
            }
        }
        //Iterar pela parte inferior da matriz da direita pra esquerda:
        for (int i = (mtzSize - 1); i > 0 ; i--) {
            for (int j = (i - 1); j >= 0; j--) {
                //mtz[i][j] = mtz[i][j + 1] + 1
                mtz[i][j] = mtz[i][j + 1] + 1;
            }
        }
            
        //Mostrar matriz final
        for (int i = 0; i < mtzSize; i++) {
            for (int j = 0; j < mtzSize; j++) {
                if (j == (mtzSize - 1)) {
                    //Apos o ultimo elemento de cada coluna nao deve ter um espaco
                    printf("%d\n", mtz[i][j]);
                }else{
                    //Separar cada elemento entre si com um espaco
                    printf("%d ", mtz[i][j]);
                }
            }
        }
        //Apos mostrar a matriz, pular uma linha a mais
        printf("\n");
    }

    return 0;
}


        