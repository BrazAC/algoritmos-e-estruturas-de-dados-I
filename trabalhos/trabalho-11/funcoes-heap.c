#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

void heap_sobeHeap(tipo_heap *heap, int pos){
    int idx_pai = (pos - 1)/2;
    
    if (pos != 0 && (heap->heap[pos].chave > heap->heap[idx_pai].chave)) {
        tipo_dado_heap temp = heap->heap[idx_pai];
        heap->heap[idx_pai] = heap->heap[pos];
        heap->heap[pos] = temp;

        heap_sobeHeap(heap, idx_pai);
    }
}

int heap_inserePorCriterio(tipo_heap *heap, tipo_no_lista novoNohDado, char criterio){
    if (heap->cont == MAX_HEAP) return -1;

    tipo_dado_heap temp;

    //Extrair chave escolhida no criterio
    if (criterio == 'c'){
        //Casos totais (confirmados)
        temp.chave = novoNohDado.confirmados;
    }
    else if (criterio == 'm'){
        //Casos de morte
        temp.chave = novoNohDado.mortes;
    }
    else if(criterio == 'r'){
        //Casos de recuperacao
        temp.chave = novoNohDado.recuperados;
    }
    
    //Extrair resto das informacoes
    temp.confirmados = novoNohDado.confirmados;
    temp.mortes = novoNohDado.mortes;
    temp.recuperados = novoNohDado.recuperados;
    temp.mortes100 = novoNohDado.mortes100;
    temp.recuperados100 = novoNohDado.recuperados100;
    strcpy(temp.pais, novoNohDado.pais);

    //Inserir no heap
    heap->heap[heap->cont] = temp;
    heap->cont ++;

    //Subir elemento
    heap_sobeHeap(heap, heap->cont - 1);
}

void heap_desceHeap(tipo_heap *heap, int pos){
    //Calcular posicao dos filhos esquerdo e direito
    int idx_esq = pos * 2 + 1;
    int idx_dir = pos * 2 + 2;
    int idx_maior_chave;

    //Verificar quais filhos existem e dentre eles quem tem a maior chave
    //Se o filho esquerdo existe
    if(idx_esq < heap->cont){
        //Se o filho direito existe
        if(idx_dir < heap->cont) {
            //Identificar quem possui a maior chave (pq e um heap maximo)
            if(heap->heap[idx_esq].chave > heap->heap[idx_dir].chave){
                idx_maior_chave = idx_esq;
            }
            else{
                idx_maior_chave = idx_dir;
            }
        }
        else{
            //O esquerdo automaticamente tem a maior chave
            idx_maior_chave = idx_esq;
        }


        //Verificar se o filho com a maior chave, tem a chave maior que a do pai
        if (heap->heap[idx_maior_chave].chave > heap->heap[pos].chave){
            //Swap do pai com o filho
            tipo_dado_heap temp = heap->heap[pos];
            heap->heap[pos] = heap->heap[idx_maior_chave];
            heap->heap[idx_maior_chave] = temp;

            //Chamar recursivamente desceHeap
            heap_desceHeap(heap, idx_maior_chave);
        }
    }
}

tipo_dado_heap heap_removeRaiz(tipo_heap *heap){
    if(heap->cont == 0){ 
        printf("[AVISO] Nao e possivel removver de heap vazio\n");
    }
    else{
        //Guardar dado a ser removido
        tipo_dado_heap tempRm = heap->heap[0];
        //Decrementar contador
        heap->cont --;

        //Mover ultimo elemento para a antiga posicao do removido (raiz)
        heap->heap[0] = heap->heap[heap->cont];

        //Descer elemento movido
        heap_desceHeap(heap, 0);

        //Retorna o elemento removido
        return tempRm;
    }
}

void heap_removeEmostraX(tipo_heap* heap, int quant){
    if(heap->cont == 0){ 
        printf("[AVISO] Nao e possivel removver de heap vazio\n");
        return;
    }

    //Exibir criterio
    //Extrair chave escolhida no criterio
    if (heap->criterioChave == 'c'){
        //Casos totais (confirmados)
        printf("\n[CRITERIO: %s] MOSTRANDO INFORMACOES REMOVIDAS DO HEAP\n", "confirmados");
    }
    else if (heap->criterioChave == 'm'){
        //Casos de morte
        printf("\n[CRITERIO: %s] MOSTRANDO INFORMACOES REMOVIDAS DO HEAP\n", "mortos");
    }
    else if(heap->criterioChave == 'r'){
        //Casos de recuperacao
        printf("\n[CRITERIO: %s] MOSTRANDO INFORMACOES REMOVIDAS DO HEAP\n", "recuperados");
    }
    

    //Verificando se existem menos elementos no heap do que o solicitado para remocao
    if(heap->cont < quant){
        printf("[AVISO] Voce quer remover %d elementos, mas existem %d cadastrados no heap!\n", quant, heap->cont);
        printf("[AVISO] Removendo APENAS %d elementos do heap\n", heap->cont);
    }
    else{
        printf("[AVISO] Removendo %d elementos do heap\n", quant);
    }
    
    //Removendo e exibindo apenas ATE o maximo de elementos cadastrados no heap
    printf("|Pais/Regiao                     |Confirmados|Mortes|Recuperados|Mortes/100|Recuperados/100|\n");
    printf("|--------------------------------|-----------|------|-----------|----------|---------------|\n");
    while(quant != 0 && heap->cont > 0){
        //Remover elemento da raiz
        tipo_dado_heap tempRm = heap_removeRaiz(heap);

        //Exibir elemento removido
        printf("|%-32s|%-11d|%6d|%11d|%10.2f|%15.2f|\n", 
            tempRm.pais,
            tempRm.confirmados, 
            tempRm.mortes, 
            tempRm.recuperados,
            tempRm.mortes100,
            tempRm.recuperados100
        );

        //Decrementar contador da quantidade de elementos solicitados para remocao
        quant --;
    }
}

