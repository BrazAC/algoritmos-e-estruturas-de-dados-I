#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct tipo_fila {
    int fila[30];
    int contador;
} tipo_fila;

void fila_insere(tipo_fila*, int);
int fila_remove(tipo_fila*);
void fila_mostra(tipo_fila);

int main(){
    //-- Inicializando variaveis
    int inscritosAtuais, inscritosNecessarios;

    tipo_fila fila_diaria_inscritos;
    fila_diaria_inscritos.contador = 0;

    //-- Obtendo dados
    scanf("%d %d", &inscritosAtuais, &inscritosNecessarios);
    //Cadastrando a quantidade de inscritos diarios nos ultimos 30 dias na fila
    int j = 0, inscritosNoDia;
    while (j < 30){
        j ++;
        scanf("%d", &inscritosNoDia);
        fila_insere(&fila_diaria_inscritos, inscritosNoDia);
    }

    //-- Logica
    int contadorDeDias = 0;
    while (inscritosAtuais < inscritosNecessarios){
        //Passar o dia
        contadorDeDias ++;

        //Calcular novos inscritos do dia
        //Determinando a media
        int soma = 0;
        for (int i = 0; i < 30; i++) {
            soma += fila_diaria_inscritos.fila[i];
        }
        double mediaUltimos30Dias = (double)soma / 30;

        //Atualizar fila de novos inscritos diarios
        int novosInscritosNoDia = ceil(mediaUltimos30Dias);
        fila_remove(&fila_diaria_inscritos);
        fila_insere(&fila_diaria_inscritos, novosInscritosNoDia);

        //Calculando total de inscritos no dia
        inscritosAtuais += novosInscritosNoDia;
    }

    //Mostrando quantidade de dias necessarios
    printf("%d\n", contadorDeDias);

    return 0;
}

void fila_insere(tipo_fila* filaInteiros, int novoInteiro){
    filaInteiros->fila[filaInteiros->contador] = novoInteiro;
    filaInteiros->contador ++;
}

int fila_remove(tipo_fila* filaInteiros){
    filaInteiros->contador --;
    for (int i = 0; i < filaInteiros->contador; i++) {
        filaInteiros->fila[i] = filaInteiros->fila[i + 1];
    }
    return filaInteiros->fila[0];
}

void fila_mostra(tipo_fila filaInteiros){
    for (int i = 0; i < filaInteiros.contador; i++) {
        if (i == 0) {
            printf("%d", filaInteiros.fila[i]);
        }
        else if(i == filaInteiros.contador - 1){
            printf(" %d\n", filaInteiros.fila[i]);
        }
        else{
            printf(" %d", filaInteiros.fila[i]);
        }
    }
}