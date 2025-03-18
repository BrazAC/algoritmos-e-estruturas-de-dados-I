#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <string.h>
#include <math.h>

/*
Trabalho de ED1
Alunos: Braz Amorim
        Gregório Tavares
        
*/


/*
Creating a new file – fopen() with attributes as “a” or “a+” or “w” or “w+”
Opening an existing file – fopen()
Reading from file – fscanf() or fgets()
Writing to a file – fprintf() or fputs()
Moving to a specific location in a file – fseek(), rewind()
Closing a file – fclose()
*/

int main(int argc, char *argv[]){
    char* quantElementos = argv[1]; 
    
    //==VERIFICACAO ARGC
    if (argc == 2) {
        //Converter entrada de string para inteiro
        int tamanhoString = strlen(quantElementos);
        int quantElementosInt = 0, potencia = tamanhoString - 1;
        for (int i = 0; i < tamanhoString; i++) {
            quantElementosInt += (quantElementos[i] - '0') * (pow(10, potencia));
            potencia --;
        }

        //Verificar se quantElementosInt é valido
        if (quantElementosInt > 100000 || quantElementosInt < 1) {
            printf("[ERRO] Quantidade de elementos invalida, insira um valor entre 1 e 100.000\n");
            return 0;
        }

        //==REPETIR 5 VEZES
            //==Criar lista
            lista_estatica lista;
            lista.contador = 0;

            //==Inicializar lista
            inserir_lista(&lista);
                //Repetir quantElementos vezes
                    //faca
                        //Gera valor aleatorio
                        //Itera pela lista conferindo se ha o numero aleatorio
                    //enquanto (valor gerado existir na lista)
                    //Inserir no final da lista o valor aleatorio gerado

            //==Criar arquivo com valores da lista
                //Chamar a funcao que cria arquivo
                //0bs: Seguir padrão de nome
    }
    else{
        printf("[ERRO] Quantidade de argumentos invalida\n");
    }

    return 0;
}