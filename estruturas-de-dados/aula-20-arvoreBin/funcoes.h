#ifndef __FUNCOES_H__
#define __FUNCOES_H__


struct est_noArv{
    int dado;
    int chave;
    struct est_noArv *esq;
    struct est_noArv *dir;
};
typedef struct est_noArv est_noArv;

est_noArv* alocaNo(int chave, int dado);
void arv_insere(est_noArv** noArv, int chave, int valor);

void percurso_preOrdem(est_noArv *noArv);
void percurso_Ordem(est_noArv *noArv);
void percurso_posOrdem(est_noArv *noArv);

//Aula 10/04
//Feito
int arv_totalDeNos(est_noArv *noArv);
int arv_totalDeFolhas(est_noArv *noArv);
est_noArv* arv_buscaNo(est_noArv *noArv, int chave);
int arv_eFolha(est_noArv *noArv, int chave);
int arv_altura(est_noArv *noArv);
void imprime_nivel(est_noArv *noArv, int nivel, int max_nivel);
void imprime_arv_nivel(est_noArv *noArv);
int contabiliza_nos_nivel(est_noArv *noArv, int nivel);
void imprime_rota(est_noArv *noArv, int chave); //Ate o no que eu quero
//Falta
est_noArv* arv_menorVal(est_noArv *noArv);
est_noArv remove_no(est_noArv *noArv, int chave);



#endif