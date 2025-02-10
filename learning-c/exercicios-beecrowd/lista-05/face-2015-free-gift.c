#include <stdlib.h>
#include <stdio.h>

typedef struct tipo_pilha{
    char** pilhaStrings;
    int contador;
} tipo_pilha;

void pilha_inserir(tipo_pilha*, char*);
char* pilha_remover(tipo_pilha*);
void pilha_mostrar(tipo_pilha);
char* inverteString(char*);
int confereIgualdadeStrings(char*, char*);

int main(){
    //Obter quantidade de visitantes
    int quantVisitantes;
    scanf("%d", &quantVisitantes);
    getchar();

    //Inicializar pilha, inserir primeira string
    tipo_pilha pilha;
    pilha.contador = 0;
    pilha.pilhaStrings = (char**)malloc(sizeof(char*) * (quantVisitantes + 1));
    char primeiraString[4] = {'F', 'A', 'C', 'E'};
    pilha_inserir(&pilha, primeiraString);
    

    //Inicializar contador de premiados
    int contPremiados = 0;

    //Repetir quantidadeDeVisitantes vezes
    for (int i = 0; i < quantVisitantes; i++) {
        //Obter string, inserir na pilha
        char* novaString = (char*)malloc(sizeof(char) * 4);
        scanf("%c %c %c %c", &novaString[0], &novaString[1], &novaString[2], &novaString[3]);
        //Retirar '\n'
        getchar();
        
        //Inserir na pilha
        pilha_inserir(&pilha, novaString);
        
        //Inverter novaString por copia (a string invertida nao sera adicionada a lista)
        char* novaStringInvertida = inverteString(novaString);

        //Se novaString (invertida) == stringAnterior
        if (confereIgualdadeStrings(pilha.pilhaStrings[pilha.contador - 2], novaStringInvertida) == 1){
            //Remover dois elementos da pilha
            pilha_remover(&pilha);
            pilha_remover(&pilha);
            //Incrementar contadorDePremiados
            contPremiados ++;
        }

        //Se o painel ficar vazio, inserir F A C E
        if (pilha.contador == 0) {
            pilha_inserir(&pilha, primeiraString);
        }
    }

    //Mostrar contadorDePremiados
    printf("%d\n", contPremiados);

    return 0;
}

void pilha_inserir(tipo_pilha* pilha, char* novaString){
    pilha->pilhaStrings[pilha->contador] = novaString;
    pilha->contador ++;
}

char* pilha_remover(tipo_pilha* pilha){
    pilha->contador --;
    return pilha->pilhaStrings[pilha->contador];
}

void pilha_mostrar(tipo_pilha pilha){
    for (int i = 0; i < pilha.contador; i++) {
        if (i == 0) {
            printf("%s", pilha.pilhaStrings[i]);
        }
        else if (i == pilha.contador - 1) {
            printf("%s\n", pilha.pilhaStrings[i]);
        }
        else{
            printf(" %s", pilha.pilhaStrings[i]);
        }
    }
}

char* inverteString(char* stringOriginal){
    char* stringInvertida = (char*)malloc(sizeof(char) * 4);
    stringInvertida[0] = stringOriginal[3];
    stringInvertida[1] = stringOriginal[2];
    stringInvertida[2] = stringOriginal[1];
    stringInvertida[3] = stringOriginal[0];
    return stringInvertida;
}

int confereIgualdadeStrings(char* stringOriginal, char* stringInvertida){
    if (stringInvertida[0] == stringOriginal[0] &&
        stringInvertida[1] == stringOriginal[1] &&
        stringInvertida[2] == stringOriginal[2] &&
        stringInvertida[3] == stringOriginal[3]) {
        
        return 1;
    }
    return 0;
}