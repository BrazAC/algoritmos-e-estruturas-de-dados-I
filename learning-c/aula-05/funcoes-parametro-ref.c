#include <stdio.h>

int main(){
    int* prt1, prt2; 
    void* prt3;
    prt3 = &prt1 + &prt2;
    printf("%p\n", prt3);
    return 0;
}