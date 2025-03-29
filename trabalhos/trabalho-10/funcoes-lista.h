#ifndef __FUNCOES_LISTA_H__
#define __FUNCOES_LISTA_H__

#define MAX_CHAR_TITULO 100
#define MAX_CHAR_GENERO 200
#define MAX_ELEM_RATINGS_CSV 32000204
#define MAX_ELEM_MOVIES_CSV 87585

typedef struct est_rating{
    int userId;
    int movieId;
    float rating;

    char title[MAX_CHAR_TITULO];
    int year;
    char genres[MAX_CHAR_GENERO];
} est_rating;

typedef struct est_lista{
    est_rating *lista;
    int cont;
} est_lista;

typedef struct est_movies{
    int movieId;
    char title[MAX_CHAR_TITULO];
    int year;
    char genres[MAX_CHAR_GENERO];
} est_movies;

typedef struct est_listaMovies{
    est_movies *lista;
    int cont;
} est_listaMovies;

//Manipulação da lista
void lista_insereFinal(est_lista*, int, int, float);
void lista_mostraX(est_lista*, int);

void listaMovies_insereFinal(est_listaMovies*, int, char[], char[], int);
void listaMovies_mostraX(est_listaMovies*, int);

//Manipulação dos arquivos.csv
void posicionaPonteiro_proxNewLine(FILE*);

//Manipulacao de strings
void extraiMovieID(char[], int*);
void extraiYear(char[], int*);
void extraiGenres(char[], char[]);
void extraiName(char[], char[]);

#endif