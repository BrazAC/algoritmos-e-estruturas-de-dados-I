/*
ALuno: Braz Amorim
Exercicio: 01
*/
#include <stdlib.h>
#include <stdio.h>


int main(){
    //Declaracao de variaveis
    float val1, val2, val3, media;
    
    //Obter valores
    printf("Insira val1: ");
    scanf("%f", &val1);

    printf("Insira val2: ");
    scanf("%f", &val2);

    printf("Insira val3: ");
    scanf("%f", &val3);
    
    //Calcular a media
    media = (val1 + val2 + val3) / 3.0;
    printf("Media: %f\n", media);   

    //Descobrir se algum dos valores lidos coincide com a media
    if(media == val1){
        printf("Media e igual ao valor 1\n");
    }else if(media == val2){
        printf("Media e igual ao valor 2\n");
    }else if(media == val3){
        printf("Media e igual ao valor 3\n");
    }else{
        printf("Nenhum valor igual a media\n");
    }

    return 0;
}