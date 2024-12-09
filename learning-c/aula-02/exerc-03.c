/*
Aluno: Braz
Exercicio: 03
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    //Declaracao de variaveis
    int n1, n2, menor, maior, iguais;
    iguais = 0;

    //Obter numeros inteiros
    printf("Insira dois valores separado por espaco: ");
    scanf("%i %i", &n1, &n2);

    //Identificar o menor ou se sao iguais
    if(n1 < n2){
        menor = n1;
        maior = n2;
    }else if(n2 < n1){
        menor = n2;
        maior = n1;
    }else{
        iguais = 1;
    }
    
    //Se forem iguais avisar, se nao for imprimir serie
    if(iguais){
        printf("Os numeros sao iguais!");
    }else{
        for(int i = menor; i <= maior; i++){
            printf("%i\n", i);
        }
    }
}