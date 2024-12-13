#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *prt;

    scanf("%d", &n);

    prt = malloc(n * sizeof(int));
    prt = (int*)prt;

    printf("Você alocou %lu bytes de memoria no endereço: %p\n", n * sizeof(*prt), (void*)prt);
    printf("Você alocou %lu bytes de memoria no endereço: %p\n", n * sizeof(prt), (void*)prt);

    return 0;
}   