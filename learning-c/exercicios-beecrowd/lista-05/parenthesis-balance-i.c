#include <stdlib.h>
#include <stdio.h>

typedef struct tipo_pilha{
    char* pilhaStrings;
    int contador;
} tipo_pilha;

void pilha_inserir(tipo_pilha*, char);
char pilha_remover(tipo_pilha*);
void pilha_mostrar(tipo_pilha);

int main(){
    //Ler strings linha-a-linha ate EOF
    char* stringExpressao = (char*)malloc(sizeof(char) * 10001);
    //printf("%s\n", stringExpressao);

    //Repetir ate fgets receber apenas '\n' do buffer
    while(scanf("%s", stringExpressao) != EOF){
        //Inicializando pilha
        tipo_pilha pilhaParAbertura;
        pilhaParAbertura.contador = 0;
        pilhaParAbertura.pilhaStrings = (char*)malloc(sizeof(char) * 10001);

        //Iterar por toda a string
        int cont = 0, estado = 1;
        
        while(stringExpressao[cont] != '\0') {
            //Se encontrar um ')' verificar se existe um '(' na pilha
            if (stringExpressao[cont] == ')') {
                //Se sim, remover '(' da pilha
                if (pilhaParAbertura.contador > 0) {
                    pilha_remover(&pilhaParAbertura);
                }
                else{
                    //Se nao atualizar estado
                    estado = 0;
                }
            }else if (stringExpressao[cont] == '('){
                pilha_inserir(&pilhaParAbertura, stringExpressao[cont]);
            }
            //printf("%c ", stringExpressao[cont]);
            cont++;
        }

        if (estado == 0) {
            printf("incorrect\n");
        }
        else if(estado == 1 && pilhaParAbertura.contador == 0){
            printf("correct\n");
        }else if (pilhaParAbertura.contador > 0){
            printf("incorrect\n");
        }
    }

    return 0;
}

void pilha_inserir(tipo_pilha* pilha, char novoChar){
    pilha->pilhaStrings[pilha->contador] = novoChar;
    pilha->contador ++;
}

char pilha_remover(tipo_pilha* pilha){
    pilha->contador --;
    return pilha->pilhaStrings[pilha->contador];
}

void pilha_mostrar(tipo_pilha pilha){
    for (int i = 0; i < pilha.contador; i++) {
        if (i == 0) {
            printf("%c", pilha.pilhaStrings[i]);
        }
        else if (i == pilha.contador - 1) {
            printf("%c\n", pilha.pilhaStrings[i]);
        }
        else{
            printf(" %c", pilha.pilhaStrings[i]);
        }
    }
}