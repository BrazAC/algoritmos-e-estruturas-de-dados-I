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
        //printf("[%d|%s|%d]\n", id_cat, nome, id_cat_pai);
        am_inserePorIdPai(arvore, id_cat, id_cat_pai, nome);
        
    }
}

void main_carregaProdutos(FILE* arquivo, tipo_noh_ab** arvore){
    //Levar cursor para o inicio da linha 1
    while(1){
        if(fgetc(arquivo) == '\n') break;
    }

    //Variaveis auxliares
    float preco;
    char codigo[MAX_CODIGO];
    char titulo[MAX_TITULO_PROD];
    float avaliacao;
    int id_cat;

    //Extrair dados
    char fstring[1000];
    int cont = 100000;
    while(fgets(fstring, 1000, arquivo) != NULL && cont > 0){
        cont --;
        //printf("%s\n", fstring);
        //Obtendo um ponteiro que aponta pra primeira virgula da string da esquerda pra direita
        char *prtVirgulaEsq = strchr(fstring, ',');

        //======|Cortar fora ultimos dois campos
        for(int i = 0; i < 2; i++){
            //Prt para primeira virgula da direita para esquerda
            char *prtVirgulaDir = strrchr(fstring, ',');
            //Cortar campo fora
            prtVirgulaDir[0] = '\0';
        }

        //======|Obter id_cat
        char *prtVirgulaDir = strrchr(fstring, ',');
        //Mover ponteiro 1 character a frente
        prtVirgulaDir = prtVirgulaDir + 1;
        //Casting e armazenamento da categoria
        id_cat = atoi(prtVirgulaDir);
        //Mover ponteiro 1 character a tras
        prtVirgulaDir = prtVirgulaDir - 1;
        //Cortar campo fora
        prtVirgulaDir[0] = '\0';
        //printf("%d\n", id_cat);

        //======|Remover campo list_price
        prtVirgulaDir = strrchr(fstring, ',');
        //Cortar campo fora
        prtVirgulaDir[0] = '\0';
        
        //======|Obter preco
        prtVirgulaDir = strrchr(fstring, ',');
        //Mover ponteiro 1 character a frente
        prtVirgulaDir = prtVirgulaDir + 1;
        //Casting e armazenamento do preco
        preco = atof(prtVirgulaDir);
        //Mover ponteiro 1 character a tras
        prtVirgulaDir = prtVirgulaDir - 1;
        //Cortar campo fora
        prtVirgulaDir[0] = '\0';
        
        //======|Remover campo reviews
        prtVirgulaDir = strrchr(fstring, ',');
        //Cortar campo fora
        prtVirgulaDir[0] = '\0';
        
        //======|Obter avaliacao
        prtVirgulaDir = strrchr(fstring, ',');
        //Mover ponteiro 1 character a frente
        prtVirgulaDir = prtVirgulaDir + 1;
        //Casting e armazenamento da avaliacao
        avaliacao = atof(prtVirgulaDir);
        //Mover ponteiro 1 character a tras
        prtVirgulaDir = prtVirgulaDir - 1;
        //Cortar campo fora
        prtVirgulaDir[0] = '\0';
        //printf("%f\n", avaliacao);

        //======|Remover campo productURL
        prtVirgulaDir = strrchr(fstring, ',');
        //Cortar campo fora
        prtVirgulaDir[0] = '\0';
        
        //======|Remover campo imgUrl
        prtVirgulaDir = strrchr(fstring, ',');
        //Cortar campo fora
        prtVirgulaDir[0] = '\0';

        //printf("%s\n", fstring);
        //-----------------------------|Se o nome tem virgula
        if(prtVirgulaEsq[1] == '"'){
            //======|Obter titulo
            //Mover ponteiro 1 character a tras
            prtVirgulaDir = prtVirgulaDir - 1;
            //Cortar aspas fora
            prtVirgulaDir[0] = '\0';
            //Prt primera aspas da esquerda para direita
            char* prtAspas = strchr(fstring, '"');
            //Mover ponteiro um espaco de memoria a frente
            prtAspas = prtAspas + 1;
            //Copiar string do prtAspas para nome
            strcpy(titulo, prtAspas);
            //Mover ponteiro 2 character a tras
            prtAspas = prtAspas - 2;
            //Cortar titulo fora
            prtAspas[0] = '\0';

            //======|Obter codigo
            strcpy(codigo, fstring);
        }
        //-----------------------------|Se o nome NAO tem virgula
        else{
            //======|Obter titulo
            //Mover prt da virgula esq, 1 para frente
            prtVirgulaEsq = prtVirgulaEsq + 1;
            //Copiar titulo
            strcpy(titulo, prtVirgulaEsq);
            //Mover prt da virgula esq, 1 para tras
            prtVirgulaEsq = prtVirgulaEsq - 1;
            //Cortar nome fora
            prtVirgulaEsq[0] = '\0';
            //printf("%s\n", titulo);
            //======|Obter codigo 
            strcpy(codigo, fstring);
            //printf("%s\n", codigo);
        }

        //Inserir dados extraidos na arvore binaria
        //printf("[%-7.2f|%10s|%3d|%2.1f|%200s]\n",preco,codigo,id_cat,avaliacao,titulo);
        ab_insere(arvore, preco, codigo, titulo, avaliacao, id_cat);
    }
}

