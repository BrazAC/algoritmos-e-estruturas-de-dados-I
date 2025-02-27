#include "filaDin-funcoes.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    tipo_no *prtBase;
    prtBase = NULL;

    //filaDin_mostra(prtBase);
    filaDin_inserePos(&prtBase, 5, 1);
    filaDin_mostra(prtBase);
    //filaDin_inserePos(&prtBase, 5, 2);
    filaDin_insereFinal(&prtBase, 45);
    filaDin_mostra(prtBase);
    filaDin_insereFinal(&prtBase, 13);
    //filaDin_removeInicio(&prtBase);
    //filaDin_inserePos(&prtBase, 5, 4);
    filaDin_mostra(prtBase);
    filaDin_removeFim(&prtBase);
    filaDin_mostra(prtBase);
    filaDin_removeFim(&prtBase);
    filaDin_mostra(prtBase);
    filaDin_removeFim(&prtBase);
    filaDin_mostra(prtBase);

    return 0;
}