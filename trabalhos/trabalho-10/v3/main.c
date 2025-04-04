#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "funcoes-lista.h"

int main(){
    //===Inicializar listas com vetor estatico
    est_lista listaAvaliacoes;
    listaAvaliacoes.lista = (est_rating*)malloc(MAX_ELEM_MOVIES_CSV * sizeof(est_rating)); 
    listaAvaliacoes.cont = 0;

    //===Extrair dados
    FILE *moviesCSV = fopen("./base-de-dados/ml-32m/movies.csv", "r");

    //---Extraindo de movies.csv
    int year, contLeiturasFeedback = 0, movieId;
    char title[MAX_CHAR_TITULO];
    char genres[MAX_CHAR_GENERO];
    int tam = 10 + MAX_CHAR_TITULO + MAX_CHAR_GENERO;
    char linhaCSV[tam];

    printf("[AVISO] Iniciando extracao de Movies\n");
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
        contLeiturasFeedback ++;
        printf("MOVIES.CSV -> Leitura %d realizada, faltando %d leituras\n", contLeiturasFeedback, (MAX_ELEM_MOVIES_CSV - contLeiturasFeedback));
        printf("\033[1A");
        
    }   
    printf("\n");
    fclose(moviesCSV);
    
    //---Extraindo de ratings.csv 
    FILE *ratingsCSV = fopen("./base-de-dados/ml-32m/ratings.csv", "r");
    int cont;
    int contExtracoes = 100;
    float tempRating = 0;
    tam = 10 + 10 + 10 + 20;
    char linhaRatingCSV[tam];
    clock_t inicio, fim;
    double tempo_decorrido2;
    contLeiturasFeedback = 0;

    //printf("\n");
    printf("\n[AVISO] Iniciando extracao de ratings\n");
    inicio = clock();
    posicionaPonteiro_proxNewLine(ratingsCSV);
    while(fgets(linhaRatingCSV, tam, ratingsCSV) != NULL && contExtracoes > 0){
        contExtracoes --;
        //---Calcular media de avaliacoes pra o filme atual
        //Removendo o newline
        linhaRatingCSV[strcspn(linhaRatingCSV, "\n")] = '\0';
        //printf("Linha extraida: %s\n",linhaRatingCSV);
        
        //Da linha, extrair movieId
        extraiMovieID_2(linhaRatingCSV, &movieId);
        //printf("MovieId extraido: %d\n", movieId);

        //Da linha, extrair rating
        extraiRating(linhaRatingCSV, &tempRating);
        //printf("Rating extraido: %f\n", tempRating);

        //Inserir dados no struct corespondente
        cont = 0;
        while(1){
            if(listaAvaliacoes.lista[cont].movieId == movieId){
                listaAvaliacoes.lista[cont].averageRating += tempRating;
                listaAvaliacoes.lista[cont].contMovieId ++;
                /*
                //Feedback
                printf("Encontrado MovieId: %d Na lista: %d Com rating atual: %f Com rating somado: %f E aparicoes: %d \n",
                    movieId,
                    listaAvaliacoes.lista[cont].movieId,
                    tempRating,
                    listaAvaliacoes.lista[cont].averageRating, 
                    listaAvaliacoes.lista[cont].contMovieId);
                */
                break;
            }
            if(cont >= MAX_ELEM_MOVIES_CSV){
                printf("[ERRO] NÃO ENCONTROU O MOVIEID\n"); 
                break;
            }
            cont++;
        }
        //Feedback de extracao
        contLeiturasFeedback ++;
        printf("RATINGS.CSV -> Leitura %d realizada, faltando %d leituras\n", contLeiturasFeedback, (MAX_ELEM_RATINGS_CSV - contLeiturasFeedback));
        printf("\033[1A");
    }
    fim = clock();
    tempo_decorrido2 = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nO tempo decorrido para extracao de ratings foi: %f segundos\n\n", tempo_decorrido2);  

    
    //Calcular a media rating para cada struct
    double tempo_decorrido3;
    inicio = clock();
    contLeiturasFeedback = 0;
    printf("[AVISO] Iniciando calculo de médias\n");
    for (int i = 0; i < MAX_ELEM_MOVIES_CSV; i++) {
        lista_atualizaAvrgRating(&listaAvaliacoes, listaAvaliacoes.lista[i].movieId); 

        //Feedback de extracao
        contLeiturasFeedback ++;
        printf("Media %d calculada, faltando %d medias\n", contLeiturasFeedback, (MAX_ELEM_MOVIES_CSV - contLeiturasFeedback));
        printf("\033[1A");
    }
    fim = clock();
    tempo_decorrido3 = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nO tempo decorrido de para o calculo de medias foi: %f segundos\n\n", tempo_decorrido3); 
   
    fclose(ratingsCSV);

    //Mostrando primeiros x's elementos da lista de ratings
    lista_mostraX(&listaAvaliacoes, 10);

    ordenaCustom(&listaAvaliacoes, 'q', 'n');

    ordenaCustom(&listaAvaliacoes, 'q', 'r');

    ordenaCustom(&listaAvaliacoes, 'm', 'n');

    //===Interface do usuario
    

    return 0;
}