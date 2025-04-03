#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "funcoes-lista.h"

//==Manipulação da lista
void lista_atualizaAvrgRating(est_lista *lista, int movieId){
    //printf("Cont: %d", lista->cont);
    //Encontrar o struct com movieId passado
    for (int i = 0; i < lista->cont; i++) {
        //Se encontrar, cadastra o movieID passado atualizar a media
        if(lista->lista[i].movieId == movieId){
            lista->lista[i].averageRating = lista->lista[i].averageRating / lista->lista[i].contMovieId;
            //printf("MovieID encontrado: %d", lista->lista[i].movieId);
        }
    }
}

void lista_insereFinal(est_lista *lista, int movieId, int year, char genres[], char title[]){
    if(lista->cont == MAX_ELEM_MOVIES_CSV) return;
    //Cadastrar dados
    lista->lista[lista->cont].movieId = movieId;
    lista->lista[lista->cont].year = year;
    strcpy(lista->lista[lista->cont].genres, genres);
    strcpy(lista->lista[lista->cont].title, title);
    lista->lista[lista->cont].contMovieId = 0;
    lista->lista[lista->cont].averageRating = 0.0;
    
    //Incrementar
    lista->cont ++;
}

void lista_mostraX(est_lista *lista, int quant){
    if (lista->cont == 0) return;

    printf("Mostrando %d primeiros elementos da lista:\n", quant);
    for(int i = 0; i < quant; i++){
        if (i >= lista->cont) break;
        printf("%d -> MovieId: %d  Average Rating: %f  Title: %s  Year: %d  Genres: %s\n", 
            i + 1, 
            lista->lista[i].movieId, 
            lista->lista[i].averageRating,
            lista->lista[i].title,
            lista->lista[i].year,
            lista->lista[i].genres);
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
    int flag;

    //Iterar da direita pra esquerda procurando um ','
    for (pos = (tamLinha - 1); pos >= 0; pos --) {
        if (linhaCSV[pos] == ','){ 
            //Quando encontrar, verificar se o char 6 posicoes a esquerda e um '(' 
            //e o char 5 posicoes a esquerda e um algarismo (0->9)
            if (linhaCSV[pos - 6] == '(' && linhaCSV[pos - 5] >= 48 && linhaCSV[pos - 5] <= 57) {
                //printf("Letra: %c\n", linhaCSV[pos - 6]);
                //Se for um algarismo, coletar a data (mudar a flag)
                break;
            }
            else{
                *year = 9999;
                return;
            }
        }
    }

    //Extrair ano depois converter pra inteiro
    int cont = 0;
    //Mover pos para cima do char atras
    pos -= 5;
    //printf("Letra2: %c\n", linhaCSV[pos]);
    //Copiar char apenas se for um char entre 0 e 9 e antes de )
    while(linhaCSV[pos] != ')' && linhaCSV[pos] >= 48 && linhaCSV[pos] <= 57){
        yearStr[cont] = linhaCSV[pos];
        cont ++;
        pos ++;
    }
    yearStr[4] = '\0';
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

void extraiMovieID_2(char linhaCSV[], int *movieId){
    char movieIDstr[10];
    int cont = 0;
    int cont2 = 0;

    //Movendo da esquerda pra direita ate uma virgula
    while(linhaCSV[cont] != ','){
        cont ++;
    }
    //Posicionar contador em do primeiro char apos a virgula
    cont ++;
    //Copiar characteres a frente de cont ate antes da proxima virgula
    do{
        movieIDstr[cont2] = linhaCSV[cont];
        cont2 ++;
        cont ++;
    }while(linhaCSV[cont] != ',');

    movieIDstr[cont2 + 1] = '\0';

    *movieId = atoi(movieIDstr);
}

void extraiRating(char linhaCSV[], float *rating){
    char movieRatingstr[10];
    int cont = 0;
    int cont2 = 0;
    int temp0, temp1, temp3;

    //Movendo da esquerda pra direita ate uma virgula
    while(linhaCSV[cont] != ','){
        cont ++;
    }
    //Posicionar contador em do primeiro char apos a virgula
    cont ++;

    //Movendo da esquerda pra direita ate uma virgula
    while(linhaCSV[cont] != ','){
        cont ++;
    }
    //Posicionar contador em do primeiro char apos a virgula
    cont ++;

    sscanf(linhaCSV, "%d,%d,%f,%d", &temp0, &temp1, rating, &temp3);
        

    /*
    //Copiar characteres a frente de cont ate antes da proxima virgula
    do{
        movieRatingstr[cont2] = linhaCSV[cont];
        cont2 ++;
        cont ++;
    }while(linhaCSV[cont] != ',');

    movieRatingstr[cont2 + 1] = '\0';

    *rating = atoi(movieRatingstr);
    */

    
}

//Ordenacao
int ordenaCustom(est_lista *lista, char opAlg, char opInfo){
    if (opAlg == 'q') {
        if (opInfo == 'y') {
            quick_SortYear(lista, 0, lista->cont - 1);
        }
        else if (opInfo == 'r'){
            quick_SortRating(lista, 0, lista->cont - 1);
        }
        else if (opInfo == 'n'){
            quick_SortString(lista, 0, lista->cont - 1);
        }
        else{
            return -2;
        }
    }
    else{
        return -1;     
    }
}

//Quick sort (bendita implementacao de hoare NAO DO OUTRO CARA LA)
void quick_SortYear(est_lista *lista, int e, int d){
    if (d > e) {
        int j = sortYear(lista, e, d);
        quick_SortYear(lista, e, j);
        quick_SortYear(lista, j+1, d);
    }
}
int sortYear(est_lista *lista, int e, int d){
    est_rating temp;
    int i = e - 1;
    int j = d + 1;
    est_rating pivo = lista->lista[(e + d) / 2];

    while(1){
        do{
            i++;
        }while(lista->lista[i].year < pivo.year);
        do{
            j--;
        }while(lista->lista[j].year > pivo.year);

        if (j <= i) {
            return j;
        }

        temp = lista->lista[i];
        lista->lista[i] = lista->lista[j];
        lista->lista[j] = temp;
    }

}

void quick_SortRating(est_lista *lista, int e, int d){
    if (d > e) {
        int j = sortRating(lista, e, d);
        quick_SortRating(lista, e, j);
        quick_SortRating(lista, j+1, d);
    }
}
int sortRating(est_lista *lista, int e, int d){
    est_rating temp;
    int j = d + 1;
    int i = e - 1;
    est_rating pivo = lista->lista[(e + d) / 2];

    while(1){
        do{
            i++;
        }while(lista->lista[i].averageRating < pivo.averageRating);
        do{
            j--;
        }while(lista->lista[j].averageRating > pivo.averageRating);

        if (j <= i) {
            return j;            
        }

        temp = lista->lista[i];
        lista->lista[i] = lista->lista[j];
        lista->lista[j] = temp;
    }
}

void quick_SortString(est_lista *lista, int e, int d){
    if (d > e) {
        int j = sortString(lista, e, d);
        quick_SortString(lista, e, j);
        quick_SortString(lista, j+1, d);
    }
}
int sortString(est_lista *lista, int e, int d){
    est_rating temp;
    int j = d + 1;
    int i = e - 1;
    est_rating pivo = lista->lista[(e + d) / 2];

    while(1){
        do{
            i++;
        }while(strcmp(lista->lista[i].title, pivo.title) < 0);
        do{
            j--;
        }while(strcmp(lista->lista[j].title, pivo.title) > 0);

        if (j <= i) {
            return j;
        }

        temp = lista->lista[i];
        lista->lista[i] = lista->lista[j];
        lista->lista[j] = temp;
    }
}