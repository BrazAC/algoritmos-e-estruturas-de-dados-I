#include <stdlib.h>
#include <stdio.h>
#include "fila_functions.h"

int main(){
    tipo_fila minhaFila;
    minhaFila.contador = 0;

    fila_insereFinal(&minhaFila, 3);
    fila_insereFinal(&minhaFila, 4);
    fila_insereInicio(&minhaFila, 1);
    fila_inserePosEspecifico(&minhaFila, 2, 20);
    fila_inserePosEspecifico(&minhaFila, 5, 10);
    fila_mostrar(minhaFila);

    fila_removeValEspecifico(&minhaFila, 66);
    fila_mostrar(minhaFila);

    fila_ordenar(&minhaFila);
    fila_mostrar(minhaFila);

    return 0;
}
