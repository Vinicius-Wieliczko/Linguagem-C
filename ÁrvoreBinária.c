#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


typedef struct no{
    struct no *esq;
    struct no *dir;
    int valor;
}no;


no *raiz = NULL;


void vazia(){
    if (raiz == NULL){
        printf("A árvore está vazia!\n");
    }else
        printf("A árvore não está vazia!\n");
    return;
}


void insere(int valor){
    no *aux;
    no *percorre = raiz;
    no *anterior;

    aux = (no*) malloc (sizeof(no));

    aux->valor = valor;

    if (raiz == NULL){
        raiz = aux;
        return;
    }
    while(percorre != NULL){
        anterior = percorre;
        if(aux->valor == percorre->valor){
            printf("Valor já inserido, favor inserir outro!\n");
            return;
        }
        if(aux->valor < percorre->valor){
            percorre = percorre->esq;
        } else{
            percorre = percorre->dir;
        }
    }
    if(aux->valor < anterior->valor){
        anterior->esq = aux;
    } else{
        anterior->dir = aux;
    }

}


void busca(int valor){
    no *percorre = raiz;

    while(percorre != NULL){

        if(valor == percorre->valor){
            printf("Valor %d encontrado!\n", valor);
            return;
        }

        if (valor < percorre->valor){
            percorre = percorre->esq;
        } else {
            percorre = percorre->dir;
        }
    }
    printf("Valor %d não encontrado!\n", valor);
}


void imprimeOrdem(struct no *aux) {
    if(aux){
			imprimeOrdem(aux->esq);
			printf("%d ", aux->valor);
			imprimeOrdem(aux->dir);
  }
}



int main(){
    setlocale(LC_ALL, "portuguese");

    vazia();

    printf("\n________________________________________________________________________________\n");

    insere(6);
    insere(1);
    insere(3);
    insere(4);
    insere(4);
    insere(5);
    insere(9);
    insere(8);

    vazia();
    printf("\n________________________________________________________________________________\n");

    busca(10);
    busca(4);

    printf("\n________________________________________________________________________________\n");

    imprimeOrdem(raiz);

    printf("\n________________________________________________________________________________\n");


return 0;
}
