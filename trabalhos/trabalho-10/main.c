#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "funcoes-lista.h"



int main(){
    //===Extrair dados
    FILE *moviesCSV = fopen("./base-de-dados/ml-32m/movies.csv", "r");
    FILE *ratingsCSV = fopen("./base-de-dados/ml-32m/ratings.csv", "r");
    est_no *filaDDAvaliacoes = NULL;

    //-Extraindo de ratings.csv
    int cont = 10, contLeituras = 0;
    posicionaPonteiro_proxNewLine(ratingsCSV);
    int userId;
    int movieId;
    float rating;

    while(fscanf(ratingsCSV, "%d,%d,%f", &userId, &movieId, &rating) != -1 /*&& cont > 0*/){
        //posicionaPonteiro_proxNewLine(ratingsCSV);
        filaDinD_insereFinal(&filaDDAvaliacoes, userId, movieId, rating);

        //cont --;
        contLeituras ++;
        printf("Leitura %d realizada, faltando %d leituras\n", contLeituras, (MAX_ELEM_RATINGS_CSV - contLeituras));
    }   

    fclose(moviesCSV);
    
    //-Extraindo de movies.csv
    //title
    //year
    //genre

    filaDinD_mostraX(filaDDAvaliacoes, 10);

    

    return 0;
}