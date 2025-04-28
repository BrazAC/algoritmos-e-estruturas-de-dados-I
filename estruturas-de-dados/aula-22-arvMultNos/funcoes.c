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
    if (nohArv == NULL) {
        return NULL;
    }
    else{
        //Verificar se esse noh tem a chave que to procurando
        int flagNoh = 0, pos = 0;
        for (pos; pos < nohArv->contDados; pos++) {
            if (nohArv->dados[pos].chave == chave) {
                flagNoh = 1;
            }
        }
        
        //Se sim, retorna o noh
        if (flagNoh){
            return nohArv;
        }
        //Se nao, retorna a chamada recursiva para todos os filhos SE NAO FOR NULO
        else{
            tipo_no_arvM *retorno = NULL;
            int pos = 0;

            while(retorno == NULL && pos < (T + 1)){
                retorno = arvMultNo_buscaNo(nohArv->proxs[pos], chave);
                pos ++;
            }

            return retorno;
        }
    }
}

tipo_dado* arvMultNo_buscaDado(tipo_no_arvM *nohArv, int chave){
    if (nohArv == NULL) {
        return NULL;
    }
    else{
        //Verificar se esse noh tem a chave que to procurando
        int flagNoh = 0, pos = 0;
        for (int i = 0; i < nohArv->contDados; i++) {
            if (nohArv->dados[pos].chave == chave) {
                flagNoh = 1;
                pos = i;
            }
        }
        
        //Se sim, retorna o endereco do dado
        if (flagNoh){
            return &(nohArv->dados[pos]);
        }
        //Se nao, retorna a chamada recursiva para todos os filhos SE NAO FOR NULO
        else{
            tipo_no_arvM *retorno = NULL;
            int pos = 0;

            //Chamando para os filhos enquanto nao encontrar o alvo
            while(retorno == NULL && pos < (T + 1)){
                retorno = arvMultNo_buscaNo(nohArv->proxs[pos], chave);
                pos ++;
            }

            //Retornar o endereco do dado ou null
            if (retorno) {
                return &(retorno->dados[pos]);
            }
            else{
                return NULL;
            }
            
        }
    }
}

tipo_dado arvMultNo_remove(tipo_no_arvM **noh, int chave){
    if(noh != NULL){
        //Esse noh contem a chave que to procurando?
        int flagP = 0;
        for(int i = 0; i < (*noh)->contDados; i++){
            if((*noh)->dados[i].chave == chave){
                flagP = 1;
            }
        }

        //Se sim, remover
        if(flagP){
            //Identificar se é folha
            int flagFolha = 1;
            for(int j = 0; j <= (*noh)->contDados; j++){
                if((*noh)->proxs[j] != NULL){
                    flagFolha = 0;
                }
            }

            //Eh uma folha
            if (flagFolha){
                //So tem o primeiro elemento
                if((*noh)->contDados == 1){
                    tipo_dado dadoRm = (*noh)->dados[0];
                    free(*noh);
                    *noh = NULL;
                    return dadoRm;
                }
                //Tem mais de um elemento
                else{
                    //Remover o elemento e ordenar lista
                    int pos = 0;
                    while(pos < (*noh)->contDados && (*noh)->dados[pos].chave != chave){
                        pos ++;
                    }
                    tipo_dado dadoRm = (*noh)->dados[pos];

                    //ordenar lista
                    for(int i = pos; i < (*noh)->contDados - 1; i++){
                        (*noh)->dados[i] = (*noh)->dados[i+1];
                    }

                    //Decrementar contador
                    (*noh)->contDados --;

                    return dadoRm;
                }

            }
            //Nao e uma folha
            else{
                //Verifica se o DADO tem filho(s)
                //se: Tem filho esquerdo?
                    //Encontrar o maior valor do ramo esquerdo
                    //Sobrescrever o maior valor no dadoRm
                    //Remover o filho duplicado
                    //Retornar dadoRm

                //se nao se: Tem filho direito?
                    //Encontrar o menor valor do ramo direito
                    //Sobrescrever o menor valor no dadoRm
                    //Remover o filho duplicado
                    //Retornar dadoRm
                //se nao: Não tem filhos?
                    //Procura pelo primeiro filho a esquerda
                        //Quando encontrar:
                        //Procure pelo maior valor (chave) desse ramo
                        //Avance todos os dados 1 a frente
                        //Copie maior do ramo para o vetor de dados
                        //remova o dado removido
                    //Se nao tiver filho a esquerda: 
                        //Procura pelo primeiro filho a direita
                            //Quando encontrar:
                            //Procure pelo menor valor (chave) desse ramo
                            //Avance todos os dados 1 a tras
                            //Copie menor do ramo para o vetor de dados
                            //remova o dado removido
            }
            
        }
        //Se nao, procura a direcao correta e chama recursivamente o filho
        else{
            int pos = 0;
            while(pos < (*noh)->contDados && chave > (*noh)->dados[pos].chave){
                pos ++;
            }

            arvMultNo_remove(&(*noh)->proxs[pos], chave);
        }
    }
    else{
        tipo_dado dadoErro;
        dadoErro.chave = -1;
        return dadoErro;
    }
}

//V. PROFESSOR
/*
tipo_dado* arvMultNo_buscaDado(tipo_no_arvM *nohArv, int chave){
    if (nohArv == NULL) {
        return NULL;
    }
    
    int i;
    //Posicionar i em cima do alvo caso exista ou em cima da posicao do prox prt
    for (i = 0; i < nohArv->contDados && chave > nohArv->dados[i].chave; i++){
        i ++;   
    } 

    //Se a i apontar para o alvo
    if(i < nohArv->contDados && chave == nohArv->dados[i].chave){
        return &(nohArv->dados[i]);
    }
    else{
        return arvMultNo_buscaDado(nohArv->proxs[i], chave);
    }
}

int arvMultNo_totalNos(tipo_no_arvM *nohArv){
    int i, total = 0;
    if (nohArv != NULL){
        total ++;
        for (i = 0; i <= nohArv->contDados; i++){
            total += arvMultNo_totalNos(nohArv->proxs[i]);
        }
    }

    return total;
}

int arvMultNo_totalFolhas(tipo_no_arvM *nohArv){
    int i, flag, total;
    flag = 1;
    total = 0;
    if (nohArv != NULL) {
        for (i = 0;i <= nohArv->contDados; i++){
            if (nohArv->proxs[i] != NULL){
                flag = 0;
                total += arvMultNo_totalFolhas(nohArv->proxs[i]);
            }
        }

        if (flag){
            return 1;
        }
        else{
            return 0;
        }
    }
}
*/