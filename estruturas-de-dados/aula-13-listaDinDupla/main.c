#include "funcoes-filadindupla.h"
#include <stdlib.h>
#include <stdio.h>

int main(){ 
    tipo_no *prt_base;
    prt_base = NULL;

    listaDinDupla_insereInicio(&prt_base, 45);
    listaDinDupla_insereInicio(&prt_base, 23);
    listaDinDupla_insereInicio(&prt_base, 76);
    listaDinDupla_mostrar(&prt_base);

    return 0;
}