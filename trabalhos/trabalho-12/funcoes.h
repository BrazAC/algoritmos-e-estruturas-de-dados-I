#ifndef __FUNCOES_H__
#define __FUNCOES_H__

#define MAX_DADOS_CAT (10 + 100) 
#define MAX_NOME_CAT 100

typedef struct est_categoria{
    int id;
    char nome[MAX_NOME_CAT];
    int id_pai;
} tipo_categoria;

typedef struct est_noh_am{
    tipo_categoria dados[MAX_DADOS_CAT];
    struct est_noh_am* filhos[MAX_DADOS_CAT + 1];
    int cont;
    //tipo_no_ab *ref_arv_produtos;
} tipo_noh_am;

//--------------------------Funcoes arvore n-aria
//Insercao
tipo_noh_am* alocaNohAm(int id_cat, int id_pai_cat, char nome_cat[]);
void am_inserePorIdPai(tipo_noh_am **noh, int id_cat, int id_pai_cat, char nome_cat[]);
//Visualizacao 
void am_mostraNivel(tipo_noh_am *noh, int nivel);
void am_mostraArv(tipo_noh_am *noh);
void am_preOrdem(tipo_noh_am *noh);
#endif