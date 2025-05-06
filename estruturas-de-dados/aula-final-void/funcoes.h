#ifndef __FUNCOES_H__
#define __FUNCOES_H__

typedef struct est_aluno{
    int rga;
    char nome[25];
} tipo_aluno;

typedef struct est_noh{
    void *dado;
    int chave;
    struct est_noh *esq;
    struct est_noh *dir;
} tipo_noh;

tipo_noh* alocaNoh(int chave, int rga, char nome[]);
void ab_insere(tipo_noh **noh, int chave, int rga, char nome[]);
void ab_mostraNivel(tipo_noh *noh, int nivel);

#endif