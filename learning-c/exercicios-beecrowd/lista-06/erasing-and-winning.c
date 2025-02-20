#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct tipo_lista{
    int *vetorInts;
    int contador;
    int tamMax;
} tipo_lista;

int* identificaMenorNumero(tipo_lista*, int*, int*);
int quantasAparicoesDeNum(tipo_lista*, int);

tipo_lista* identificaMelhorRemocao(tipo_lista, int, int, int*);
int lista_removerPorPosicao(tipo_lista*, int);


int converteLista_Numero(tipo_lista);
tipo_lista* conveteNumero_Lista(int);

int lista_insere(tipo_lista*, int);
int lista_mostra(tipo_lista*);
tipo_lista* lista_copia(tipo_lista);
int lista_remove(tipo_lista*);


int main(){
    int D, A;

    while(1){
        //Receber D quantidade de algarismos, A quantidade de algarismos a serem apagados
        scanf("%d %d", &D, &A);
        if (D == 0 && A == 0) break;

        //Receber numero em formado de string
        char Nstring[D + 1];
        scanf("%s", Nstring);

        //===Inserir algarismos de Nstring na fila de ints
        //Criar fila
        tipo_lista* prtListaMelhorNum;
        tipo_lista listaMaiorNum;
        listaMaiorNum.contador = 0;
        listaMaiorNum.vetorInts = (int*)malloc(D * sizeof(int));
        listaMaiorNum.tamMax = D;
        prtListaMelhorNum = &listaMaiorNum;
        //Separar algarismos, inserir na fila
        int quantAlgarismos = 0;
        while(Nstring[quantAlgarismos] != '\0'){
            lista_insere(&listaMaiorNum, Nstring[quantAlgarismos] - '0');
            quantAlgarismos ++;
        }
        quantAlgarismos --;

        //===Loop principal
        int maiorNum, menorNum, repetsMenorNum, *posicoesMenorNum;
        for (int i = 0; i < A; i++){
            //Identificar menor algariso em listaMaiorNum e quantas vezes ele aparece
            repetsMenorNum = 0;
            posicoesMenorNum = identificaMenorNumero(prtListaMelhorNum, &repetsMenorNum, &menorNum);
            prtListaMelhorNum = identificaMelhorRemocao((*prtListaMelhorNum), menorNum, repetsMenorNum, posicoesMenorNum);
            
            printf("Posicoes do menor numero: [");
            for (int i = 0; i < repetsMenorNum; i++) {
                printf(" %d ", posicoesMenorNum[i]);
            }
            printf("]\n");

            printf("Melhor possibilidade: ");
            lista_mostra(prtListaMelhorNum);
            printf("\n");
            
        }

        //==Mostrar melhor menor numero final
        lista_mostra(prtListaMelhorNum);
        
        
    }
    return 0;
}

int lista_insere(tipo_lista* lista, int novoInt){
    if (lista->contador == lista->tamMax) {
        return -1;
    }

    lista->vetorInts[lista->contador] = novoInt;
    lista->contador ++;
}

int lista_mostra(tipo_lista *lista){
    if (lista->contador == 0) {
        printf("[WARNING] Tentando mostrar lista vazia\n");
        return -1;
    }

    for (int i = 0; i < lista->contador; i++) {
        printf("[%d]",lista->vetorInts[i]);
    }
    printf("\n");
}

tipo_lista* lista_copia(tipo_lista listaOriginal){
    //Alocar memoria para a copia
    tipo_lista *listaCopia = (tipo_lista*)malloc(sizeof(tipo_lista));
    listaCopia->contador = 0;
    listaCopia->tamMax = listaOriginal.tamMax;
    listaCopia->vetorInts = (int*)malloc(listaOriginal.tamMax * sizeof(int));

    //Copiar dados de uma lista pra outra
    for (int i = 0; i < listaOriginal.tamMax; i++) {
        lista_insere(listaCopia, lista_remove(&listaOriginal));
    }

    return listaCopia;
}

int lista_remove(tipo_lista *lista){
    if (lista->contador == 0) {
        printf("[ERRO] Tentando remover de lista vazia\n");
        return -1;
    }

    //Tirar primeiro elemento
    int dadoRm = lista->vetorInts[0];
    lista->contador --;

    //Organizar resto
    for (int i = 0; i < lista->contador; i++) {
        lista->vetorInts[i] = lista->vetorInts[i + 1];
    }

    return dadoRm;
}

int lista_removerPorPosicao(tipo_lista* lista, int posicao){
    if (lista->contador == 0) {
        printf("[ERRO] Tentando remover de lista vazia\n");
        return -1;
    }

    //Remover elemento da posicao desejada
    int dadoRm = lista->vetorInts[posicao];
    lista->contador --;

    //Reorganizar lista
    for (int i = posicao; i < lista->contador; i++) {
        lista->vetorInts[i] = lista->vetorInts[i + 1];
    }
 
    return dadoRm;
}

int* identificaMenorNumero(tipo_lista* lista, int *repetsMenorNum, int *menorNum){
    if (lista->contador == 0) {
        printf("[WARNING] Tentando identificar menor algarismo em lista vazia");
    }else{
        (*repetsMenorNum) = 0;
        //Identificar menor valor
        //printf("1\n");
        int menor = lista->vetorInts[0];
        for (int i = 0; i < lista->contador; i++) {
            if (menor > lista->vetorInts[i]) {
                menor = lista->vetorInts[i];
            }
        }
        //printf("2\n");
        (*menorNum) = menor;
        printf("Menor valor: %d\n", menor);

        //Contar quantas vezes ele aparece
        for (int i = 0; i < lista->contador; i++) {
            if (menor == lista->vetorInts[i]) {
                (*repetsMenorNum) ++;
            }
        }
        printf("Menor valor apareceu: %d vezes\n", (*repetsMenorNum));

        //Identificar posicoes de aparicao
        printf("Menor valor apareceu nas posicoes: ");
        int *posicoesMenorNum = malloc((*repetsMenorNum) * sizeof(int));
        int cont = 0;
        for (int i = 0; i < lista->contador; i++) {
            if (menor == lista->vetorInts[i]) {
                posicoesMenorNum[cont] = i;
                printf("%d", posicoesMenorNum[cont]);
                cont++;
                
            }
        }
        printf("\n");
        return posicoesMenorNum;
    }
    
}

int converteLista_Numero(tipo_lista lista){
    int numero, potencia, tamMax;
    numero = 0;
    tamMax = lista.tamMax - 1;

    for (int i = 0; i < tamMax; i++) {
        potencia = tamMax - i;
        numero += lista.vetorInts[i] * pow(10, potencia);
    }
    
    return numero;
}

tipo_lista* identificaMelhorRemocao(tipo_lista listaInvestigada, int menorNum, int repetsMenorNum, int *posicoesMenorNum){
    //==Gerar possibilidades de numero
    int *possibilidadesNumeros = (int*)malloc(repetsMenorNum * sizeof(int));
    for (int j = 0; j < repetsMenorNum; j++) {
        //Criar copia de listInvestigada
        tipo_lista *copiaListInvestigada = lista_copia(listaInvestigada);

        //Remover algarismo da posicao livre atual
        lista_removerPorPosicao(copiaListInvestigada, posicoesMenorNum[j]);
        
        //Converter possibilidade gerada de lista -> inteiro, guardar em  possibilidadesNumer0
        possibilidadesNumeros[j] = converteLista_Numero((*copiaListInvestigada));
        
        //Liberar copiaListInvestigada
        free(copiaListInvestigada);
    }
    
    //==Identificar qual a melhor possibilidade
    int maiorNumero = possibilidadesNumeros[0];
    //Iterar por possibilidadesNumeros, identificar maior numero
    printf("Numeros potenciais: ");
    for (int i = 0; i < repetsMenorNum; i++) {
        if (maiorNumero < possibilidadesNumeros[i] ) {
            maiorNumero = possibilidadesNumeros[i];
        }
        printf("%d", possibilidadesNumeros[i]);
    }
    printf("\n");

    //Converter maiorNumero de numero para lista de chars e entao para uma lista de algarismos listaMelhorPossibilidade
    tipo_lista lstMelhorPoss;
    tipo_lista *listaMelhorPossibilidade = &lstMelhorPoss;
    listaMelhorPossibilidade->contador = 0;
    listaMelhorPossibilidade->tamMax = listaInvestigada.tamMax;
    listaMelhorPossibilidade->vetorInts = (int*)malloc(listaInvestigada.contador);


    char listaMelhorPossibilidadeStr[listaInvestigada.contador];
    sprintf(listaMelhorPossibilidadeStr, "%d", maiorNumero);

    //Separar algarismos, inserir na fila
    int quantAlgarismos = 0;
    while(listaMelhorPossibilidadeStr[quantAlgarismos] != '\0'){
        lista_insere(listaMelhorPossibilidade, listaMelhorPossibilidadeStr[quantAlgarismos] - '0');
        quantAlgarismos ++;
    }
    quantAlgarismos --;

    //Liberar memoria
    free(possibilidadesNumeros);

    //==Retornar melhor possibilidade
    return listaMelhorPossibilidade;
}
//Essa funcao retorna o endereco de uma lista alocada no heap
//com a melhor menor possibilidade, dados o menor algarismo do
//numero e quantas vezes ele aparece.
//(quantas vezes ele aparece == quantidade de possibilidades de melhores menores numeros)
