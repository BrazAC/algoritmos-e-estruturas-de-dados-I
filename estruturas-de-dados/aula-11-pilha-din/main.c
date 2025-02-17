#include <stdlib.h>
#include <stdio.h>
#include "funcoes-pilha-din.h"


int main(){
    tipo_no *prtBase;
    prtBase = NULL;

    pilhaDin_insere(&prtBase, 87);
    pilhaDin_insere(&prtBase, 62);
    pilhaDin_insere(&prtBase, 23);
    pilhaDin_mostra(&prtBase);
    pilhaDinRec_mostra(&prtBase);


    return 0;
}