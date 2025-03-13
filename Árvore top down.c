#include <stdio.h>
#include <stdlib.h>

#define ORDEM 200 // Número máximo de filhos
#define MAX_CHAVES ORDEM-1 // Número máximo de chaves
#define TOTAL 10000


struct no {
    int dado[ORDEM-1];
    struct no *filhos[ORDEM];
    struct no *pai;
    int n_chaves;
};

struct no *raiz=NULL;

int encontra_chave(struct no *atual, int chave) {
    int i=0;
    while (i<atual->n_chaves && chave>atual->dado[i])
        i++;
    return i;
}

struct no *cria_no(int chave){
    struct no *novo;
    novo = (struct no*)malloc (sizeof(struct no));
    int i;
    novo->dado[0]= chave;
    for(i = 1; i < ORDEM; i++){
        novo->filhos[i] = NULL;
    }
    novo->n_chaves = 1;
    return novo;

}


struct no *encontra_no(int chave, int *posicao) {
    struct no *atual, *anterior;
        anterior=NULL;
        atual=raiz;
    while (atual!=NULL) {
        *posicao=encontra_chave(atual,chave);
        anterior = atual;
        atual = atual->filhos[*posicao];
    }
    return anterior;
}

void insere_folha(struct no *atual, int chave) {
    int i;
    for (i=atual->n_chaves ; i>0 && chave<atual->dado[i-1] ; i--)
        atual->dado[i]=atual->dado[i-1];
        atual->dado[i] = chave;
        atual->n_chaves++;
}


int insere(int chave) {
    struct no *novo,*atual;
    int posicao;
    if (raiz==NULL) {
        raiz=cria_no(chave);
    return 1;
    }
    // Encontra no folha onde a nova chave será inserida
    atual = encontra_no(chave,&posicao);

    // Existe espaco no no folha, insere nova chave
    if (atual->n_chaves < MAX_CHAVES) {
        insere_folha(atual,chave);
    return 1;
    }
    // Nao existe espaco no no folha, cria novo no
    novo=cria_no(chave);
    atual->filhos[posicao]=novo;
    return 1;
}


int conta(struct no *atual) {
    int i, total;
    if (atual!=NULL) {
        total=1;
    for (i=0; i<atual->n_chaves+1; i++) {
        total = total + conta(atual->filhos[i]);
    }
    return total;
    }
    return 0;
}


int busca(int chave){
    struct no *atual;
    if(raiz == NULL){
        printf("\nArvore vazia!\n");
        return 0;
    }
    atual = raiz;
    while(atual != NULL){
        int i = encontra_chave(atual, chave);
        if(atual->dado[i] == chave){
            printf("\nValor encontrado!\n");
            return 0;
        }
        atual = atual->filhos[i];
    }
    printf("\nValor nao encontrado!\n");
}


int main(){
    insere(31);
    insere(34);
    insere(21);
    insere(57);
    insere(37);
    insere(33);
    insere(9);

    busca(9);
    busca(30);
    conta(raiz);
}
