#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *prox;
	struct no *ant;
};

struct no *fim = NULL;
struct no *inicio = NULL;

void insere(int valor, int lado){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;

	if(lado == 0){ //lado 0 = esquerdo
		if(inicio==NULL){
            aux->prox = NULL;
            aux->ant = NULL;
			inicio=aux;
			fim=aux;
			printf("\nElemento inserido pela esquerda!\n");
			return;
		}
        aux->ant = NULL;
        inicio->ant = aux;
        aux->prox = inicio;
        inicio = aux;
		printf("\nElemento inserido pela esquerda!\n");
		return;
	}
	if(lado == 1){ //lado 1 = direito
		if(fim==NULL){
                aux->prox = NULL;
            aux->ant = NULL;
			fim=aux;
			inicio=aux;
			printf("\nElemento inserido pela direita!\n");
			return;
		}
		aux->prox = NULL;
		fim->prox = aux;
		aux->ant = fim;
		fim = aux;
		printf("\nElemento inserido pela direita!\n");
		return;
	}
	else printf("Lado inválido!");
	return;

}


void removeValor(int valor){
    struct no *aux = inicio;
    struct no *anterior;
    struct no *posterior;
    int cont = 0;

    if(inicio==NULL){
        printf("\nLista vazia!\n");
        return;
    }
    for(aux; aux != NULL; aux = aux->prox){
        if(aux->valor == valor){
                printf("2");
            if(aux == inicio){
                inicio = inicio->prox;
                inicio->ant = NULL;
                free(aux);
                aux = inicio;
            }else if(aux == fim){
                fim = fim->ant;
                fim->prox = NULL;
                free(aux);
            }else{
                anterior = aux->ant;
                posterior = aux->prox;
                anterior->prox = posterior;
                posterior->ant = anterior;
                free(aux);
                aux=anterior;
            }
        }
    }
}


void imprime(int lado){
    if(lado == 0){
        if(inicio==NULL){
            printf("\nFila vazia!\n");
            return;
        }
        struct no *aux;
        printf("\nFila: ");
        for(aux=inicio;aux!=NULL;aux=aux->prox){
            printf("%d ", aux->valor);
        }
        printf("\n");
    }
    if(lado == 1){
        if(fim == NULL){
            printf("\nFila vazia!\n");
            return;
        }
        struct no *aux;
        printf("\nFila: ");
        for(aux=fim;aux!=NULL;aux=aux->ant){
            printf("%d ", aux->valor);
        }
        printf("\n");
    }
}


int main(){
	insere(4,1);
	insere(6,0);
	insere(8,1);
	insere(10,0);
	insere(3,1);
	insere(3,0);
	insere(3,1);
	insere(4,0);
	insere(69,1);


	imprime(0);
	imprime(1);
    printf("===================================================================");

	removeValor(3);
	imprime(0);
	imprime(1);
    printf("===================================================================");

	removeValor(4);
	imprime(0);
	imprime(1);
    printf("===================================================================");

return 0;
}
