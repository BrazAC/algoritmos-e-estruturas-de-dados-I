#include <stdio.h>
#include <stdlib.h>

int main(){
    //Criar 2 vetores de char (50 espaços), 1 vetor de char (100 espaços)
    char primeiraString[50], segundaString[50], stringFinal[101];
    
    //Receber quantidade de recepcoes
    int N;
    scanf("%d", &N);

    //Repetir N vezes
    for (int i = 0; i < N; i++) {
        //Receber strings, guardar nos dois vetores de 50 espaços
        scanf("%s %s", primeiraString, segundaString);

        //Iinicializar contadorPosicionadorStringFinal com 0
        int contadorPosicionadorStringFinal = 0;
        //Inicializar contadorStrings com 0
        int contadorStrings = 0;

        //Repetir
        while (1){
            //Verificar se o char atual primeira string é diferente de '\0'
            //Se sim:
            if (primeiraString[contadorStrings] != '\0') {
                //char atual na posicao contadorStrings vai pra posicao contadorPosicionadorStringFinal na string final
                stringFinal[contadorPosicionadorStringFinal] = primeiraString[contadorStrings];
            }
            //Se nao:
            else{
                //Iniciar um novo loop que preenche a string final com os resto da segunda string
                //Repetir enquanto char atual da segunda string != '/0'
                while (segundaString[contadorStrings] != '\0') {
                    //char na posicao contadorPosicionadorStringFinal da string final receber char atual da segunda string posicao = contadorStrings
                    stringFinal[contadorPosicionadorStringFinal] = segundaString[contadorStrings];
                    //contadorPosicionadorStringFinal aumenta 1
                    contadorPosicionadorStringFinal ++;
                    //contadorStrings aumenta 1
                    contadorStrings ++;
                }
                //Indicar para o compilador que stringFinal acabou
                stringFinal[contadorPosicionadorStringFinal] = '\0';
                //Encerrar loop externo
                break;
            }

            //contadorPosicionadorStringFinal aumenta 1
            contadorPosicionadorStringFinal ++;

            //Verificar se o char atual segunda string é diferente de '/0'
            if (segundaString[contadorStrings] != '\0') {
            //Se sim:
                //char atual na posicao contadorStrings vai pra posicao contadorPosicionadorStringFinal na string final
                stringFinal[contadorPosicionadorStringFinal] = segundaString[contadorStrings];
            }
            //Se nao:
            else{
                //Iniciar um novo loop que preenche a string final com os resto da primeira string
                //contadorStrings aumenta 1
                contadorStrings ++;
                //Repetir enquanto char atual da primeira string != '/0'
                while (primeiraString[contadorStrings] != '\0') {
                    //char na posicao contadorPosicionadorStringFinal da string final receber char atual da primeira string posicao = contadorStrings
                    stringFinal[contadorPosicionadorStringFinal] = primeiraString[contadorStrings];
                    //contadorPosicionadorStringFinal aumenta 1
                    contadorPosicionadorStringFinal ++;
                    //contadorStrings aumenta 1
                    contadorStrings ++;
                }
                //Indicar para o compilador que stringFinal acabou
                stringFinal[contadorPosicionadorStringFinal] = '\0';
                //Encerrar loop externo
                break;
            }
            //contadorPosicionadorStringFinal aumenta 1
            contadorPosicionadorStringFinal ++;
            //contadorStrings aumenta 1
            contadorStrings ++;
        }

        //Mostrar stringFinal
        printf("%s\n", stringFinal);
    }
    return 0;
}