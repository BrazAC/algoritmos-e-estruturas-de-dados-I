#ifndef __FUNCOES_LISTA_H__
#define __FUNCOES_LISTA_H__

#define MAX_CHAR_TITULO 100
#define MAX_CHAR_GENERO 200
#define MAX_ELEM_RATINGS_CSV 32000204
#define MAX_ELEM_MOVIES_CSV 87585

//Struct para armazenar a média de rating de um filme
typedef struct est_rating{
    int movieId;
    int contMovieId;
    float averageRating;

    int year;
    char title[MAX_CHAR_TITULO];
    char genres[MAX_CHAR_GENERO];
} est_rating;

//Lista estática para armazenar structs
typedef struct est_lista{
    est_rating *lista;
    int cont;
} est_lista;

//Manipulação da lista
void lista_insereFinal(est_lista *lista, int movieId, int year, char genres[], char title[]);
void lista_atualizaAvrgRating(est_lista *lista, int movieId);
void lista_mostraX(est_lista*, int);

//Ordenacao
int ordenaCustom(est_lista *lista, char opAlg, char opInfo);
//Quick sort
void quick_SortString(est_lista *lista, int e, int d);
int sortString(est_lista *lista, int e, int d);

void quick_SortYear(est_lista *lista, int e, int d);
int sortYear(est_lista *lista, int e, int d);

void quick_SortRating(est_lista *lista, int e, int d);
int sortRating(est_lista *lista, int e, int d);

//Shell sort
void shell_SortString(est_lista *lista);
void shell_SortYear(est_lista *lista);
void shell_SortRating(est_lista *lista);

//Merge sort
void merge_SortYear(est_lista *lista, int e, int d);
void mergeYear(est_lista *lista, int e, int meio, int d);

void merge_SortString(est_lista *lista, int e, int d);
void mergeString(est_lista *lista, int e, int meio, int d);

void merge_SortRating(est_lista *lista, int e, int d);
void mergeRating(est_lista *lista, int e, int meio, int d);

//Manipulação dos arquivos.csv
void posicionaPonteiro_proxNewLine(FILE*);

//Extracao de strings
void extraiMovieID(char[], int*);
void extraiYear(char[], int*);
void extraiGenres(char[], char[]);
void extraiName(char[], char[]);

void extraiMovieID_2(char[], int*);
void extraiRating(char[], float*);

#endif