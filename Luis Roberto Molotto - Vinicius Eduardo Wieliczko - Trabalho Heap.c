#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 1000

typedef struct {
    int vetor[TAM];
    int n;
} heap;
heap heap1;

void subir(int i){
    int j, aux;
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

void insereHeap(int valor){
    if(heap1.n == TAM){
        printf("heap cheia!\n");
        return;
    }
    heap1.n++;
    heap1.vetor[heap1.n] = valor;
    subir(heap1.n);
}



void maiorHeap(){
    if(heap1.n == 0){
        printf("Heap vazia!\n");
        return;
    }
    printf("%d\n", heap1.vetor[1]);
}

void descer(int i){
    int j, aux;
    j = 2*i;
    if (j <= heap1.n){
        if (j < heap1.n && heap1.vetor[j + 1] > heap1.vetor[j]){
            j++;
        }
        if (heap1.vetor[i] < heap1.vetor[j]){
            aux = heap1.vetor[i];
            heap1.vetor[i] = heap1.vetor[j];
            heap1.vetor[j] = aux;
            descer(j);
        }
    }
}

void removeHeap(){
    if(heap1.n == 0){
        printf("Heap vazia!\n");
        return;
    }
    int aux = heap1.vetor[1];
    heap1.vetor[1] = heap1.vetor[heap1.n];
    heap1.vetor[heap1.n] = aux;
    heap1.n--;
    descer(1);
}

void imprimir(){
    for (int i = 1; i <= heap1.n; i++){
        printf("%d\t", heap1.vetor[i]);
    }
    printf("\n");
}

void le_e_insere(const char* numeros){
    FILE *file = fopen(numeros, "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo %s\n", numeros);
        return;
    }

    int num;
    while(fscanf(file, "%d", &num) != EOF){
        insereHeap(num);
    }
    fclose(file);
}

void maiorArquivo(){
    printf("Os três maiores números são: %d, %d e %d\n", heap1.vetor[1], heap1.vetor[2], heap1.vetor[3]);
}

int main(){
    setlocale(LC_ALL,"portuguese");
    le_e_insere("numeros.txt");

    maiorArquivo();
    imprimir();

    return 0;
}
