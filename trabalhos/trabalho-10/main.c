#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "funcoes-lista.h"



int main(){
    //==Inicializar listas com vetor dinamico
    est_lista listaAvaliacoes;
    listaAvaliacoes.lista = (est_rating*)malloc(MAX_ELEM_RATINGS_CSV * sizeof(est_rating)); 
    listaAvaliacoes.cont = 0;
    est_listaMovies listaFilmes;
    listaFilmes.lista = (est_movies*)malloc(MAX_ELEM_MOVIES_CSV * sizeof(est_movies));
    listaFilmes.cont = 0;

    //===Extrair dados
    FILE *moviesCSV = fopen("./base-de-dados/ml-32m/movies.csv", "r");
    FILE *ratingsCSV = fopen("./base-de-dados/ml-32m/ratings.csv", "r");

    //-Extraindo de ratings.csv
    int cont = 0, contLeituras = 0;
    int userId;
    int movieId;
    float rating;

    posicionaPonteiro_proxNewLine(ratingsCSV);
    while(fscanf(ratingsCSV, "%d,%d,%f", &userId, &movieId, &rating) == 3 && cont > 0){
        posicionaPonteiro_proxNewLine(ratingsCSV);
        lista_insereFinal(&listaAvaliacoes, userId, movieId, rating);

        cont --;
        contLeituras ++;
        printf("Leitura %d realizada, faltando %d leituras\n", contLeituras, (MAX_ELEM_RATINGS_CSV - contLeituras));
        printf("\033[1A");
    }   
    //printf("\n");

    //-Extraindo de movies.csv
    int year, tokenI/*, movieId*/;
    char title[MAX_CHAR_TITULO];
    char genres[MAX_CHAR_GENERO];
    int tam = 10 + MAX_CHAR_TITULO + MAX_CHAR_GENERO;
    char linhaCSV[tam];
    char* linhaCSVtoken[3];
    char* tituloEAno[2];


    cont = 15;
    contLeituras = 0;
    posicionaPonteiro_proxNewLine(moviesCSV);
    //fscanf(moviesCSV, "%d,%[^(](%d),%[^\n]", &movieId, title, &year, genres) == 4 /*&& cont > 0*/
    while(fgets(linhaCSV, tam, moviesCSV) != NULL /*&& cont > 0*/){
        //Removendo o newline
        linhaCSV[strcspn(linhaCSV, "\n")] = '\0';
        
        //Extraindo movieId
        extraiMovieID(linhaCSV, &movieId);
        //printf("Id: %d\n", movieId);

        //Extraindo year
        extraiYear(linhaCSV, &year);
        //printf("Year: %d\n", year);

        //Entraindo genres
        extraiGenres(linhaCSV, genres);
        //printf("Genres: %s\n", genres);

        //Extraindo nome
        extraiName(linhaCSV, title);
        //printf("Title: %s\n", title);

        //cont --;
        listaMovies_insereFinal(&listaFilmes, movieId, title, genres, year);
        printf("MovieId:%d-Title:%s-Year:%d-Genres:%s\n", movieId, title, year, genres);
        /*
        contLeituras ++;
        printf("Leitura %d realizada, faltando %d leituras\n", contLeituras, (MAX_ELEM_MOVIES_CSV - contLeituras));
        printf("\033[1A");
        */
    }   
    //printf("\n");

    //listaMovies_mostraX(&listaFilmes, 200);

    fclose(moviesCSV);
    fclose(ratingsCSV);

    return 0;
}