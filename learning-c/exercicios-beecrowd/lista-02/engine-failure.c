#include <stdio.h>
#include <stdlib.h>


int main(){
    //Obter quantidade de testes guardar em n
    int n;
    scanf("%d", &n);

    //Obter n entradas em linha unica, guardar em medidas[n]
    //alocar dinamicamente vetor de tamanho n
    int *testes = (int*)malloc(n * sizeof(int)); 
    //inicializar contador com 0
    int contador = 0;
    //declarar variavel rpm
    int rpm;
    //enquanto(retorno de scanf guardando em rpm for diferente de -1)
    while(scanf("%d", &rpm) == 1){
        contador ++;
        testes[contador - 1] = rpm;
        //se o proximo character no buffer == '\n', encerrar loop
        if (getchar() == '\n'){
            break;
        } 
    }
    //Criar sentinela = 0
    int sentinela = 0;
    //Iterar por medidas[n] comecando em 1
    for (int i = 1; i < n; i++) {
        //Se medida[i] < medida[i - 1] 
        if (testes[i] < testes[i - 1]){
            //sentinela = i + 1
            sentinela = i + 1;
            break;
        } 
    }
    //mostrar valor da sentinela e pular linha
    printf("%d\n", sentinela);
    return 0;
}