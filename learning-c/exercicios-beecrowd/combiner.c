#include <stdio.h>
#include <stdlib.h>

int main(){
    //Criar 2 vetores de char (50 espaços)
    //Criar 1 vetor de char (100 espaços)
    
    //Receber strings, guardar nos dois vetores de 50 espaços

    //Iinicializar contadorPosicionadorStringFinal com 0
    //Inicializar contadorStrings com 0

    //Repetir
        //Verificar se o char atual primeira string é diferente de '/0'
        //Se sim:
            //char atual na posicao contadorStrings vai pra posicao contadorPosicionadorStringFinal na string final
        //Se nao:
            //Iniciar um novo loop que preenche a string final com os resto da segunda string
            //Repetir enquanto char atual da segunda string != '/0'
                //char na posicao contadorPosicionadorStringFinal da string final receber char atual da segunda string posicao = contadorStrings
                //contadorPosicionadorStringFinal aumenta 1
                //contadorStrings aumenta 1
            //Encerrar loop

        //contadorPosicionadorStringFinal aumenta 1

        //Verificar se o char atual segunda string é diferente de '/0'
        //Se sim:
            //char atual na posicao contadorStrings vai pra posicao contadorPosicionadorStringFinal na string final
        //Se nao:
            //Iniciar um novo loop que preenche a string final com os resto da primeira string
            //contadorStrings aumenta 1
            //Repetir enquanto char atual da primeira string != '/0'
                //char na posicao contadorPosicionadorStringFinal da string final receber char atual da primeira string posicao = contadorStrings
                //contadorPosicionadorStringFinal aumenta 1
                //contadorStrings aumenta 1
            //Encerrar loop

        //contadorPosicionadorStringFinal aumenta 1
        //contadorStrings aumenta 1
    
    //Mostrar stringFinal

    return 0;
}