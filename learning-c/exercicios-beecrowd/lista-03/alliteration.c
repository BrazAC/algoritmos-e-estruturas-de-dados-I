#include <stdlib.h>
#include <stdio.h>

int main(){
    int vetInt[10], dado, cont = 0;

    while (scanf("%d", &vetInt[cont]) != -1) {
        cont ++;

        if (getchar() == '\n') {break;}
    }

    for (int i = 0; i < cont; i++){
        printf("%d ", vetInt[i]);
    }

    printf("\n");

    return 0;
}