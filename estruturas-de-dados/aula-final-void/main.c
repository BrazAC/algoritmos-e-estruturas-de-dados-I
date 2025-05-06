#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main(){
    tipo_noh* arvore = NULL;

    ab_insere(&arvore, 10, 4444, "Braz Amorim");
    ab_insere(&arvore, 4, 1565, "Gregorio Mamares");
    ab_insere(&arvore, 14, 5643, "Galvino");

    ab_mostraNivel(arvore, 1);
    printf("\n");

    return 0;
}