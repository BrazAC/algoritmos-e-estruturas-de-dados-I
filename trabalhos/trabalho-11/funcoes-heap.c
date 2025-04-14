#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

void heap_removeEmostraX(tipo_heap heap, int quant, char criterio){
    if(heap == NULL){ 
        printf("[AVISO] Lista vazia\n");
        return;
    }

    //Exibir criterio
    if (criterio == 'c'){
        //Casos totais (confirmados)
        printf("[%s] MOSTRANDO INFORMACOES SOBRE CASOS\n", "confirmados");
    }
    else if (criterio == 'm'){
        //Casos de morte
        printf("[%s] MOSTRANDO INFORMACOES SOBRE CASOS\n", "mortes");
    }
    else if(criterio == 'r'){
        //Casos de recuperacao
        printf("[%s] MOSTRANDO INFORMACOES SOBRE CASOS\n", "recuperados");
    }


    //Exibir dados removidos
    while(quant != 0){
        printf("_________________________________________________________________________________________\n");
        printf("| Pais/Regiao: %s\n", aux->pais);
        printf("| Confirmados: %d | Mortes: %d | Recuperados: %d | Mortes/100: %d | Recuperados/100: %d |\n", 
            aux->confirmados, 
            aux->mortes, 
            aux->recuperados,
            aux->mortes100,
            aux->recuperados100
        );

        quant --;
    }
}