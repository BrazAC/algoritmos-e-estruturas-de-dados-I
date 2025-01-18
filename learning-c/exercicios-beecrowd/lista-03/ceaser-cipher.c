#include <stdio.h>
#include <stdlib.h>

//Definir constante para quantidade de letras do alfabeto chamada TAM_ALFABETO
#define TAM_ALFABETO 26

int main(){
    //cadastrar alfabeto no vetor de chars vetAlfabeto
    char vetAlfabeto[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    //Declarar cripPalavra, descripPalavra e cripPasso
    char cripPalavra[51], descripPalavra[51];
    int cripPasso, N; 

    //Obter quantidade de casos
    scanf("%d", &N);

    //Repetir N vezes
    for (int i = 0; i < N; i++) {
        //Obter palavra criptografada, guardar em cripPalavra
        scanf("%s", cripPalavra);
        //Obter passo da criptografia, guardar em cripPasso
        scanf("%d", &cripPasso);

        //Inicializar cont com 0
        int cont = 0;

        //Declarar posAlfabeto 
        int posAlfabeto;

        //Repetir enquanto cripPalavra[cont] != '\0'
        while (cripPalavra[cont] != '\0') {
            //Inicializar posAlfabeto com 0
            posAlfabeto = 0;

            //Guardar letra atual em letraAtual
            char letraAtual = cripPalavra[cont];

            //Repetir sempre
            while (1) {
                //se letraAtual != vetAlfabeto[posAlfabeto]
                if (letraAtual != vetAlfabeto[posAlfabeto]) {
                    //aumentar posAlfabeto em 1
                    posAlfabeto ++;
                //caso contrario
                }else{ 
                    //encerrar loop
                    break;
                }
            }

            //Calcular a posicao da letra descriptografada 
            int posDecrip = posAlfabeto - cripPasso;

            //Se posDecrip for negativa tratar a posicao
            if (posDecrip < 0) {
                posDecrip = TAM_ALFABETO + posDecrip;
            }

            //Atualizar palavra final
            descripPalavra[cont] = vetAlfabeto[posDecrip];

            //cont aumenta em 1
            cont ++;
        }

        //Especificar que descripPalavra finalizou
        descripPalavra[cont] = '\0';

        //Mostrar descripPalavra
        printf("%s\n", descripPalavra);
    }
    return 0;
}