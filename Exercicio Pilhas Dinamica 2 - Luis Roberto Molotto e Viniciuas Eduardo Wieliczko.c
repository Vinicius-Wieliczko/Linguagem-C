//Luis Roberto Molotto e Vinicius Eduardo Wieliczko

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
	char valor;
	struct no *prox;
};

struct no *pilha = NULL;

void push(char valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->prox = pilha;
	pilha = aux;
}

int pop(){
	if(pilha == NULL){
		printf("\nPilha vazia!\n");
		return -1;
	}
	struct no *aux;
	aux = pilha;
	pilha = aux->prox;
	free(aux);
	return 0;
}

void imprime(){
	struct no *aux;;
	for(aux=pilha;aux!=NULL;aux=aux->prox){
		printf("[%c]\n", aux->valor);
	}
	printf("\n");

}

void zeraPilha(){
    while(pilha != NULL)
        pop();
}


int main(){
	char *p = (char *) calloc(20, sizeof(char));
	printf("Digite uma palavra: ");
	scanf("%s", p);

	printf ("Palavra invertida:\n");
	for(int i=0;i<strlen(p);i++){
		push(p[i]);
	}

	imprime();
	zeraPilha();

    printf ("\n\nPalavra certa:\n");
	for(int i=strlen(p);i>0;i--){
		push(p[i-1]);
	}

	imprime();

	return 0;
}
