#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct pilha{
    int* pilhaInts;
    int contador;
} pilha;

void pilha_inserir(pilha*, int);
int pilha_remover(pilha*);
void pilha_mostrar(pilha);
void pilha_preencherInversa(pilha*, int);


int main(){
    //Pegar quantidade de vagoes, ate receber 0 vagoes
    int quantVagoes;
    while (1){
        //printf("Pegando quantidade de vagoes: ");
        scanf("%d", &quantVagoes);
        if (quantVagoes == 0) {
            break;
        }
        getchar();

        //Repetir ate receber 0, tratamento de cada caso
        while (1) {
            //Criar pilha para guardar saidaDeVagoes
            pilha pilhaSaidaDesejada;
            pilhaSaidaDesejada.contador = 0;
            pilhaSaidaDesejada.pilhaInts = (int*)malloc(sizeof(int) * quantVagoes);

            //Criando vetor temporario, para armazenar entrada e repassar invertida para pilhaSaidaDesejada
            int* tempSaidaDesejada = (int*)malloc(sizeof(int) * quantVagoes);

            //Receber saidaDeVagoes, int a int, Realizar quantVagoes leituras, inserir na pilha
            //printf("Recebendo vagoes:\n");
            int numVagao;
            for (int i = 0; i < quantVagoes; i++) {
                scanf("%d", &numVagao);

                //Se scanear um 0 encerrar
                if(numVagao == 0){
                    break; 
                }

                //Inserir dados no vetor temporario
                tempSaidaDesejada[i] = numVagao;
                
            }
            getchar();
            //Se scanear um 0 encerrar
            if(numVagao == 0){
                //printf("Encerrando recepcao de vagoes\n");
                printf("\n");
                break; 
            }

            //repassar ordem de saida invertida para pilhaSaidaDesejada
            for (int i = quantVagoes - 1; i >= 0; i--) {
                //printf("%d\n", tempSaidaDesejada[i]);
                pilha_inserir(&pilhaSaidaDesejada, tempSaidaDesejada[i]);
            }

            //Criar e inicializar pilhaEntrada com int's de 1 ate quantVagoes
            pilha pilhaEntrada;
            pilhaEntrada.contador = 0;
            pilhaEntrada.pilhaInts = (int*)malloc(sizeof(int) * quantVagoes);
            pilha_preencherInversa(&pilhaEntrada, quantVagoes);

            //Crio pilhaEstacao, alocar memoria, deixar vazia
            pilha pilhaEstacao;
            pilhaEstacao.contador = 0;
            pilhaEstacao.pilhaInts = (int*)malloc(sizeof(int) * quantVagoes);
            
            //Identificar se a saida e possivel ou nao
            //Repetir
            while(1){
                //A estacao esta vazia?
                //Sim
                if (pilhaEstacao.contador == 0) {
                    //A entrada esta vazia?
                    //Sim
                    if (pilhaEntrada.contador == 0) {
                        printf("Yes\n");
                        break;
                    }
                    //Nao
                    else{
                        pilha_inserir(&pilhaEstacao, pilha_remover(&pilhaEntrada));
                    }
                }
                //Nao
                else{
                    //O vagao do topo da estacao e igual ao vagao alvo
                    int vagaoTopoEstacao = pilha_remover(&pilhaEstacao);
                    pilha_inserir(&pilhaEstacao, vagaoTopoEstacao);

                    int vagaoTopoSaidaDesejada = pilha_remover(&pilhaSaidaDesejada);
                    pilha_inserir(&pilhaSaidaDesejada, vagaoTopoSaidaDesejada);
                    //Sim
                    if (vagaoTopoEstacao == vagaoTopoSaidaDesejada) {
                        pilha_remover(&pilhaEstacao);
                        pilha_remover(&pilhaSaidaDesejada);
                    }
                    //Nao
                    else{
                        //A entrada esta vazia?
                        //Sim
                        if (pilhaEntrada.contador == 0) {
                            printf("No\n");
                            break;
                        }
                        //Nao
                        else{
                            pilha_inserir(&pilhaEstacao, pilha_remover(&pilhaEntrada));
                        }
                    }
                }
            }

        }

    }
    
    return 0;
}

void removeEspacos(char *str) {
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i]; 
        }
    }
    str[j] = '\0'; 
}

void pilha_preencherInversa(pilha* pilha, int alvo){
    for (int i = alvo; i > 0; i--) {
        pilha_inserir(pilha, i);
    }
}

void pilha_inserir(pilha* pilha, int novoInt){
    pilha->pilhaInts[pilha->contador] = novoInt;
    pilha->contador++;
}

int pilha_remover(pilha* pilha){
    if (pilha->contador > 0) {
        pilha->contador--;
        return pilha->pilhaInts[pilha->contador];
    } else {
        printf("Nao e possivel remover, pilha vazia!\n");
        return -1;
    }
}

void pilha_mostrar(pilha pilha){
    printf("Mostrando pilha: ");
    if (pilha.contador == 0) {
        printf("Tentando mostrar pilha vazia!");
    }
    else{
        for (int i = 0; i < pilha.contador; i++) {
            printf("%d", pilha.pilhaInts[i]);
            if (i < pilha.contador - 1) {
                printf(" ");
            }
        } 
    }
    printf("\n");
    
}
