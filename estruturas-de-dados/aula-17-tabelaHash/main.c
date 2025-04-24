#include <stdlib.h>
#include <stdio.h>
#include "funcoes-hash.h"

int main(){
    //Inicializar tabela
    est_tabelaHash tabelaHash;
    inicializaTabHash(&tabelaHash);

    //Padrão de chaves, entre 10, 119;
    int chave = 12;
    int chave2 = 32;
    int chave3 = 100;

    //Inserir na tabela
    insereTabHash(&tabelaHash, chave, 32, 31);
    insereTabHash(&tabelaHash, chave2, 67, 76);
    insereTabHash(&tabelaHash, chave3, 45, 23);

    //Remover da tabela
    //removeTabHash(&tabelaHash, 43);
    removeTabHash(&tabelaHash, 100);

    //Mostrar tabela
    mostraTabHash(tabelaHash);
    

}