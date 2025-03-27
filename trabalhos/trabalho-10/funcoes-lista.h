#ifndef __FUNCOES_LISTA_H__
#define __FUNCOES_LISTA_H__

#define MAX_CHAR_TITULO 100
#define MAX_CHAR_GENERO 200
#define MAX_ELEM_RATINGS_CSV 32000204

typedef struct est_no {
    int userId;
    int movieId;
    float rating;

    char title[MAX_CHAR_TITULO];
    int year;
    char genre[MAX_CHAR_TITULO];
    
    struct est_no *prox;
    struct est_no *ant;
} est_no;

//Manipulação da lista
est_no* alocaNo(int, int, float);
void filaDinD_insereFinal(est_no **, int, int, float);
void filaDinD_mostraX(est_no *, int);

//Manipulação dos arquivos.csv
void posicionaPonteiro_proxNewLine(FILE*);

#endif