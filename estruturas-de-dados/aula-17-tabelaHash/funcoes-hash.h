#ifndef __FUNCOES_HASH_H__
#define __FUNCOES_HASH_H__

#define MAX_HASH 10 

typedef struct est_no_hash{
    int chave;
    int dado1;
    int dado2;
    struct est_no_hash *prox;
} est_no_hash;

typedef struct est_tabelaHash{
    est_no_hash* tabela[MAX_HASH];
    int cont; //Não é necessário, mas pode ter
} est_tabelaHash;

//Tabela hash
int fHash(int);
void inicializaTabHash(est_tabelaHash*);
est_no_hash* buscaTabHash(est_tabelaHash*, int);
void insereTabHash(est_tabelaHash*, int, int, int);
int removeTabHash(est_tabelaHash*, int);

void mostraTabHash(est_tabelaHash);


//Lista encadeada (TRATAMENTO DE COLISAO)
est_no_hash* alocaNoHash(int, int, int);
void listaDin_insereInicio(est_no_hash**, est_no_hash*);
int listaDin_RemovePorChave(est_no_hash**, int);
est_no_hash* listaDin_buscaPorChave(est_no_hash**, int);
void listaDin_mostra(est_no_hash*);

#endif