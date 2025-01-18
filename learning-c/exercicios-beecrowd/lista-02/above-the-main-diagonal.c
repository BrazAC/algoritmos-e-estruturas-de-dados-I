#include <stdio.h>

#define TAM_mtx 12

float somaMtx(float mtx[TAM_mtx][TAM_mtx]){
    float soma = 0;
    //Somar todos os elementos acima da diagonal principal
    for (int i = 0; i < TAM_mtx - 1; i++) {
        for (int j = i + 1; j < TAM_mtx; j++) {
            soma += mtx[i][j];
        }
    }
    return soma;
}

int main(){
    //Criar variavel para a opcao e criar a matriz 12x12 e para a resposta final
    char opcao;
    float mtx[TAM_mtx][TAM_mtx], soma;
    int quantAcimaPrincipal;

    //Obter opção S (soma), A (média)
    scanf("%c", &opcao);

    //Preencher mtz com entradas do usuario
    for (int i = 0; i < TAM_mtx; i++) {
        for (int j = 0; j < TAM_mtx; j++) {
            scanf("%f", &mtx[i][j]);
        }
    }

    //Analisar a opção
    if (opcao == 'S') {
        //Se for S, somar todos os elementos acima da diagonal principal
        printf("%.1f\n", somaMtx(mtx));

    } else if (opcao == 'M') {
        //Se for A, calcular a media de todos o elementos acima da diagonal principal
            //Somar todos os elementos
            soma = somaMtx(mtx);
            //Dividir a soma pela quantidade de elementos somados
            quantAcimaPrincipal = (TAM_mtx * (TAM_mtx - 1)) / 2;
            printf("%.1f\n", soma / quantAcimaPrincipal);
    }

    return 0;
}