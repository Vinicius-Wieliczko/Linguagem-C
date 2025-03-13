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
        aux->prox = atual;
        anterior->prox = aux;
    }
    printf("Elemento inserido!\n");
}

void recuperaLista(int valor){
    struct no *aux = inicio;

    if(aux == NULL){
        printf ("\nLista vazia!\n");
        return;
    }
    int cont = 0, contnum = 0;
    for(aux; aux != NULL; aux = aux->prox){
        cont++;
        if(aux->valor == valor){
            if(contnum == 1){
                printf(", %d° posição", cont);
            }else{
                contnum = 1;
                printf("\nO valor %d aparece na: ", valor);
                printf("%d° posição", cont);
            }
        }
    }
    if (contnum == 0){
        printf("\nValor %d não encontrado na lista!\n", valor);
    }
}


void removeLista(int posicao){
    no *aux = inicio;
    no *anterior;

    if(aux == NULL){
        printf ("\nLista vazia!\n");
        return;
    }
    if (posicao == 1){
        inicio = inicio->prox;
        free(aux);
        return;
    }
    for(int cont = 1; cont < posicao; cont++){
        anterior = aux;
        aux = aux->prox;
        if(aux == NULL){
            printf("\nPosição inválida!");
            return;
        }
    }
        anterior->prox = aux->prox;
        free(aux);
}


void removeValor(int valor){
    no *aux = inicio->prox;
    no *anterior = inicio;

    for(aux; aux != NULL; aux = aux->prox){
        if(inicio->valor == valor){
            inicio = anterior->prox;
            free(anterior);
            anterior = inicio;
        }else if (aux->valor == valor){
            anterior->prox = aux->prox;
            free(aux);
        }else anterior = anterior->prox;
    }
}


void imprime(){
	if(inicio==NULL){
		printf("\nLista vazia!\n");
		return;
	}
	struct no *aux;
	printf("\nLista: [");
	for(aux=inicio;aux!=NULL;aux=aux->prox){
        if (aux->prox == NULL){
            printf("%d]\n", aux->valor);
        }else
            printf("%d-", aux->valor);
	}

}


int main(){
    setlocale(LC_ALL, "portuguese");

    insereLista(4);
    insereLista(4);
    insereLista(4);
    insereLista(6);
    insereLista(5);
    insereLista(5);
    insereLista(5);
    insereLista(4);
    insereLista(7);


    imprime();
    printf("___________________________________________");


    recuperaLista(5);
    recuperaLista(4);
    recuperaLista(1);

    printf("___________________________________________");
    removeLista(7);


    imprime();

    printf("___________________________________________");
    removeLista(1);


    imprime();
    printf("___________________________________________");

    removeValor(5);


    imprime();
    printf("___________________________________________");

    removeValor(4);


    imprime();
    printf("___________________________________________");



return 0;

}
