#ifndef __FUNCOES_H__
#define __FUNCOES_H__

#define T 3

typedef struct est_dado{
    char dado;
    int chave;
}tipo_dado;

typedef struct est_no_arvM{
    tipo_dado dados[T];
    int contDados;

    //Vetor de prt dos filhos
    struct est_no_arvM *proxs[T + 1];
} tipo_no_arvM;

//Insercao
tipo_no_arvM *alocaNoh(char dado, int chave);
void arvMultNo_insere(tipo_no_arvM **nohArv, char dado, int chave);

//Percursos
void arvMultNo_preOrdem(tipo_no_arvM *nohArv);
void arvMultNo_posOrdem(tipo_no_arvM *nohArv);
void arvMultNo_Ordem(tipo_no_arvM *nohArv);

//Gerais
int arvMultNo_totalNos(tipo_no_arvM *nohArv);
int arvMultNo_totalFolhas(tipo_no_arvM *nohArv);
tipo_no_arvM* arvMultNo_buscaNo(tipo_no_arvM *nohArv, int chave);
tipo_dado* arvMultNo_buscaDado(tipo_no_arvM *nohArv, int chave);

//Remocao
tipo_dado arvMultNo_remove(tipo_no_arvM **noh, int chave);


#endif