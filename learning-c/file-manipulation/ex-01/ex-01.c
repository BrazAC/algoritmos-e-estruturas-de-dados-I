/*
- Crie um arquivo
- Cadastre alunos no arquivo (nome, idade)
- Feche o arquivo
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME_TURMA 51
#define TAM_NOME_ALUNOS 51

typedef struct struct_aluno {
    char nome[TAM_NOME_ALUNOS];
    int idade;
} struct_aluno;

typedef struct struct_turma {
    char nomeTurma[TAM_NOME_TURMA];
    int quantidadeDeAlunos;
    struct_aluno *vetorAlunos;
} struct_turma;

int retiraQuebraRetornaTamanho(char*);

int main(){
    //-- Obter dados 
    //Obter info turma
    //Criar struct_turma
    struct_turma Turma;
    //Obter nome da turma
    printf("Informa o nome da turma: \n");
    fgets(Turma.nomeTurma, TAM_NOME_TURMA, stdin);
    //Tirar '\n' do nomeTurma
    retiraQuebraRetornaTamanho(Turma.nomeTurma);
    //Obter quantidade de alunos da turma
    printf("Informe a quantidade de alunos da turma: ");
    scanf("%d", &Turma.quantidadeDeAlunos);
    getchar();
    //ALocar vetor de alunos
    Turma.vetorAlunos = (struct_aluno*)malloc(Turma.quantidadeDeAlunos * sizeof(struct_aluno));

    //Obter info alunos
    //Repetir
    for (int i = 0; i < Turma.quantidadeDeAlunos; i ++) {
        printf("Cadastrando aluno %d\n", i);
        //Criar struct_aluno
        struct_aluno Aluno;
        //Obter e cadastrar nome do aluno
        printf("Informe o nome do aluno: \n");
        fgets(Aluno.nome, TAM_NOME_ALUNOS, stdin);
        retiraQuebraRetornaTamanho(Aluno.nome);
        //Obter e cadastrar idade do aluno
        printf("Informe a idade do aluno: ");
        scanf("%d", &Aluno.idade);
        getchar();
        //Cadastrar struct_aluno em struct_turma.vetorAlunos
        Turma.vetorAlunos[i] = Aluno;
    }

    //-- Cadastrar dados no sistema
    //Criar ponteiro do tipo file
    FILE *fp;
    //Abrir/Criar arquivo no modo de escrita 
    fp = fopen("./files/turma.txt", "w");
    (fp == NULL) ? printf("[ERRO] Falha ao abrir/criar o arquivo\n") : printf("[SUCESSO] Abrindo aquivo\n");
    //- Escrever dados no arquivo
    //Escrever cabecario (dados da turma)
    fputs(Turma.nomeTurma, fp);
    fprintf(fp, "Quantidade de alunos: %d", Turma.quantidadeDeAlunos);
    //Escrever dados dos alunos
    for (int i = 0; i < Turma.quantidadeDeAlunos; i += 1) {
        fputs(Turma.vetorAlunos[i].nome, fp);
        fprintf(fp, "Idade: %d\n", Turma.vetorAlunos[i].idade);
    }
    //Fechar arquivo
    fclose(fp);

    return 0;
}

int retiraQuebraRetornaTamanho(char* stringSuja){
    int tamStringReal = 0;
    while (stringSuja[tamStringReal] != '\0') {
        tamStringReal ++;
    }
    if(stringSuja[tamStringReal] == '\n'){
        stringSuja[tamStringReal] = '\0';
        tamStringReal --;
    }
    return tamStringReal;
}