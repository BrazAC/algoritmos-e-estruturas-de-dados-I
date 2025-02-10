#include <stdlib.h>
#include <stdio.h>

typedef struct tipo_fila_string{
    char** fila;
    int contador;
} tipo_fila_string;

void insereFila(tipo_fila_string*, char*);
char* removeFila(tipo_fila_string*, char*);
void mostraFila(tipo_fila_string);
void copiaString(char* , char*);

int main(){
    //-1
    //-3, -2
    //-4
    int contFila_1 = 0, contFila_2 = 0, contFila_3 = 0, contFila_4 = 0;


    //Criar filas -1, -3, -2, -4, ordemFinal
    tipo_fila_string fila_1, fila_2, fila_3, fila_4, ordemFinal;
    fila_1.contador = 0;
    fila_2.contador = 0;
    fila_3.contador = 0;
    fila_4.contador = 0;
    ordemFinal.contador = 0;
    ordemFinal.fila = (char**)malloc(sizeof(char*));
    fila_1.fila = (char**)malloc(sizeof(char*));
    fila_2.fila = (char**)malloc(sizeof(char*));
    fila_3.fila = (char**)malloc(sizeof(char*));
    fila_4.fila = (char**)malloc(sizeof(char*));

    //Criar vetor de entradasIniciais
    char** vetEntradasIniciais = (char**)malloc(sizeof(char*));

    //-- Ler strings ate obter um '0', ir guardando em entradasIniciais
    char* entradaInicial = (char*)malloc(6 * sizeof(char));
    scanf("%s", entradaInicial);
    
    vetEntradasIniciais[0] = entradaInicial;

    //PONTO DE QUEBRA (ate aqui funciona)

    int cont = 0; 
    while (vetEntradasIniciais[cont][0] != '0') {
        //Aumentar capacidade de vetEntradasIniciais
        cont ++;
        vetEntradasIniciais = (char**)realloc(vetEntradasIniciais, sizeof(char*) * (cont + 1));

        //Criar nova string entradaInicial
        char* entradaInicial = (char*)malloc(sizeof(char) * 6);
        scanf("%s", entradaInicial);
        
        
        //Guardar nova entradaInicial em vetEntradasIniciais
        vetEntradasIniciais[cont] = entradaInicial;
    }

    int tamanhoVetEntradas = cont + 1;

    //Iterar por entradaInicial
    int ultimoNumero;
    for (int i = 0; i < (tamanhoVetEntradas - 1); i++){
        //Se for um numero
        if (vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '1'
            || vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '2'
            || vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '3'
            || vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '4'){

                //Identificar qual numero e, guardar em ultimoNumero
                if(vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '1'){
                    ultimoNumero = -1;
                }
                else if(vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '2'){
                    ultimoNumero = -2;
                }
                else if(vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '3'){
                    ultimoNumero = -3;
                }
                else if(vetEntradasIniciais[i][0] == '-' && vetEntradasIniciais[i][1] == '4'){
                    ultimoNumero = -4;
                }

                //printf("Numero: %d\n", ultimoNumero);
        }
        //Senao
        else{
            //String para copia
            char* stringCopia = (char*)malloc(sizeof(char) * 6);           

            //Identificar qual e o ultimoNumero, guardar o nomeAviao na lista do ultimoNumero
            //printf("Aviao: %s\n", vetEntradasIniciais[i]);
            if (ultimoNumero == -1) {
                //Guardar aviao na fila -1
                //Aumentar capacidade de fila_1.fila
                contFila_1 ++;
                fila_1.fila = (char**)realloc(fila_1.fila, sizeof(char*) * (contFila_1 + 1));

                //Copiar string
                copiaString(vetEntradasIniciais[i], stringCopia);
                insereFila(&fila_1, stringCopia);
            }
            if (ultimoNumero == -2) {
                //Guardar aviao na fila -2
                //Aumentar capacidade de fila_1.fila
                contFila_2 ++;
                fila_2.fila = (char**)realloc(fila_2.fila, sizeof(char*) * (contFila_2 + 1));

                copiaString(vetEntradasIniciais[i], stringCopia);
                insereFila(&fila_2, stringCopia);
            }
            if (ultimoNumero == -3) {
                //Guardar aviao na fila -3
                //Aumentar capacidade de fila_1.fila
                contFila_3 ++;
                fila_3.fila = (char**)realloc(fila_3.fila, sizeof(char*) * (contFila_3 + 1));

                copiaString(vetEntradasIniciais[i], stringCopia);
                insereFila(&fila_3, stringCopia);
            }
            if (ultimoNumero == -4) {
                //Guardar aviao na fila -4
                //Aumentar capacidade de fila_1.fila
                contFila_4 ++;
                fila_4.fila = (char**)realloc(fila_4.fila, sizeof(char*) * (contFila_4 + 1));

                copiaString(vetEntradasIniciais[i], stringCopia);
                insereFila(&fila_4, stringCopia);
            }
        }  
    }

    /*
    mostraFila(fila_1);
    mostraFila(fila_2);
    mostraFila(fila_3);
    mostraFila(fila_4);
    */

    //Mostrar fila ordemFinal
    
    //Enquanto uma das filas nao estiver vazia
    while (fila_1.contador > 0 || fila_2.contador > 0 || fila_3.contador > 0 || fila_4.contador > 0){
        //Se fila_1 nao estiver vazia, mover primeiro para ordemFinal
        if (fila_1.contador > 0) {
            char* stringRemovida = (char*)malloc(sizeof(char) * 6);
            insereFila(&ordemFinal, removeFila(&fila_1, stringRemovida));
        }
        
        //Se fila_3 nao estiver vazia, mover primeiro para ordemFinal
        if (fila_3.contador > 0) {
            char* stringRemovida = (char*)malloc(sizeof(char) * 6);
            insereFila(&ordemFinal, removeFila(&fila_3, stringRemovida));
        }
        //Se fila_2 nao estiver vazia, mover primeiro para ordemFinal
        if (fila_2.contador > 0) {
            char* stringRemovida = (char*)malloc(sizeof(char) * 6);
            insereFila(&ordemFinal, removeFila(&fila_2, stringRemovida));
        }
        //Se fila_4 nao estiver vazia, mover primeiro para ordemFinal
        if (fila_4.contador > 0) {
            char* stringRemovida = (char*)malloc(sizeof(char) * 6);
            insereFila(&ordemFinal, removeFila(&fila_4, stringRemovida));
        }
    }

    //Mostrar ordemFinal
    mostraFila(ordemFinal);

   
    return 0;
}

void copiaString(char* stringOriginal, char* stringCopia){
    for (int i = 0; i < 6; i++) {
        stringCopia[i] = stringOriginal[i];
    }

}

void insereFila(tipo_fila_string* filaStrings, char* novaString){
    filaStrings->fila[filaStrings->contador] = novaString;
    filaStrings->contador ++;
    
}

char* removeFila(tipo_fila_string* filaStrings, char* stringRemovida){  
    //Copiar string para retorno
    copiaString(filaStrings->fila[0], stringRemovida);

    for (int i = 0; i < filaStrings->contador; i++) {
        filaStrings->fila[i] = filaStrings->fila[i + 1];
    }
    filaStrings->contador --;
    
    return stringRemovida;
}

void mostraFila(tipo_fila_string filaStrings){
    for (int i = 0; i < filaStrings.contador; i++) {
        if (i == (filaStrings.contador - 1)){
            printf(" %s\n", filaStrings.fila[i]);
        }else if(i == 0){
            printf("%s", filaStrings.fila[i]);
        }
        else{
            printf(" %s", filaStrings.fila[i]);
        }

    }
}