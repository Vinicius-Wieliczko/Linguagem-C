#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int valor;
    struct no *prox;
} no;

no *inicio = NULL;


void insereLista(int valor){
    no *aux;
    aux = (no*)malloc(sizeof(no));
    aux->valor = valor;

    no *atual = inicio;
    no *anterior = NULL;

    while(atual != NULL && atual->valor < valor){
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL){
        aux->prox = inicio;
        inicio = aux;
    } else{
        aux->prox = anterior->prox;
        anterior->prox = aux;
    }
    printf("Elemento inserido!\n");
}


void recuperaLista(int posicao){
    no *aux = inicio;

    if(inicio == NULL){
        printf("Lista vazia!\n");
    }

    for(int i = 1; i<posicao; i++){
        if(aux != NULL)
            aux = aux->prox;
            else break;
    }
    if(aux == NULL){
        printf("Não exite essa posição na lista!\n");
    }else
    printf("O elemento %d é: %d\n", posicao, aux->valor);
}


void removeLista(int posicao){
    no *aux = inicio;
    for(int i = 1; i < posicao){

    }

}


void imprime(){
	if(inicio==NULL){
		printf("\nFila vazia!\n");
		return;
	}
	struct no *aux;
	printf("\nLista: ");
	for(aux=inicio;aux!=NULL;aux=aux->prox){
		printf("%d ", aux->valor);
	}
	printf("\n");
}


int main(){
    setlocale(LC_ALL, "portuguese");

    insereLista(4);
    insereLista(6);
    insereLista(5);

    imprime();


    recuperaLista(4);
    recuperaLista(1);
    recuperaLista(3);
    recuperaLista(5);
return 0;
}
