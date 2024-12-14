/*
UFMT
Aluno: Braz Amorim
Disciplina: EDI
Professor: Ivairton
*/

#include <stdio.h>

#define QUAT_CADASTROS 3

//Declaracao dos enumerates
enum enum_situacao {APROVADO, REPROVADO};
typedef enum enum_situacao enum_situacao;

//Declaracao dos strucs
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

int main(){
    //Inicializar um struct do tipo turma
    printf(">>-------------CRIACAO DE TURMA-------------<<\n");
    struct_Turma Turma;
    /*CADASTRAR DADOS DA TURMA POR ENTRADA*/
    /*PERMITIR CRIACAO DE MAIS DE UMA TURMA*/

    //Cadastrar QUAT_CADASTROS alunos no struct da turma
    printf(">>------------CADASTRO DE ALUNOS------------<<\n");
    for (int i = 0; i < QUAT_CADASTROS; i++) {
        //Inicializar struct aluno
        tipo_Aluno Aluno;
        printf("CADASTRANDO ALUNO %d\n", i + 1);
        printf("Informe o nome: ");
        scanf("%s", Aluno.nome);
        printf("Informe o RA: ");
        scanf("%d", &Aluno.RA);
        printf("Informe a nota1: ");
        scanf("%f", &Aluno.nota1);
        printf("Informe a nota2: ");
        scanf("%f", &Aluno.nota2);

        //Cadastro aluno no struct aluno
        Turma.alunos[i] = Aluno;
        //Atualizar media do aluno
        Turma.alunos[i].media = (Aluno.nota1 + Aluno.nota2) / 2;
        //Atualizar situacao do aluno
        if(Turma.alunos[i].media < 5){
            Aluno.situacao = REPROVADO;
        }else{
            Aluno.situacao = APROVADO;
        }
    }
        
    //Iterar pelos alunos da turma contando e depois mostrando:
    float somaMedias = 0;
    int quantAprovados = 0;
    int quantReprovados = 0;
    

    printf("\n>>------------SITUACAO DOS ALUNOS------------<<\n");
    for(int j = 0; j < QUAT_CADASTROS; j++){
        //Quantos e quais foram aprovados e quantos foram reprovados
        if(Turma.alunos[j].situacao == APROVADO){
            quantAprovados += 1;
            printf("Aluno: %s\nSituacao: APROVADO\n===---===---===\n", Turma.alunos[j].nome);
        }else{
            quantReprovados += 1;
            printf("Aluno: %s\nSituacao: APROVADO\n===---===---===\n", Turma.alunos[j].nome);
        }

        //Qual a media das medias dos alunos   
        somaMedias += Turma.alunos[j].media;
    }

    //Quantos foram aprovados e quantos foram reprovados
    printf("%d Alunos aprovados\n", quantAprovados);
    printf("%d Alunos reprovados\n", quantReprovados);

    //Qual a media das medias dos alunos  
    printf("Media da turma: %f\n", somaMedias / QUAT_CADASTROS);   
    
    


    return 0;
}