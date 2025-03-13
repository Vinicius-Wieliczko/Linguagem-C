//Luis Roberto Molotto e Vinicius Eduardo Wieliczko

#include <stdio.h>
#include <stdlib.h>

struct no {
	int valor;
	struct no *prox;
};

struct no *pilha = NULL;

int vazia(){
	if(pilha == NULL){
		return 1;
	}
	return 0;
}

void push(int valor){
	struct no *aux;
	aux = (struct no*)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->prox = pilha;
	pilha = aux;
}

int pop(){
	if(vazia() == 1){
		printf("\nPilha vazia!\n");
		return -1;
	}
	int num;
	struct no *aux;
	aux = pilha;
	num = aux->valor;
	pilha = aux->prox;
	free(aux);
	return num;

}

void topoPilha(){
	if(vazia() == 1){
		printf("\nPilha vazia!\n");
		return;
	}
	printf("\nTopo da pilha: %d\n", pilha->valor);
}

void imprime(){
	struct no *aux;
	printf("\nPilha:\n");
	for(aux=pilha;aux!=NULL;aux=aux->prox){
		printf("[%d]\n", aux->valor);
	}
	printf("\n");

}

int main(){
	push(10);
	push(15);
	imprime();
	push(20);
	push(30);
	pop();
	pop();
	topoPilha();
	imprime();
	return 0;
}
