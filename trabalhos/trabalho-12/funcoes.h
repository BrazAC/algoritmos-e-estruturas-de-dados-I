#ifndef __FUNCOES_H__
#define __FUNCOES_H__

#define MAX_DADOS_CAT (10 + 100) 
#define MAX_NOME_CAT 100
#define MAX_TITULO_PROD 500
#define MAX_CODIGO 15

typedef struct est_noh_ab{
    //O preco e a chave
    float preco;

    //Outras informacoes
    char codigo[MAX_CODIGO];
    char titulo[MAX_TITULO_PROD];
    float avaliacao;
    int categoria;

    //FIlhos
    struct est_noh_ab* esq;
    struct est_noh_ab* dir;

} tipo_noh_ab;

typedef struct est_categoria{
    int id;
    char nome[MAX_NOME_CAT];
    int id_pai;
    tipo_noh_ab *sub_arv_bin;
    int possuiSubArvoreBin;
} tipo_categoria;

typedef struct est_noh_am{
    tipo_categoria dados[MAX_DADOS_CAT];
    struct est_noh_am* filhos[MAX_DADOS_CAT + 1];
    int cont;
} tipo_noh_am;

//--------------------------Funcoes main
void main_carregaPrincipais(FILE* arquivo, tipo_noh_am** arvore);
void main_carregaSecundarias(FILE* arquivo, tipo_noh_am** arvore);
void main_carregaProdutos(FILE* arquivo, tipo_noh_ab** arvore);


//--------------------------Funcoes arvore n-aria
//Insercao
tipo_noh_am* alocaNohAm(int id_cat, int id_pai_cat, char nome_cat[]);
void am_inserePorIdPai(tipo_noh_am **noh, int id_cat, int id_pai_cat, char nome_cat[]);
//Busca
tipo_categoria* am_buscaCategoria(tipo_noh_am *arvore, int id_categoria);
//Visualizacao 
void am_mostraNivel(tipo_noh_am *noh, int nivel);
void am_mostraArv(tipo_noh_am *noh);
void am_preOrdem(tipo_noh_am *noh);
//Especial
void am_carregaTodasSubarvores(tipo_noh_am *arvore, tipo_noh_ab* arv_produtos);

//--------------------------Funcoes arvore binaria
//Insercao
tipo_noh_ab* alocaNoh(float preco, char codigo[], char titulo[], float avaliacao, int id_categoria);
void ab_insere(tipo_noh_ab **noh, float preco, char codigo[], char titulo[], float avaliacao, int id_categoria);
void ab_carregaSubArvoreBin(tipo_categoria *categoria, tipo_noh_ab* arv_produtos);
void ab_buscaTodosEcadastra(tipo_noh_ab **sub_arv_bin, tipo_noh_ab *arv_produtos, int id_categoria);
//Busca
tipo_noh_ab* ab_buscaProduto(tipo_noh_ab *noh, char codigoProduto[]);
//Visualizacao
void ab_mostraNivel(tipo_noh_ab *noh, int nivel);
int ab_calculaAltura(tipo_noh_ab *noh);
void ab_mostraArvore(tipo_noh_ab *noh);
int ab_mostraXmaiores(tipo_noh_ab *noh ,int quant);

#endif