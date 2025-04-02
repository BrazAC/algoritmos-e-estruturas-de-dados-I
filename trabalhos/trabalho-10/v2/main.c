#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "funcoes-lista.h"

int main(){
    //==Inicializar listas com vetor dinamico
    est_lista listaAvaliacoes;
    listaAvaliacoes.lista = (est_rating*)malloc(MAX_ELEM_MOVIES_CSV * sizeof(est_rating)); 
    listaAvaliacoes.cont = 0;

    //===Extrair dados
    FILE *moviesCSV = fopen("./base-de-dados/ml-32m/movies.csv", "r");

    //-Extraindo de movies.csv
    int year, contLeituras, movieId;
    char title[MAX_CHAR_TITULO];
    char genres[MAX_CHAR_GENERO];
    int tam = 10 + MAX_CHAR_TITULO + MAX_CHAR_GENERO;
    char linhaCSV[tam];

    contLeituras = 0;
    posicionaPonteiro_proxNewLine(moviesCSV);
    while(fgets(linhaCSV, tam, moviesCSV) != NULL){
        //Removendo o newline
        linhaCSV[strcspn(linhaCSV, "\n")] = '\0';
        
        //Extraindo movieId
        extraiMovieID(linhaCSV, &movieId);

        //Extraindo year
        extraiYear(linhaCSV, &year);

        //Entraindo genres
        extraiGenres(linhaCSV, genres);

        //Extraindo nome
        extraiName(linhaCSV, title);

        lista_insereFinal(&listaAvaliacoes, movieId, year, genres, title);
        //printf("MovieId: %d Title: %s Year: %d Genres: %s\n", movieId, title, year, genres);
        
        //Feedback de extracao
        contLeituras ++;
        printf("Leitura %d realizada, faltando %d leituras\n", contLeituras, (MAX_ELEM_MOVIES_CSV - contLeituras));
        printf("\033[1A");
        
    }   
    printf("\n");
    fclose(moviesCSV);

    //Mostrando primeiros x's elementos da lista de ratings
    lista_mostraX(&listaAvaliacoes, 10);
    
    //-Extraindo de ratings.csv 
    FILE *ratingsCSV = fopen("./base-de-dados/ml-32m/ratings.csv", "r");
    int cont = 5, aparicoesMovieID = 0;
    contLeituras = 0;
    float averageRating = 0, tempRating;
    tam = 10 + 10 + 10 + 20;
    char linhaRatingCSV[tam];
    clock_t inicio, fim;
    double tempo_decorrido2;
    int quantDeFilmes = MAX_ELEM_MOVIES_CSV;

    printf("\n");
    inicio = clock();
    for (int i = 0; i < quantDeFilmes; i++) {
        //---Calcular media de avaliacoes pra o filme atual
        //Iterar por ratings.csv procurando pelo movieId atual
        posicionaPonteiro_proxNewLine(ratingsCSV);
        while(fgets(linhaRatingCSV, tam, ratingsCSV) != NULL /*&& cont > 0*/){
            
            //Removendo o newline
            linhaRatingCSV[strcspn(linhaRatingCSV, "\n")] = '\0';
            //printf("Linha extraida: %s\n",linhaRatingCSV);
            
            //Da linha, extrair movieId
            extraiMovieID_2(linhaRatingCSV, &movieId);
            //printf("MovieId extraido: %d\n", movieId);

            //Da linha, extrair rating
            extraiRating(linhaRatingCSV, &tempRating);
            //printf("Rating extraido: %f\n\n", tempRating);
            
            //Se movieId extraido for igual a movieId atual
            if (movieId == listaAvaliacoes.lista[i].movieId) {
                //printf("MovieIdExtraido: %d TargetID: %d\n", movieId, listaAvaliacoes.lista[i].movieId);
                //Somar rating extraido a averageRating
                averageRating += tempRating;
                //Incrementar aparicoesMovieID
                aparicoesMovieID ++;
                //cont --;
            }
        }
        //Mover cursor de volta ao comeco do arquivo
        rewind(ratingsCSV);
            
        //Calcular a media
        //dividir averageRating por aparicoesMovieId
        averageRating = averageRating / aparicoesMovieID;
        
        //Feedback de extracao
        printf("Media calculada, info:\nMovieId: %d AverageRating: %f AparicoesMovieID: %d\n", 
            listaAvaliacoes.lista[i].movieId, 
            averageRating, 
            aparicoesMovieID);    

        //---Inserir media encontrada no struct atual
        lista_editaAvrgRating(&listaAvaliacoes, listaAvaliacoes.lista[i].movieId, averageRating);
        
        //Preparar para o proxima iteracao
        averageRating = 0;
        aparicoesMovieID = 0;
    }
    fim = clock();
    if (cont  > 0) printf("\n");

    tempo_decorrido2 = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Para %d filmes, o tempo decorrido de extracao de ratings foi: %f segundos\n\n", quantDeFilmes, tempo_decorrido2);  

    fclose(ratingsCSV);
    

    //Mostrando primeiros x's elementos da lista de ratings
    lista_mostraX(&listaAvaliacoes, 10);

    return 0;
}