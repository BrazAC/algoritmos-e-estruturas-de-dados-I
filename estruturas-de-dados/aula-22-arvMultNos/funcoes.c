#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

tipo_no_arvM *alocaNoh(char dado, int chave){
    tipo_no_arvM *novoNoh = (tipo_no_arvM*)malloc(sizeof(tipo_no_arvM));

    //Inicializar ponteiros proxs
    for (int i = 0; i < (T + 1); i++){
        novoNoh->proxs[i] = NULL;
    }

    //Cadastrar primeiro dado (sempre acontece no momento de alocacao do noh)
    novoNoh->dados[0].chave = chave;
    novoNoh->dados[0].dado = dado;

    //Inicializar contador (comeca valendo 1)
    novoNoh->contDados = 1;

    //Retorar endereco do noh
    return novoNoh;

}

void arvMultNo_insere(tipo_no_arvM **nohArv, char dado, int chave){
    if(*nohArv == NULL){
        *nohArv = alocaNoh(dado, chave);
        //printf("[%c|%d]", (*nohArv)->dados[0].dado, (*nohArv)->dados[0].chave);
    }
    else{
        //O noh atual tem espaco?
        if ((*nohArv)->contDados < T) {
            //----------------------------------Fazer insercao ordenada
            int i, chaveNaArv, minhaChave = chave;

            //Percorrer lista da dados do noh atual
            for (i = 0; i < (*nohArv)->contDados; i++) {
                chaveNaArv = (*nohArv)->dados[i].chave;

                if (chaveNaArv > minhaChave) {
                    //Mover elementos da posicao atual pra frente 1 casa
                    for (int j = (*nohArv)->contDados; j > i; j--){
                        (*nohArv)->dados[j] = (*nohArv)->dados[j - 1];
                    }
                    //printf("[%c|%d]", (*nohArv)->dados[i].dado, (*nohArv)->dados[i].chave);
                    //Parar loop
                    break;
                }
            }
            //Inserir dado na posicao atual
            (*nohArv)->dados[i].dado = dado;
            (*nohArv)->dados[i].chave = chave;
            (*nohArv)->contDados ++;
        }
        //Se nao tem espaco
        else{
            //Encontrar o filho apropriado e fazer chamada recursiva pra ele
            int chaveNaArv, minhaChave = chave;

            //Percorrer lista de dados do noh atual procurando a pos
            int pos;
            for(pos = 0; pos < T; pos++){
                chaveNaArv = (*nohArv)->dados[pos].chave;
            
                if(chaveNaArv > minhaChave){
                    break;
                }
            }
            //Chamada recusiva na pos encontrada no vetor de proxs nohs
            arvMultNo_insere(&((*nohArv)->proxs[pos]), dado, chave);
        }
    }
}

void arvMultNo_preOrdem(tipo_no_arvM *nohArv){
    if (nohArv == NULL) {
        return;
    }
    else{
        //Acessar os dados
        for (int i = 0; i < nohArv->contDados; i++){
            printf("[%c|%d]", nohArv->dados[i].dado, nohArv->dados[i].chave);
        }
        printf("\n");

        //Chamar recursivamente para os filhos
        for (int i = 0; i < (T + 1); i++){
            arvMultNo_preOrdem(nohArv->proxs[i]);
        }
    }
}

void arvMultNo_posOrdem(tipo_no_arvM *nohArv){
    if (nohArv == NULL) {
        return;
    }
    else{
        //Chamar recursivamente para os filhos
        for (int i = 0; i < (T + 1); i++){
            arvMultNo_preOrdem(nohArv->proxs[i]);
        }

        //Acessar os dados
        for (int i = 0; i < nohArv->contDados; i++){
            printf("[%c|%d]", nohArv->dados[i].dado, nohArv->dados[i].chave);
        }
        printf("\n");        
    }
}

void arvMultNo_Ordem(tipo_no_arvM *nohArv){
    if (nohArv == NULL) {
        return;
    }
    else{
        //Um looping apenas (iterar pelos dados)
        for (int i = 0; i < nohArv->contDados; i++){
            //Chamada recursiva para o da esquerda (perceba que na proxima chamada esse vira o da direita, e depois vira o da esquerda...)
            arvMultNo_preOrdem(nohArv->proxs[i]);
            //Acessar dado
            printf("[%c|%d]", nohArv->dados[i].dado, nohArv->dados[i].chave);
        }

        //Chamar recursivamente para o ponteiro da extrema direita que sobrou
        int posExtremoDireito = nohArv->contDados;
        arvMultNo_preOrdem(nohArv->proxs[posExtremoDireito]);
    }
}

int arvMultNo_totalNos(tipo_no_arvM *nohArv){
    if(nohArv == NULL){
        return 0;
    }
    else{
        //Se vetDados nao estiver cheio, eu nao tenho filhos
        if(nohArv->contDados < T){
            return 1;
        }
        //Se estiver, eu TALVEZ tenho filhos
        else{
            //Se nao e nulo eu automaticamente tenho 1 noh
            int cont = 1;

            //Chamar recursivamente para os outros filhos
            for (int i = 0; i < (T + 1); i++) {
                cont += arvMultNo_totalNos(nohArv->proxs[i]);
            }

            return cont;
        }
    }
}

int arvMultNo_totalFolhas(tipo_no_arvM *nohArv){
    if (nohArv == NULL){
        return 0;
    }
    else{
        //Verificar se é folha
        int flagFolha = 1;
        for (int i = 0; i < (T + 1); i ++) {
            if(nohArv->proxs[i] != NULL){
                flagFolha = 0;
            }
        }

        //Se for folha retorna 1
        if (flagFolha) {
            return 1;
        }
        //Se nao for folha retorna a soma dos retornos das chamdas recursivas para todos os filhos
        else{
            int contFolha = 0;
            //Chamar pra todos os filhos somando os retornos em contFolha
            for (int i = 0; i < (T+1); i++) {
                tipo_no_arvM *proxAtual = nohArv->proxs[i];
                contFolha += arvMultNo_totalFolhas(proxAtual);
            } 
            //Retornar contFolha
            return contFolha;
        }
    }
}

tipo_no_arvM* arvMultNo_buscaNo(tipo_no_arvM *nohArv, int chave){

}