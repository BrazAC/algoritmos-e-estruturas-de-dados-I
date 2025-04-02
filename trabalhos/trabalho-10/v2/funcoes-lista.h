#ifndef __FUNCOES_LISTA_H__
#define __FUNCOES_LISTA_H__

#define MAX_CHAR_TITULO 100
#define MAX_CHAR_GENERO 200
#define MAX_ELEM_RATINGS_CSV 32000204
#define MAX_ELEM_MOVIES_CSV 87585

//Struct para armazenar a média de rating de um filme
typedef struct est_rating{
    int movieId;
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
void lista_editaAvrgRating(est_lista *lista, int movieId, float averageRating);
void lista_mostraX(est_lista*, int);

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