#include <stdio.h>
#include <stdlib.h>

int main(){
    //obter quantidade de alunos, guardar em n
    int n;
    scanf("%d", &n);

    //alocar vetor de ponteiros com n espacos, chamar de prtLinhas
    int **prtLinhas = (int**)malloc(n * sizeof(int**));

    //repetir de i == 0 enquanto i < n
    for (int i = 0; i < n; i++) {
        //Criar vetor com 6 espacos, guardar em prtLinhas[i]
        prtLinhas[i] = (int*)malloc(6 * sizeof(int));
    }
        
    //obter e armazenar dados
    char *nome = (char*)malloc(40 * sizeof(char));
    for (int k = 0; k < n; k++) {
        //obter nome
        scanf("%s", nome);

        //preencher primeiros tres espacos da linha
        int valor, contador = 0;
        while(scanf("%d", &valor) != -1){
            contador ++;
            prtLinhas[k][contador - 1] = valor;
            
            if (contador == 3) {
                break;
            }
        }

        //preencher ultimos tres espacos da linha
        contador = 3;
        while(scanf("%d", &valor) != -1){
            contador ++;
            prtLinhas[k][contador - 1] = valor;
            
            if (getchar() == '\n') {
                break;
            }
        }
    }

    //Calcular porcentagem saques bem sucedidos
    //inicializar var somaTentativasTotais = 0
    float somaTentativasTotais = 0;
    //inicializar var somaTentativasEfetivas = 0
    float somaTentativasEfetivas = 0;
    //repetir de i == 0 enquanto i < n
    for (int j = 0; j < n; j++) {
        //somaTentativasTotais += prtLinhas[i][0]
        somaTentativasTotais += prtLinhas[j][0];
        //somaTentativasEfetivas += prtLinhas[i][3]
        somaTentativasEfetivas += prtLinhas[j][3];
    }
        
    //Mostrar porcentagem de saques bem sucedidos:
        //printf("Pontos de Saque: %.2f %%.")
        float saquesBemSucedidos = (somaTentativasEfetivas * 100) / somaTentativasTotais;
        printf("Pontos de Saque: %.2f %%.\n", saquesBemSucedidos);
    
    //Calcular porcentagem bloqueios bem sucedidos
    //inicializar var somaTentativasTotais = 0
    somaTentativasTotais = 0;
    //inicializar var somaTentativasEfetivas = 0
    somaTentativasEfetivas = 0;
    //repetir de i == 0 enquanto i < n
    for (int j = 0; j < n; j++) {
        //somaTentativasTotais += prtLinhas[i][0]
        somaTentativasTotais += prtLinhas[j][1];
        //somaTentativasEfetivas += prtLinhas[i][3]
        somaTentativasEfetivas += prtLinhas[j][4];
    }
        
    //Mostrar porcentagem de saques bem sucedidos:
        //printf("Pontos de Saque: %.2f %%.")
        float bloqueiosBemSucedidos = (somaTentativasEfetivas * 100) / somaTentativasTotais;
        printf("Pontos de Bloqueio: %.2f %%.\n", bloqueiosBemSucedidos);

    //Calcular porcentagem ataques bem sucedidos
    //inicializar var somaTentativasTotais = 0
    somaTentativasTotais = 0;
    //inicializar var somaTentativasEfetivas = 0
    somaTentativasEfetivas = 0;
    //repetir de i == 0 enquanto i < n
    for (int j = 0; j < n; j++) {
        //somaTentativasTotais += prtLinhas[i][0]
        somaTentativasTotais += prtLinhas[j][2];
        //somaTentativasEfetivas += prtLinhas[i][3]
        somaTentativasEfetivas += prtLinhas[j][5];
    }
        
    //Mostrar porcentagem de saques bem sucedidos:
        //printf("Pontos de Saque: %.2f %%.")
        float ataquesBemSucedidos = (somaTentativasEfetivas * 100) / somaTentativasTotais;
        printf("Pontos de Ataque: %.2f %%.\n", ataquesBemSucedidos);
    return 0;
}