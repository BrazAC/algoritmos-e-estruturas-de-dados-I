/*
UFMT
Aluno: Braz Amorim
Disciplina: EDI
Professor: Ivairton
*/

#include <stdio.h>

#define TAM_vet 2
#define TAM_vendas 2

//Definindo da estrutura do struct
struct struct_Produto {
    int codigo;
    float preco_custo;
    float preco_venda;
};

//Atribuir apelido para nao precisar usar "struct nomeStruc"
typedef struct struct_Produto Produto;

struct struct_Venda {
    Produto produtosVendidos[TAM_vendas];
    int quantProdutos[TAM_vendas];
    float valorVenda;
    float subtotal[TAM_vendas];
};

typedef struct struct_Venda Venda;

int main(){
    //Criacao de um vetor do tipo struct definido
    Produto vet_produtos[TAM_vet];

    //Declaracao e inicializacao dos produtos no vetor
    printf("--------------CADASTRO DE PRODUTOS--------------\n");
    for (int i = 0; i < TAM_vet; i++) {
        //Declaracao do struct
        Produto produto;

        //Inicializacao do struct criado
        printf("Insira o codigo do produto: ");
        scanf("%d", &produto.codigo);
        printf("Insira o preco de custo do produto: ");
        scanf("%f", &produto.preco_custo);
        printf("Insira o preco de venda do produto: ");
        scanf("%f", &produto.preco_venda);
        
        //Armazenando no vetor de produtos
        vet_produtos[i] = produto;
    }

    //Acessando dados dos structs dentro do vetor
    printf("--------------PRODUTO CADASTRADOS--------------\n");
    for (int j = 0; j < TAM_vet; j++) {
        printf("Codigo: %d\n", vet_produtos[j].codigo);
        printf("Preco custo: %.2f\n", vet_produtos[j].preco_custo);
        printf("Preco venda: %.2f\n\n", vet_produtos[j].preco_venda);
    }
    
    //Realizando venda
    printf("\n=====> REALIZANDO VENDA\n");   
    int codigo;
    Venda venda;
    venda.valorVenda = 0;

    //Fazer TAM_vendas vezes
    for (int k = 0; k < TAM_vendas; k++) {
        printf("Informe o codigo do produto: ");
        scanf("%d", &codigo);
        printf("Informe a quantidade do produto: ");
        scanf("%d", &venda.quantProdutos[k]);
        printf("===---===---===---===\n");

        //Encontrando e guardando o produto no vetor de vendas
        for (int i = 0; i < TAM_vet; i++) {
            if(vet_produtos[i].codigo == codigo){
                venda.produtosVendidos[k] =  vet_produtos[i];
            }
        }

        //Calculando o subtotal
        venda.subtotal[k] = venda.produtosVendidos[k].preco_venda * venda.quantProdutos[k];

        //Calculando o valor da venda
        venda.valorVenda += venda.produtosVendidos[k].preco_venda * venda.quantProdutos[k];
    }

    //Mostrar dados sobre a venda
    printf("=====> INFO SOBRE A VENDA\n");
    for (int j = 0; j < TAM_vendas; j++) {
        printf("Produto: %d\n", venda.produtosVendidos[j].codigo);
        printf("Vendeu: %d unidade(s)\n", venda.quantProdutos[j]);
        printf("Subtotal: %.2f R$\n\n", venda.subtotal[j]);
    }    
    printf("->VALOR TOTAL DA VENDA: %.2f R$\n", venda.valorVenda);

    return 0;
}