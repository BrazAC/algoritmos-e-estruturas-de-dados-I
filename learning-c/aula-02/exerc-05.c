/*
UFMT - Estrutura de Dados
Exercicio: 05
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int val, resultado, resto;
    
    //lendo valor do usuario
    printf("Informe um número a ser dividido por 3: \n");
    scanf("%d", &val);

    //realizando a divisao
    resultado = val / 3;
    resto = val % 3;
    printf("Resultado inteiro: %d Resto: %d\n", resultado, resto);
}