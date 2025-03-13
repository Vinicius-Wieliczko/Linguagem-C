#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct {
    int vetor[TAM];
    int n;
} heap;
    heap heap1;

void insereheap(int valor){
    if(heap1.n == TAM){
        printf("heap cheia!");
        return -1;
    }
    heap1.n++;
    heap1.vetor[heap1.n] = valor;
    subir(heap1.n);
}


void subir(int i){
    int j;
    int aux;
    j = i/2;
    if(j >= 1){
        if(heap1.vetor[i] > heap1.vetor[j]){
            aux = heap1.vetor[i];
            heap1.vetor[i] = heap1.vetor[j];
            heap1.vetor[j] = aux;
            subir(j);
        }
    }
}

void maiorheap(){
    printf("O maior valor é: %d!\n", heap1.vetor[1]);
}

void removeheap(){
    int j;
    int aux;
    if(heap1.n == 0){
        printf("heap vazia!");
        return -1;
    }
    aux = heap1.vetor[1];
    heap1.vetor[1] = heap1.vetor[heap1.n];
    heap1.vetor[heap1.n] = aux;
    heap1.n--;
    descer(1);
}

void descer(int i){
    int j;
    int aux;
    j = 2*i;
    if (j <= heap1.n){
        if (j < heap1.n){
            if (heap1.vetor [j+1] > heap1.vetor [j]){
            j ++;
            }

            if (heap1.vetor[i] < heap1.vetor[j]){
            aux = heap1.vetor[i];
            heap1.vetor [i] = heap1.vetor[j];
            heap1.vetor [j] = aux;
            descer(j);
            }
        }
    }
}

void imprimir(){
    for (int i = 1; i <= heap1.n; i++){
        printf("%d\t", heap1.vetor[i]);
    }
}

int main(){
    insereheap(25);
    insereheap(57);
    insereheap(48);
    insereheap(37);
    insereheap(12);
    insereheap(92);
    insereheap(86);
    insereheap(33);

    imprimir();

    removeheap();

    imprimir();




return 0;
}

