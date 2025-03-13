#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 10

int vet[N];
int matriz[N][N], fim = 0;


void inicializaMatriz(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matriz[i][j] = 0;
        }
    }
}


void insereVertice(int valor){
    int cont = 0;
    if (fim > N){
        printf("\nO vetor esta cheio!\n");
        return;
    }
    while (cont < fim){
        if(valor == vet[cont]){
            printf("\nVertice ja inserido!\n");
            return;
        }
        cont++;
    }
    vet[fim] = valor;
    fim++;
}


void insereAresta(int origem, int destino){
    int cont = 0;
    int orig = -1, dest = -1;
    while (cont < fim){
        if(origem == vet[cont]){
            orig = cont;
        }
        if(vet[cont] == destino){
            dest = cont;
        }
        cont++;
    }
    if (orig != -1 && dest != -1){
        matriz[orig][dest] = 1;
    }
}


void removeAresta(int origem, int destino){
    int cont = 0;
    int orig = -1, dest = -1;
    while (cont < fim){
        if(origem == vet[cont]){
            orig = cont;
        }
        if(destino == vet[cont]){
            dest = cont;
        }
        cont++;
    }
    if (orig != -1 && dest != -1){
        if(haAresta()){
            matriz[orig][dest] = 0;
        }else
            printf("\Aresta inexistente\n");
    }else
        printf("\nVertice inexistente\n");
}

int haAresta(int origem, int destino){
    int cont = 0;
    int orig = -1, dest = -1;
    while (cont < fim){
        if(origem == vet[cont]){
            orig = cont;
        }
        if(destino == vet[cont]){
            dest = cont;
        }
        cont++;
    }
    if (orig != -1 && dest != -1){
        if (matriz[orig][dest] == 0){
            printf("\nAresta <%d, %d> inexistente!\n", vet[orig], vet[dest]);
            return 0;
        }else{
        printf("\nAresta <%d, %d> existente!\n", vet[orig], vet[dest]);
        return 1;
        }
    }else
        printf("\nVertice inexistente\n");
}


void imprimeGrafo(){
    for(int i = 0; i < fim; i++){
            printf("\n%d -> ", vet[i]);
        for(int j = 0; j < fim; j++){
            if (matriz[i][j] == 1){
                printf("<%d, %d>\t", vet[i], vet[j]);
            }
        }
    }
}

int main(){
    inicializaMatriz();

    insereVertice(0);
    insereVertice(1);
    insereVertice(1);
    insereVertice(2);

    insereAresta(0, 1);
    insereAresta(1, 0);
    insereAresta(0, 2);

    haAresta(0,2);
    haAresta(2,0);

    imprimeGrafo();

    removeAresta(0, 2);
    imprimeGrafo();

}
