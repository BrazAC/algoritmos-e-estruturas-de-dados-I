/*
UFMT - Ciencia da Computacao
Estrutura de dados I
Aluno: Braz Amorim Campos
*/

#include <stdio.h>
#include <stdlib.h>

//Prototipagem de funcoes
void soma(int, int);

//Funcao main nao precisa de prototipagem
int main(){
    //Declaracao de variaveis
    int x, y;

    //Entrada de dados
    printf("Insira um valor: ");
    scanf("%d", &x);
    printf("Insira outro valor: ");
    scanf("%d", &y);
    
    //Usando funcao
    soma(x, y);

    return 0;
}

//Declaracao das funcoes prototipadas
void soma(int x, int y){
    int sum = x + y;
    printf("Resultado: %d\n", sum);
}