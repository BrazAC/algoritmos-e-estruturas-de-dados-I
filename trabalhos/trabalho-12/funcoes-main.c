#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
#include <string.h>

void main_carregaPrincipais(FILE* arquivo, tipo_noh_am** arvore){
    //Levar cursor para o inicio da linha 3
    for(int i = 0; i < 2; i++){
        while(1){
            if(fgetc(arquivo) == '\n') break;
        }
    }

    //Extrair dados
    int id_cat, id_cat_pai;
    char nome[MAX_NOME_CAT], fstring[MAX_DADOS_CAT];

    while(fgets(fstring, MAX_DADOS_CAT, arquivo) != NULL){
        sscanf(fstring, "%d,%[^,],%d", &id_cat, nome, &id_cat_pai);
        //printf("[%d|%s|%d]\n", id_cat, nome, id_cat_pai);
    
        //Inserir na arvore
        
        am_inserePorIdPai(arvore, id_cat, id_cat_pai, nome);
    }

}

void main_carregaSecundarias(FILE* arquivo, tipo_noh_am** arvore){
    //Levar cursor para o inicio da linha 1
    while(1){
        if(fgetc(arquivo) == '\n') break;
    }
    
    //Variaveis auxiliares
    char *tokens[3];
    char *token;
    int contTokens = 0;

    //Extrair dados
    int id_cat, id_cat_pai;
    char nome[MAX_NOME_CAT], fstring[MAX_DADOS_CAT];

    while(fgets(fstring, MAX_DADOS_CAT, arquivo) != NULL){
        //Obtendo um ponteiro que aponta pra primeira virgula da string da esquerda pra direita
        char *prtVirgula = strchr(fstring, ',');
        
        //-----------------------------|Se o nome tem virgula
        if(prtVirgula[1] == '"'){
            //======|Obter id_cat_pai
            //Prt primera aspas da direita para esquerda
            char *prtAspas = strrchr(fstring, '"');
            //Convertendo id_cat_pai para inteiro
            id_cat_pai = prtAspas[2] - '0';
            //Finalizando string logo na ultima aspas
            prtAspas[0] = '\0';

            //======|Obter nome
            //Prt primera aspas da esquerda para direita
            prtAspas = strchr(fstring, '"');
            //Mover ponteiro um espaco de memoria a frente
            prtAspas = prtAspas + 1;
            //Copiar string do prtAspas para nome
            strcpy(nome, prtAspas);

            //======|Obter id_cat
            //Mover ponteiro dois espacos de memoria para tras
            prtAspas = prtAspas - 2;
            //Finalizando string logo na primeira virgula
            prtAspas[0] = '\0';
            id_cat = atoi(fstring);
        }
        //-----------------------------|Se o nome NAO tem virgula
        else{
            //---Logica da funcao strtok
            //Inicializar token (pegar primeiro string antes de "," o id da categoria)
            token = strtok(fstring, ",");
            //Guardar na lista de tokens
            tokens[contTokens] = token;
            //Obter resto dos dados da linha
            while (token != NULL) {
                //Extrair proximo token (proxima string)
                token = strtok(NULL, ",");
                
                //Extraindo apenas primeiras 3 strings da linha
                contTokens ++;
                if(contTokens == 3){ 
                    break;
                }
                else{
                    //Guardar na lista de tokens
                    tokens[contTokens] = token;
                } 
            }
            contTokens = 0;

            //---Guardar dados no nohAux, realizando as conversoes
            //id_cat
            id_cat = atoi(tokens[0]);
            //nome
            strcpy(nome, tokens[1]);
            //id_cat_pai
            id_cat_pai = atoi(tokens[2]);
        }

        //Inserir na arvore
        printf("[%d|%s|%d]\n", id_cat, nome, id_cat_pai);
        am_inserePorIdPai(arvore, id_cat, id_cat_pai, nome);
    }
}