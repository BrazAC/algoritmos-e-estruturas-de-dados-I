/*
Aluno: Braz
Exercicio: 02
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    //Declaracao de variaveis
    char c1, c2, c3, c4;
    char ma, me;

    //Obter letras
    printf("Insira as letras separadas por um espaco: ");
    scanf("%c %c %c %c", &c1, &c2, &c3, &c4);

    //Identificar primeira e ultima letra
    ma = c1;
    me = c1;

    //Identificar primeira letra
    if(c1 < me){
        me = c1;
    }
    if(c2 < me){
        me = c2;
    }
    if(c3 < me){
        me = c3;
    }
    if(c4 < me){
        me = c4;
    }
    
    //Identificar ultima letra
    if(c1 > ma){
        ma = c1;
    }
    if(c2 > ma){
        ma = c2;
    }
    if(c3 > ma){
        ma = c3;
    }
    if(c4 > ma){
        ma = c4;
    }
    
    //Imprimir info
    printf("Sequencia: %c -> %c \n", me, ma);

    return 0;
}