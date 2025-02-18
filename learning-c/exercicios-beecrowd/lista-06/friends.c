#include <stdlib.h>
#include <stdio.h>
#include <string.h>  // Para strdup()

typedef struct tipo_no{
    char* nome;
    struct tipo_no *proximo;

} tipo_no;

tipo_no* criaNo(char*);
int listaDin_insere(tipo_no**, char*);
int listaDin_inserePos(tipo_no**, char*, char*);
char* listaDin_remove(tipo_no**);
int listaDin_mostra(tipo_no**);

int main() {
    //Inicializar listas
    tipo_no *prtBaseAmigosAntigos, *prtBaseAmigosNovos, *prtBaseAmigosRecomends;
    prtBaseAmigosAntigos = NULL;
    prtBaseAmigosNovos = NULL;
    prtBaseAmigosRecomends = NULL;

    //Obter listas de nomes amigos antigos
    char novoNome[20];
    while(scanf("%s", novoNome)){
        listaDin_insere(&prtBaseAmigosAntigos, novoNome);
        
        if(getchar() == '\n'){
            break;
        }
    }

    //Obter listas de nomes amigos novos
    while(scanf("%s", novoNome)){
        listaDin_insere(&prtBaseAmigosNovos, novoNome);
        
        if(getchar() == '\n'){
            break;
        }
    }
    
    //Obter nome amigo indicado
    char amigoIndicado[20];
    scanf("%s", amigoIndicado);
    getchar();

    //Preencher lista de amigos recomendados
    char *respNegativa = (char*)malloc(sizeof(char) * 3);
    respNegativa[0] = 'n';
    respNegativa[1] = 'a';
    respNegativa[2] = 'o';
    
    if (strcmp(amigoIndicado, respNegativa) == 0) {
        //Apenas adicionar ao final da lista de recomendados
        //Mover de listaAntigosAmigos
        char *nomeRemovido = listaDin_remove(&prtBaseAmigosAntigos);
        while(nomeRemovido != NULL){
            listaDin_insere(&prtBaseAmigosRecomends, nomeRemovido);
            nomeRemovido = listaDin_remove(&prtBaseAmigosAntigos);
        }
        //Mover de listaNovosAmigos
        nomeRemovido = listaDin_remove(&prtBaseAmigosNovos);
        while(nomeRemovido != NULL){
            listaDin_insere(&prtBaseAmigosRecomends, nomeRemovido);
            nomeRemovido = listaDin_remove(&prtBaseAmigosNovos);
        }
    }
    else{
        //Adicionar na posicao da string amigoIndicado
        //Mover de listaAntigosAmigos
        char *nomeRemovido = listaDin_remove(&prtBaseAmigosAntigos);
        while(nomeRemovido != NULL){
            listaDin_insere(&prtBaseAmigosRecomends, nomeRemovido);
            nomeRemovido = listaDin_remove(&prtBaseAmigosAntigos);
        }

        //Mover de listaNovosAmigos para a poiscao especifica a listaAmigosRecomends
        nomeRemovido = listaDin_remove(&prtBaseAmigosNovos);
        while(nomeRemovido != NULL){
            listaDin_inserePos(&prtBaseAmigosRecomends, nomeRemovido, amigoIndicado);
            nomeRemovido = listaDin_remove(&prtBaseAmigosNovos);
        }

    }

    //Mostrando lista de amigos recomendados
    listaDin_mostra(&prtBaseAmigosRecomends);

    return 0;
}

tipo_no* criaNo(char* novoNome){
    tipo_no *novoNo = (tipo_no*)malloc(sizeof(tipo_no));
    novoNo->nome = strdup(novoNome);
    novoNo->proximo = NULL;

    return novoNo;
}

int listaDin_insere(tipo_no** prtBase, char* novoNome){
    if ((*prtBase) == NULL) {
        (*prtBase) = criaNo(novoNome);
        return 0;
    }
    
    tipo_no *aux = (*prtBase), *novoNo = criaNo(novoNome);
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = novoNo;
}

int listaDin_inserePos(tipo_no** prtBase, char* novoNome, char* nomeAlvo){
    if ((*prtBase) == NULL) {
        (*prtBase) = criaNo(novoNome);
        return 0;
    }
    
    tipo_no *aux = (*prtBase); 
    tipo_no *novoNo = criaNo(novoNome);


    while(strcmp(aux->proximo->nome, nomeAlvo) != 0){
        aux = aux->proximo;
        if(aux == NULL) return- 1;
    }

    novoNo->proximo = aux->proximo;
    aux->proximo = novoNo;
}

int listaDin_mostra(tipo_no** prtBase){
    if ((*prtBase) == NULL) {
        return -1;
    }

    tipo_no *aux = (*prtBase);
    printf("%s ", aux->nome);
    aux = aux->proximo;

    while(aux->proximo != NULL){
        printf("%s ", aux->nome);
        aux = aux->proximo;
    }
    printf("%s\n", aux->nome);
}

char* listaDin_remove(tipo_no** prtBase){
    if((*prtBase) == NULL){
        return NULL;
    }

    tipo_no *aux = (*prtBase);
    char *nomeRm = strdup(aux->nome);
    (*prtBase) = (*prtBase)->proximo;
    free(aux);
    return nomeRm; 
}