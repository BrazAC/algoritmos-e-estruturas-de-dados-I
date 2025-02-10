#include <stdlib.h>
#include <stdio.h>

//Prototipagem
void inserePilha(int *, int *, int);
int removePilha(int *, int *);
void mostraPilha(int *, int);
void mostraPilhaReverse(int *, int);

int main(){
    //Obter o total de cartas
    int totalCartas;

    //Enquanto totalCartas != 0, fazer
    scanf("%d", &totalCartas);
    while (totalCartas != 0) {
        //Criar e preencher pilha de 1 ate totaCartas elementos
        //Pilha
        int *pilha = (int*)malloc(sizeof(int) * totalCartas);
        //Contador da pilha
        int contPilha = 0;
        
        //Preencher pilha
        for (int i = totalCartas; i >= 1; i--){
            inserePilha(pilha, &contPilha, i);
        }

        int cartaTopo, cartaNovoTopo, contPilhaSuporte = 0;
        int *pilhaSuporte = (int*)malloc(sizeof(int) * totalCartas);

        int *pilhaDescartadas = (int*)malloc(sizeof(int) * (totalCartas - 1)), contPilhaDescartadas = 0;
        //Repetir enquanto contPilha >= 2
        while (contPilha > 2) {
            //Tirar carta do topo
            cartaTopo = removePilha(pilha, &contPilha);
            //Tirar e guardar carta do novo topo
            cartaNovoTopo = removePilha(pilha, &contPilha);
            //Mover cartas para a pilha auxiliar
            while (contPilha > 0) {
                inserePilha(pilhaSuporte, &contPilhaSuporte, removePilha(pilha, &contPilha));
            }
            
            //Mover novoTopo para o fundo da pilha
            inserePilha(pilha, &contPilha, cartaNovoTopo);
            //Mover cartas da pilhaSuporte para pilha
            while (contPilhaSuporte > 0) {
                inserePilha(pilha, &contPilha, removePilha(pilhaSuporte, &contPilhaSuporte));
            }
            //Adicionar carta descartada a pilhaDescartadas
            inserePilha(pilhaDescartadas, &contPilhaDescartadas, cartaTopo);
        }
        //Descartar ultima carta do topo, adicionar a pilha de descartadas
        inserePilha(pilhaDescartadas, &contPilhaDescartadas, removePilha(pilha, &contPilha));
        
        //Saidas
        printf("Discarded cards: ");
        mostraPilha(pilhaDescartadas, contPilhaDescartadas);
        printf("Remaining card: %d\n", removePilha(pilha, &contPilha));

        //Obter proximo totalCartas
        scanf("%d", &totalCartas);
    }

    return 0;
}

void inserePilha(int *pilha, int* contador,int carta){
    pilha[*contador] = carta;
    (*contador) ++;
    
}

int removePilha(int *pilha, int* contador){
    (*contador) --;
    return pilha[*contador];
}

void mostraPilha(int *pilha, int contador){
    
    for (int i = 0; i < contador; i++) {
        if (i == 0) {
            printf("%d", pilha[i]);
        }else{
            printf(", %d", pilha[i]);
        }
        
    }
    printf("\n");
}

void mostraPilhaReverse(int *pilha, int contador){
    for (int i = (contador - 1); i >= 0; i--) {
        if (i == (contador - 1)) {
            printf("%d", pilha[i]);
        }else{
            printf(", %d", pilha[i]);
        }
        
    }
    printf("\n");
}