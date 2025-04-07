#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
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
    if(title == " "){
        printf("linha-> %s\n", title);
    }
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
    printf("\n");
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
/*
void extraiYear(char linhaCSV[], int *year){
    char yearStr[10];
    int tamLinha = strlen(linhaCSV);
    int pos;
    int flag;

    //Iterar da direita pra esquerda procurando um ','
    for (pos = (tamLinha - 1); pos >= 0; pos --) {
        if (linhaCSV[pos] == ','){
            if(linhaCSV[pos - 1] == ')'){
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
            //Tem aspas a esquerda da virgula
            else if(linhaCSV[pos - 1] == '"' && linhaCSV[pos - 2] == ')'){ 
                if (linhaCSV[pos - 7] == '(' && linhaCSV[pos - 6] >= 48 && linhaCSV[pos - 6] <= 57) {
                    printf("Letra: %c%c%c%c\n", linhaCSV[pos - 7], linhaCSV[pos - 6], linhaCSV[pos - 5], linhaCSV[pos - 4]);
                    break;
                }
                else{
                    printf("Letra: %c\n", linhaCSV[pos - 7]);
                    *year = 9999;
                    return;
                }
            }
            //Tem aspas e espaco a esquerda da virgula
            else if(linhaCSV[pos - 1] == '"' && linhaCSV[pos - 2] == ' ' && linhaCSV[pos - 3] == ')'){ 
                if (linhaCSV[pos - 8] == '(' && linhaCSV[pos - 7] >= 48 && linhaCSV[pos - 7] <= 57) {
                    break;
                }
                else{
                    *year = 9999;
                    return;
                }
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
*/

void extraiYear(char linhaCSV[], int *year){
    //Fazer uma copia de linhaCSV
    char linhaCSVcopy[strlen(linhaCSV)];
    strcpy(linhaCSVcopy,linhaCSV);
    //Excluir todo mundo da vigula ate o final (DA COPIA)
    char *prtV = strrchr(linhaCSVcopy, ',');
    prtV[0] = '\0';
    //Extrair ano
    //strrchr procura a ultima ocorrence do char passado e retorna um ponteiro na posicao
    char *prtP = strrchr(linhaCSVcopy, '(');
    //prtP[0] aponta pra '('
    //isdigit retorna 1 se o o char passado for um algarismo
    if (prtP && isdigit(prtP[1]) && isdigit(prtP[2]) && isdigit(prtP[3]) && isdigit(prtP[4]) && prtP[5] == ')') {
        char yearTemp[4] = {prtP[1], prtP[2], prtP[3], prtP[4]} ;
        *year = atoi(yearTemp);
    } else {
        *year = -1;
    }
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

void extraiName(char linhaCSV[], char name[]) {
    char *prtUltimoParenteses = strrchr(linhaCSV, '(');
    if (prtUltimoParenteses == NULL) {
        //printf("linha-> %s\n", linhaCSV);
        //Se nao tem '(' e pq nao tem ano, se nao tem ano nao e pra adicionar
        name[0] = '\0';
        return;
    }
    //"cortando o pedaco fora apos a virgula antes dos generos"
    prtUltimoParenteses[0] = '\0';
    
    char *prtPrimeiraVirgula = strchr(linhaCSV, ',');
   
    //movendo ponteiro ate o primeiro char nao especial
    while (!isalnum((unsigned char)prtPrimeiraVirgula[0])) {
        if (prtPrimeiraVirgula[0] == '\0') break;  
        //movendo prt 1 endereco a frente
        prtPrimeiraVirgula++;
    }

    //se a linha tem algum char nao especial
    if (prtPrimeiraVirgula[0] != '\0') {
        strcpy(name, prtPrimeiraVirgula);  
    } 
    //se a linha inteira nao tiver nenhum char nao especial
    else {
        //printf("linha-> %s\n", linhaCSV);
        name[0] = '\0';
    }
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
    //Preparacao para cronometrar o tempo
    double tempo_decorrido = 0.0;
    clock_t inicio, fim;

    //Ordenacao
    if (opAlg == 'q') {
        if (opInfo == 'y') {
            printf("[QUICK SORT] Iniciando ordenacao por year...\n");
            inicio = clock();
            quick_SortYear(lista, 0, lista->cont - 1);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[QUICK SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else if (opInfo == 'r'){
            printf("[QUICK SORT] Iniciando ordenacao por rating...\n");
            inicio = clock();
            quick_SortRating(lista, 0, lista->cont - 1);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[QUICK SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else if (opInfo == 'n'){
            printf("[QUICK SORT] Iniciando ordenacao por name...\n");
            inicio = clock();
            quick_SortString(lista, 0, lista->cont - 1);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[QUICK SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else{
            printf("[ERRO] Escolha uma parametro de ordenacao valido\n");
            return -2;
        }

        lista_mostraX(lista, 10);
    }
    else if (opAlg == 's'){
        if (opInfo == 'y') {
            printf("[SHELL SORT] Iniciando ordenacao por year...\n");
            inicio = clock();
            shell_SortYear(lista);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[SHELL SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else if (opInfo == 'r'){
            printf("[SHELL SORT] Iniciando ordenacao por rating...\n");
            inicio = clock();
            shell_SortRating(lista);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[SHELL SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else if (opInfo == 'n'){
            printf("[SHELL SORT] Iniciando ordenacao por name...\n");
            inicio = clock();
            shell_SortString(lista);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[SHELL SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }

        else{
            printf("[ERRO] Escolha uma parametro de ordenacao valido\n");
            return -2;
        }

        lista_mostraX(lista, 10);
    }
    else if (opAlg == 'm'){
        if (opInfo == 'y') {
            printf("[MERGE SORT] Iniciando ordenacao por year...\n");
            inicio = clock();
            merge_SortYear(lista, 0, lista->cont - 1);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[MERGE SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else if (opInfo == 'r'){
            printf("[MERGE SORT] Iniciando ordenacao por rating...\n");
            inicio = clock();
            merge_SortRating(lista, 0, lista->cont - 1);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[MERGE SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else if (opInfo == 'n'){
            printf("[MERGE SORT] Iniciando ordenacao por name...\n");
            inicio = clock();
            merge_SortString(lista, 0, lista->cont - 1);
            fim = clock();
            tempo_decorrido = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
            printf("[MERGE SORT] Pronto! | Tempo: %f (s)\n", tempo_decorrido);
        }
        else{
            printf("[ERRO] Escolha uma parametro de ordenacao valido\n");
            return -2;
        }

        lista_mostraX(lista, 10);
    }
    else{
        printf("[ERRO] Escolha uma metodo de ordenacao valido\n");
        return -1;     
    }
}

//Quick sort (Hoare)
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

//Shell sort
void shell_SortYear(est_lista *lista){
    int salto = lista->cont / 2;
    int flag;
    est_rating temp;
    do{
        flag = 0;
        for (int i = 0; i < ((lista->cont - 1) - salto); i++) {
            if (lista->lista[i].year > lista->lista[i + salto].year) {
                temp = lista->lista[i];
                lista->lista[i] = lista->lista[i + salto];
                lista->lista[i + salto] = temp;
                
                flag = 1;
            }
        }
        if(salto > 1){
            salto = salto / 2;
        }

    }while(flag);
}
void shell_SortRating(est_lista *lista){
    int salto = lista->cont / 2;
    int flag;
    est_rating temp;
    do{
        flag = 0;
        for (int i = 0; i < ((lista->cont - 1) - salto); i++) {
            if (lista->lista[i].averageRating > lista->lista[i + salto].averageRating) {
                temp = lista->lista[i];
                lista->lista[i] = lista->lista[i + salto];
                lista->lista[i + salto] = temp;
                
                flag = 1;
            }
        }
        if(salto > 1){
            salto = salto / 2;
        }

    }while(flag);
}
void shell_SortString(est_lista *lista){
    int salto = lista->cont / 2;
    int flag;
    est_rating temp;
    do{
        flag = 0;
        for (int i = 0; i < ((lista->cont - 1) - salto); i++) {
            if (strcmp(lista->lista[i].title, lista->lista[i + salto].title) > 0) {
                temp = lista->lista[i];
                lista->lista[i] = lista->lista[i + salto];
                lista->lista[i + salto] = temp;
                
                flag = 1;
            }
        }
        if(salto > 1){
            salto = salto / 2;
        }

    }while(flag);
}

//Merge sort
void merge_SortYear(est_lista *lista, int e, int d){
    if (d > e){
        int meio = e + (d - e) / 2;
        merge_SortYear(lista, e, meio);
        merge_SortYear(lista, meio + 1, d);
        mergeYear(lista, e, meio, d);
    }
}
void mergeYear(est_lista *lista, int e, int meio, int d){
    int i = 0, j = 0, k = e;

    //Calcular tamanho vetores auxialiress
    int n1 = meio - e + 1;
    int n2 = d - meio;
    //Vetores aux alocados pra nao causar seg. fault. por falta de memoria na stack
    est_rating *L = malloc(n1 * sizeof(est_rating));
    est_rating *R = malloc(n2 * sizeof(est_rating));
    
    //Preencher vetores auxiliares
    for (int i = 0; i < n1; i++){
        L[i] = lista->lista[e + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = lista->lista[meio + 1 + j];
    }
    
    //Mesclar L[] e R[]
    while(i < n1 && j < n2){
        if (L[i].year < R[j].year) {
            lista->lista[k] = L[i];
            i ++;
        }
        else{
            lista->lista[k] = R[j];
            j++;
        }
        k++;
    }
    
    //Copiar elementos restantess em L se existir
    while(i < n1){
        lista->lista[k] = L[i];
        i++;
        k++;
    }
    //Copiar os elementos restantes em R se existir
    while(j < n2){
        lista->lista[k] = R[j];
        j++;
        k++;
    }
    
    //Liberar L e R
    free(L);
    free(R);
}

void merge_SortRating(est_lista *lista, int e, int d){
    if (d > e){
        int meio = e + (d - e) / 2;
        merge_SortRating(lista, e, meio);
        merge_SortRating(lista, meio + 1, d);
        mergeRating(lista, e, meio, d);
    }
}
void mergeRating(est_lista *lista, int e, int meio, int d){
    int i = 0, j = 0, k = e;

    //Calcular tamanho vetores auxialiress
    int n1 = meio - e + 1;
    int n2 = d - meio;
    //Vetores aux alocados pra nao causar seg. fault. por falta de memoria na stack
    est_rating *L = malloc(n1 * sizeof(est_rating));
    est_rating *R = malloc(n2 * sizeof(est_rating));
    
    //Preencher vetores auxiliares
    for (int i = 0; i < n1; i++){
        L[i] = lista->lista[e + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = lista->lista[meio + 1 + j];
    }
    
    //Mesclar L[] e R[]
    while(i < n1 && j < n2){
        if (L[i].averageRating < R[j].averageRating) {
            lista->lista[k] = L[i];
            i ++;
        }
        else{
            lista->lista[k] = R[j];
            j++;
        }
        k++;
    }
    
    //Copiar elementos restantess em L se existir
    while(i < n1){
        lista->lista[k] = L[i];
        i++;
        k++;
    }
    //Copiar os elementos restantes em R se existir
    while(j < n2){
        lista->lista[k] = R[j];
        j++;
        k++;
    }
    
    //Liberar L e R
    free(L);
    free(R);
}

void merge_SortString(est_lista *lista, int e, int d){
    if (d > e){
        int meio = e + (d - e) / 2;
        merge_SortString(lista, e, meio);
        merge_SortString(lista, meio + 1, d);
        mergeString(lista, e, meio, d);
    }
}
void mergeString(est_lista *lista, int e, int meio, int d){
    int i = 0, j = 0, k = e;

    //Calcular tamanho vetores auxialiress
    int n1 = meio - e + 1;
    int n2 = d - meio;
    //Vetores aux alocados pra nao causar seg. fault. por falta de memoria na stack
    est_rating *L = malloc(n1 * sizeof(est_rating));
    est_rating *R = malloc(n2 * sizeof(est_rating));
    
    //Preencher vetores auxiliares
    for (int i = 0; i < n1; i++){
        L[i] = lista->lista[e + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = lista->lista[meio + 1 + j];
    }
    
    //Mesclar L[] e R[]
    while(i < n1 && j < n2){
        if (strcmp(L[i].title, R[j].title) < 0) {
            lista->lista[k] = L[i];
            i ++;
        }
        else{
            lista->lista[k] = R[j];
            j++;
        }
        k++;
    }
    
    //Copiar elementos restantess em L se existir
    while(i < n1){
        lista->lista[k] = L[i];
        i++;
        k++;
    }
    //Copiar os elementos restantes em R se existir
    while(j < n2){
        lista->lista[k] = R[j];
        j++;
        k++;
    }
    
    //Liberar L e R
    free(L);
    free(R);
}