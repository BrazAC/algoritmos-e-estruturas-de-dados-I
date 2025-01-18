#include <stdlib.h>
#include <stdio.h>
#include <string.h>

enum statusAlit {
    FALSE,
    TRUE
};

int main(){
    //-> Alocacao de memoria
    //Declarar vetor de char frase[]
    char frase[5100];
    //Declarar vetor de char primeirasLetras[quantidade de palavras da frase]
    char primeirasLetras[101];
    //Declarar variavel inteira aliteracao
    int contAliteracao = 0;
    //Inicializar variavel do tipo statusAlit chamada ultimoStatus como false
    enum statusAlit ultimoStatus = FALSE;

    //-> Obtencao de info
    //Obter a frase informada enquanto a entrada nao for EOF, armazenar em frase e realizar logica
    while (fgets(frase, 5100, stdin) != NULL) {
        //-> Limpeza da entrada 
        //Remover character de quebra de linha se existir
        size_t tamanho = strlen(frase);
        if (frase[tamanho - 1] == '\n') {
            frase[tamanho - 1] = '\0';
        }
        
        //-> Obter primeiras letras da frase
        //Guardar o primero char de frase em primeirasLetras[0] 
        int contPrimeirasLetras = 0;
        primeirasLetras[contPrimeirasLetras] = frase[0];

        //Iterar pelos char de frase a partir do segundo char
        for (int i = 1; i < (tamanho - 1); i++) {
            //Detectar inicio de uma palavra
            //se char atual == ' ' nova palavra!
            if (frase[i] == ' ') {
                //adicionar o proximo char de frase em primeirasLetras
                contPrimeirasLetras ++;
                primeirasLetras[contPrimeirasLetras] = frase[i + 1];
            }
        }
        //Indiciar fim do vetor primeirasLetras
        primeirasLetras[contPrimeirasLetras + 1] = '\0';

        int contTeste = 0;
        while (primeirasLetras[contTeste] != '\0') {
            if (primeirasLetras[contTeste + 1] == '\0') {
                //printf("%c\n", primeirasLetras[contTeste]);
                contTeste ++;
            }
            else {
                //printf("%c ", primeirasLetras[contTeste]);
                contTeste ++;
            }
        }

        //-> Determinar aliteracoes
        //Iterar por primeirasLetras a partir da segunda letra
        int tamanhoPrimeirasLetras = contTeste;
        for (int j = 1; j < tamanhoPrimeirasLetras; j++) {
            char letraAtual = primeirasLetras[j];
            char letraAnterior = primeirasLetras[j - 1];
            //printf("LETRAS: %c - %c\n", letraAtual, letraAnterior);
            //Se (letra atual == letra anterior) e as letras forem iguais mas diferentes em lowercase ou highcase 
            if (letraAtual == letraAnterior || letraAtual - letraAnterior == 32 || letraAtual - letraAnterior == -32) {
                //Se  ultimoStatus == FALSE
                if (ultimoStatus == FALSE) {
                    //printf("Aliteracao: %c - %c\n", letraAtual, letraAnterior);
                    //somar um em aliteracao
                    contAliteracao ++;
                    //ultimoStatus = TRUE
                    ultimoStatus = TRUE;
                }
                
            }
            //Se (letra atual != letra anterior)
            if (letraAtual != letraAnterior && letraAtual - letraAnterior != 32 && letraAtual - letraAnterior != -32) {
                //printf("Nao aliteracao: %c - %c\n", letraAtual, letraAnterior);
                //ultimoStatus = FALSE
                ultimoStatus = FALSE;
            }
        }
        //Mostrar o valor de aliteracoes
        printf("%d\n", contAliteracao);

        //Zerar contAliteracao para proximo uso
        contAliteracao = 0;

        //Resetar ultimoStatus
        ultimoStatus = FALSE;
    }
        
    return 0;
}