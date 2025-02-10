#include <stdio.h>
#include <stdlib.h>

int main(){
    //-- Alocacao de memoria
    char frase[51];
    char hiddenMessage[51];
    int testCases;

    //-- Obter quantidade de testCases e executar programa
    scanf("%d", &testCases);
    
    //Limpar buffer
    getchar();

    //Repetir testCases vezes
    for (int n = 0; n < testCases; n++) {
        //-- Obter frase
        fgets(frase, 51, stdin); //51

        //-- Retirar \n da frase se existir
        int tamanhoFrase = 0;
        //Identificar tamanho da frase
        while (frase[tamanhoFrase] != '\0') {
            tamanhoFrase ++;
        }
        //Retirar \n se esse existir
        if (frase[tamanhoFrase - 1] == '\n'){
            frase[tamanhoFrase - 1] = '\0';
            tamanhoFrase --;
        }

        //--Verificar se a frase e apenas espacos vazios
        int mensagemVazia = 1, contadorVazia = 0;
        while(frase[contadorVazia] != '\0'){
            if (frase[contadorVazia] != ' ') {
                mensagemVazia = 0;
                break;
            }
            contadorVazia ++;
        }

        //-- Caso a frase nao seja vazia: Identificar mensagem escondida
        if (mensagemVazia == 0) {
            //Inicializar var control
            int posicaoInicialFrase = 0, posicaoInicialHiddenMessage = 0;
            //Verificar primeiro char de frase, se for != de espaco
            if(frase[0] != ' '){
                //hiddenMessage[0] = primeiro char de frase
                hiddenMessage[0] = frase[0];
                //Atualizar control
                posicaoInicialFrase = 1;
                posicaoInicialHiddenMessage = 1;
            }

            //Iterar por frase a partir do segundo char
            int i = posicaoInicialFrase;
            int contadorHiddenMessage = posicaoInicialHiddenMessage;
            while (frase[i] != '\0'){
                //Se encontrar char == espaco
                if (frase[i] == ' ' && frase[i + 1] != ' ') {
                    //Se o proximo char for != de espaco
                        //hiddenMessage[count] = proximo char
                        hiddenMessage[contadorHiddenMessage] = frase[i + 1];
                        //Aumentar o valor de count em um
                        contadorHiddenMessage ++;
                }
                i ++;
            }

            //Indicar o fim de hiddenMessage
            //hiddenMessage[count + 1] = '\0'
            hiddenMessage[contadorHiddenMessage] = '\0';

            //-- Mostrar o conteudo de hiddenMessage
            printf("%s\n", hiddenMessage);
        }
    }

    return 0;
}