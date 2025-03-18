/*
Universidade federal de Mato Grosso - Campus Araguaia
Trabalho de ED1
Alunos: Braz Amorim
        Gregório Tavares
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char *argv[]){
    char* quantElementos = argv[1]; 
    
    //Semente de números aleatórios
    srand(time(NULL));
    
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
        for (int i = 1; i <= 5; i++){
            //==Criar lista
            lista_estatica lista;
            lista.contador = 0;
            
            //==Preencher lista
            lista_inicializaEmbaralha(&lista, quantElementosInt);
            
            //==Criar arquivo com valores da lista
            //Gerar o nome do arquivo
            char numChar = i + '0';
            char *nomeArquivo = malloc(sizeof(char) * 50);
            strcpy(nomeArquivo, "./arquivos/");

            strcat(nomeArquivo, quantElementos);
            strcat(nomeArquivo, "-arq ");
            nomeArquivo[strlen(nomeArquivo) - 1] = numChar;
            strcat(nomeArquivo, ".txt");

            //Chamar a funcao que cria arquivo
            arquivo_gera(&lista, nomeArquivo);

            free(nomeArquivo);
        }
    }
    else{
        printf("[ERRO] Quantidade de argumentos invalida\n");
    }

}