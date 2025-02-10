#include "fila_functions.h"
#include <stdlib.h>
#include <stdio.h>

void fila_mostrar(tipo_fila fila) {
    //Se a fila nao estiver vazia
    if (fila.contador > 0) {
        for (int i = 0; i < fila.contador; i++) {
            if (i == 0) {
                printf("%d", fila.filaInts[i]);
            }
            else if(i == fila.contador - 1){
                printf(" %d\n", fila.filaInts[i]);
            }
            else{
                printf(" %d", fila.filaInts[i]);
            }
        }
    }
    //Se estiver
    else {
        printf("Fila vazia\n");
    }
}

void fila_insereInicio(tipo_fila* fila, int novoInt){
    //Se a fila nao estiver cheia
    if (fila->contador < TAMMAX) {
        //Se o inicio estiver ocupado
        if (fila->contador > 0) {
            //Mover valores  
            for (int i = fila->contador; i >= 0; i--) {
                fila->filaInts[i] = fila->filaInts[i - 1]; 
            }
            //Inserir novo valor na posicao 0
            fila->filaInts[0] = novoInt;
        }
        //Se o inicio estiver livre
        else{
            fila->filaInts[0] = novoInt;
        }
        fila->contador ++;
    }
    //Se estiver cheia
    else{
        printf("[ERRO] Nao e possivel inserir no inicio, Fila cheia\n");
    }
}

void fila_insereFinal(tipo_fila* fila, int novoInt){
//Se a fila nao estiver cheia
    if (fila->contador < TAMMAX) {
        fila->filaInts[fila->contador] = novoInt;
        fila->contador ++;
    }
    //Se estiver cheia
    else{
        printf("[ERRO] Nao e possivel inserir no final, Fila cheia\n");
    }
}

void fila_inserePosEspecifico(tipo_fila* fila, int posicao, int novoInt){
    //Se a fila nao estiver cheia
    if (fila->contador < TAMMAX) {
        //Se o inicio estiver ocupado
        //Mover valores  
        for (int i = fila->contador; i >= posicao - 1; i--) {
            fila->filaInts[i] = fila->filaInts[i - 1]; 
        }
        //Inserir novo valor na posicao 0
        fila->filaInts[posicao - 1] = novoInt;
        //Incrementar contador
        fila->contador ++;
    }
    //Se estiver cheia
    else{
        printf("[ERRO] Nao e possivel inserir na posicao %d, Fila cheia\n\n", posicao);
    }
}

int fila_removeInicio(tipo_fila* fila){
    //Se nao estiver vazia
    if (fila->contador > 0) {
        //Atualizar contador
        fila->contador --;
        //Guardar primeiro elemento a ser removido
        int elementoRemovido = fila->filaInts[0];;
        //Organizar fila
        for (int i = 0; i < fila->contador; i++) {
            fila->filaInts[i] = fila->filaInts[i + 1];
        }
        return elementoRemovido;
    }
    else {
        printf("[ERRO] Nao e possivel remover, fila vazia\n");
    }
}

int fila_removeFim(tipo_fila* fila){
    //Se nao estiver vazia
    if (fila->contador > 0) {
        //Atualizar contador
        fila->contador --;
        //Guardar ultimo elemento a ser removido
        int elementoRemovido = fila->filaInts[fila->contador];
        return elementoRemovido;
    }
    else {
        printf("[ERRO] Nao e possivel remover, fila vazia\n");
    }
}

int fila_removePosEspecifica(tipo_fila* fila, int posicao){
    if (fila->contador > 0) {
        //Verificar existe elemento naquela posicao
        int temElemento = posicao - 1 < fila->contador ? 1 : 0;
        if (temElemento) {
            fila->contador --;
            int elementoRemovido = fila->filaInts[posicao - 1];
            for (int i =  posicao - 1; i < fila->contador; i++) {
                fila->filaInts[i] = fila->filaInts[i + 1]; 
            }
            return elementoRemovido;
        }
        else{
            printf("[ERRO] Nao e possivel remover, nao existe elemento na posicao %d\n", posicao);
        }
    }
    else{
        printf("[ERRO] Nao e possivel remover, fila vazia\n");
    }
}

int fila_removeValEspecifico(tipo_fila* fila, int valorEspecifico){
    for (int i = 0; i < fila->contador; i++) {
        if (fila->filaInts[i] == valorEspecifico) {
            return fila_removePosEspecifica(fila , i + 1);
        }
    }
    printf("[ERRO] Valor %d nao esta na fila\n", valorEspecifico);
}

int fila_ordenar(tipo_fila* fila){
    int contador = fila->contador;
    int temp;
    //Bubble sort
    for (int i = 0; i < fila->contador; i++) {
        for (int i = 0; i < contador - 1; i++) {
            if (fila->filaInts[i] > fila->filaInts[i + 1]) {
                temp = fila->filaInts[i];
                fila->filaInts[i] = fila->filaInts[i + 1];
                fila->filaInts[i + 1] = temp;
            }
        }
        contador --;
    }
}

//[a, b, c, d, 0, 0]
//[a, a, b, c, d, 0]