/*
UFMT - Estrutura de Dados
Exercicio: 04
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int val1, val2, resultado, contador;
    
    //lendo valores do usuário
    printf("Infome os valores a serem multiplicados: \n");
    scanf("%d %d", &val1, &val2);
    resultado = 0;
    //executando a multiplicacao om somas sucessivas
    for (contador = 1; contador <= val2; contador++){
        resultado += val1;
    }
    printf("Resultado final: %d\n", resultado);
    return 0;
}