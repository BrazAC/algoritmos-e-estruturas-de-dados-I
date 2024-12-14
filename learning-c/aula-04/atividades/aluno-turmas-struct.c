/*
UFMT
Aluno: Braz Amorim
Disciplina: EDI
Professor: Ivairton
*/

#include <stdio.h>

#define QUAT_CADASTROS 2
#define QUAT_CADASTROS_TURMAS 1

//Declaracao dos enumerates
enum enum_situacao {APROVADO, REPROVADO};
typedef enum enum_situacao enum_situacao;

//Declaracao dos structs
struct struct_Aluno {
    char nome[60];
    unsigned int RA;
    float nota1, nota2, media;
    enum_situacao situacao;
    
};
typedef struct struct_Aluno tipo_Aluno;

struct struct_Turma {
    char nome[60];
    int codigo;
    int ano;
    int quantidade_alunos;
    tipo_Aluno alunos[40];
};
typedef struct struct_Turma struct_Turma;

struct struct_Escola {
    struct_Turma turmas[QUAT_CADASTROS_TURMAS];
};
typedef struct struct_Escola struct_Escola;

//Prototipagem das funcoes;
void mostra_menu();
void mostra_turmas(struct_Escola);
void mostra_status_alunos_turma(struct_Escola);
struct_Escola cadastra_turmas(struct_Escola);
struct_Escola cadastra_alunos(struct_Escola);
struct_Turma* encontra_turma(int, struct_Escola*);

int main(){
    //Criar escola (vetor de turmas)
    struct_Escola Escola;

    //CRIANDO MENU
    int menu_opcao;
    mostra_menu();
    while(scanf("%d", &menu_opcao) != EOF){
        switch (menu_opcao){
            case 1:
                Escola = cadastra_turmas(Escola);
                break;
            
            case 2:
                Escola = cadastra_alunos(Escola);
                break;
            
            case 3:
                mostra_turmas(Escola);
                break;
            
            case 4:
                mostra_status_alunos_turma(Escola);
                break;
        }

        //Mostrar menu e pegar nova opcao
        printf("\n");
        mostra_menu();
    }

    return 0;
}

//Declaracao das funcoes
void mostra_menu(){
    printf("_______________________________________________\n");
    printf(">>====SUPER MEGA CONTROLE ESCOLAR 3000=======<<\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("Sair: Ctrl + d\n");
    printf("1 - Cadastrar turmas\n");
    printf("2 - Cadastrar alunos em uma turma\n");
    printf("3 - Ver turmas cadastradas\n");
    printf("4 - Ver status dos alunos de uma turma\n");
    printf("Escolha uma opcao: ");
}

void mostra_turmas(struct_Escola Escola){
    printf("\n>>-------------MOSTRAR TURMAS-------------<<\n");
    for (int i = 0; i < QUAT_CADASTROS_TURMAS; i++) {
        printf("Mostrando turma %d de %d\n", (i + 1), QUAT_CADASTROS_TURMAS);
        printf("Nome: %s\n", Escola.turmas[i].nome);
        printf("Codigo: %d\n", Escola.turmas[i].codigo);
        printf("Ano: %d\n", Escola.turmas[i].ano);
        printf("Quantidade de alunos: %d\n\n", Escola.turmas[i].quantidade_alunos);
        
    }
}

void mostra_status_alunos_turma(struct_Escola Escola){
    printf("\n>>---------VER STATUS DE ALUNOS DE TURMA---------<<\n");
    //Identificar a turma
    int codigo_turma;
    printf("Informe o codigo da turma: ");
    scanf("%d", &codigo_turma);
    struct_Turma *Turma = encontra_turma(codigo_turma, &Escola);
    printf("Nome da turma: %s\n", (*Turma).nome);
    //Mostrar status dos alunos da turma
    //Iterar pelos alunos da turma contando e depois mostrando:
    float somaMedias = 0;
    int quantAprovados = 0;
    int quantReprovados = 0;
    

    printf("\n>>------------SITUACAO DOS ALUNOS------------<<\n");
    for(int j = 0; j < QUAT_CADASTROS; j++){
        //Quantos e quais foram aprovados e quantos foram reprovados
        if((*Turma).alunos[j].situacao == APROVADO){
            quantAprovados += 1;
            printf("Aluno: %s\nSituacao: APROVADO\n", (*Turma).alunos[j].nome);
            printf("Media: %f\n", (*Turma).alunos[j].media);
            printf("===---===---===\n");
        }else if ((*Turma).alunos[j].situacao == REPROVADO){
            quantReprovados += 1;
            printf("Aluno: %s\nSituacao: REPROVADO\n", (*Turma).alunos[j].nome);
            printf("Media: %f\n", (*Turma).alunos[j].media);
            printf("===---===---===\n");
        }

        //Qual a media das medias dos alunos   
        somaMedias += (*Turma).alunos[j].media;
    }

    //Quantos foram aprovados e quantos foram reprovados
    printf("%d Alunos aprovados\n", quantAprovados);
    printf("%d Alunos reprovados\n", quantReprovados);

    //Qual a media das medias dos alunos  
    printf("Media da turma: %f\n", somaMedias / QUAT_CADASTROS);
}

struct_Escola cadastra_turmas(struct_Escola Escola){
    //Cadastrar QUAT_CADASTROS_TURMAS turmas na escola
    printf("\n>>-------------CADASTRO DE TURMAS-------------<<\n");
    for (int i = 0; i < QUAT_CADASTROS_TURMAS; i++) {
        printf("Cadastro da turma %d de %d\n", (i + 1), QUAT_CADASTROS_TURMAS);
        //Inicializar um struct do tipo turma
        struct_Turma Turma;
        /*CADASTRAR DADOS DA TURMA POR ENTRADA*/
        printf("Informe o nome: ");
        scanf("%s", Turma.nome);
        printf("Informe o codigo: ");
        scanf("%d", &Turma.codigo);
        printf("Informe o ano: ");
        scanf("%d", &Turma.ano);
        //printf("Informe a quantidade de alunos: ");
        //scanf("%d", &Turma.quantidade_alunos);
        Turma.quantidade_alunos = 0;
        //Cadastrar turma na escola
        Escola.turmas[i] = Turma;
    }
    return Escola;
}

struct_Turma* encontra_turma(int codigo_turma, struct_Escola *Escola){
    for (int i = 0; i < QUAT_CADASTROS_TURMAS; i++) {
        if ((*Escola).turmas[i].codigo == codigo_turma) {
            return &(*Escola).turmas[i];
        }
    }
}

struct_Escola cadastra_alunos(struct_Escola Escola){
    printf("\n>>------------CADASTRO DE ALUNOS------------<<\n");
    //Identificar a turma para cadastrar os alunos
    int codigo_turma;
    printf("Informe o codigo da turma: ");
    scanf("%d", &codigo_turma);

    //Retornando uma COPIA de um struct_turma pertencente ao struct_escola
    struct_Turma *Turma = encontra_turma(codigo_turma, &Escola);
    
    //Cadastrar alunos na turma
    //Cadastrar QUAT_CADASTROS alunos no struct da turma
    
    for (int i = 0; i < QUAT_CADASTROS; i++) {
        //Inicializar struct aluno
        tipo_Aluno Aluno;
        printf("\nCADASTRANDO ALUNO %d de %d\n", i + 1, QUAT_CADASTROS);
        printf("Informe o nome: ");
        scanf("%s", Aluno.nome);
        printf("Informe o RA: ");
        scanf("%d", &Aluno.RA);
        printf("Informe a nota1: ");
        scanf("%f", &Aluno.nota1);
        printf("Informe a nota2: ");
        scanf("%f", &Aluno.nota2);

        //Cadastro aluno no struct aluno
        (*Turma).alunos[i] = Aluno;

        //Atualizar media do aluno
        (*Turma).alunos[i].media = (Aluno.nota1 + Aluno.nota2) / 2;
        //Atualizar situacao do aluno
        if((*Turma).alunos[i].media < 5){
            (*Turma).alunos[i].situacao = REPROVADO;
        }else if((*Turma).alunos[i].media >= 5){
            (*Turma).alunos[i].situacao = APROVADO;
        }
        //Aumentar quantidade de alunos da turma
        (*Turma).quantidade_alunos += 1;
    }

    return Escola;
}