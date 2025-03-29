#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "funcoes-lista.h"

//==Manipulação da lista
void lista_insereFinal(est_lista *lista, int userId, int movieId, float rating){
    if(lista->cont == MAX_ELEM_RATINGS_CSV) return;
    //Cadastrar dados basicos
    (lista->lista[lista->cont]).userId = userId;
    (lista->lista[lista->cont]).movieId = movieId;
    (lista->lista[lista->cont]).rating = rating;

    //Cadastrar dados extras (que dependem dos basicos)


    //Incrementar
    lista->cont ++;
}

void lista_mostraX(est_lista *lista, int quant){
    if (lista->cont == 0) return;

    printf("Mostrando %d primeiros elementos da lista de avaliacoes:\n", quant);
    for(int i = 0; i < quant; i++){
        if (i >= lista->cont) break;
        printf("%d -> UserId: %d | MovieId: %d | Rating: %f\n", i + 1,(lista->lista[i]).userId, (lista->lista[i]).movieId, (lista->lista[i]).rating);
    }
}

void listaMovies_insereFinal(est_listaMovies* lista, int movieId, char title[], char genres[], int year){
    if(lista->cont == MAX_ELEM_MOVIES_CSV) return;
    //Cadastrar dados extras
    strcpy((lista->lista[lista->cont]).title, title);
    strcpy((lista->lista[lista->cont]).genres, genres);
    (lista->lista[lista->cont]).year = year;
    (lista->lista[lista->cont]).movieId = movieId;

    //Incrementar
    lista->cont ++;
}

void listaMovies_mostraX(est_listaMovies *lista, int quant){
    if (lista->cont == 0) return;

    printf("Mostrando %d primeiros elementos da lista de filmes:\n", quant);
    for(int i = 0; i < quant; i++){
        if (i >= lista->cont) break;
        printf("%d -> MovieId: %d | Title: %s | Year: %d | Genres: %s\n", 
               i + 1,(lista->lista[i]).movieId, (lista->lista[i]).title, (lista->lista[i]).year, (lista->lista[i]).genres);
    }
}

//Manipulação dos arquivos
void posicionaPonteiro_proxNewLine(FILE* arquivo){
    while(1){
        if(fgetc(arquivo) == '\n'){
            break;
        }
    }
}

//Manipulacao das strings
void extraiMovieID(char linhaCSV[], int *movieId){
    char movieIDstr[10];
    int cont = 0;

    //Movendo da esquerda pra direita ate uma virgula
    while(linhaCSV[cont] != ','){
        movieIDstr[cont] = linhaCSV[cont]; 
        cont ++;
    }
    movieIDstr[cont + 1] = '\0';

    *movieId = atoi(movieIDstr);
}

void extraiYear(char linhaCSV[], int *year){
    char yearStr[10];
    int tamLinha = strlen(linhaCSV);
    int pos;

    //Posicionar pos em cima do primeiro ( da esquerda pra direita
    for (pos = (tamLinha - 1); pos >= 0; pos --) {
        if (linhaCSV[pos] == '(') break; 
    }

    //Extrair ano depois converter pra inteiro
    int cont = 0;
    //Mover pos para cima do char a frente
    pos ++;
    //Copiar char apenas se for um char entre 0 e 9 e antes de )
    while(linhaCSV[pos] != ')' && linhaCSV[pos] >= 48 && linhaCSV[pos] <= 57){
        yearStr[cont] = linhaCSV[pos];
        cont ++;
        pos ++;
    }
    yearStr[cont] = '\0';
    //printf("String: %s\n", yearStr);

    *year = atoi(yearStr);
}

void extraiGenres(char linhaCSV[], char genres[]){
    int tamLinha = strlen(linhaCSV);
    int pos;

    //Posicionar pos em cima do primeiro , da esquerda pra direita
    for (pos = (tamLinha - 1); pos >= 0; pos --) {
        if (linhaCSV[pos] == ',') break; 
    }

    //Extrair generos
    int cont = 0;
    //Mover pos para cima do char a frente
    pos ++;
    //Copiar char apenas se for um char entre 0 e 9 e antes de )
    while(linhaCSV[pos] != '\0'){
        genres[cont] = linhaCSV[pos];
        cont ++;
        pos ++;
    }
    genres[cont] = '\0';
}

void extraiName(char linhaCSV[], char name[]){
    int cont = 0, pos = 0;

    //Movendo da esquerda pra direita ate uma virgula
    while(linhaCSV[cont] != ','){
        cont ++;
    }
    
    //Mover cont pra prox char
    cont ++;
    
    //Copiar char apenas se for um char antes de (
    while(linhaCSV[cont] != '('){
        name[pos] = linhaCSV[cont];
        cont ++;
        pos ++;
    }
    //Finalizar string removendo espaco
    name[pos - 1] = '\0';
    //printf("String: %s\n", yearStr);

    name[cont + 1] = '\0';
}