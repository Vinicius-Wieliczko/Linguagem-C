#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 20000
#define M 1000

int A[N];
int B[M];

void geraVet(){
    int i;
    srand(10);
    for(i = 0; i<N; i++){
        A[i] = rand() % (M*10);
    }
}


void geraVetBusca(){
    int i;
    srand(10);
    for(i = 0; i < M; i++){
        B[i] = rand() % (N*10);
    }
}

void busca(){
    int cont = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(A[j] == B[i]){
                cont++;
            }
        }
    }
    if(cont == 0){
        printf("Nenhum dos valores encontrado na lista!\n");
    }else {
        printf("O valores do vetor foram encontrado %d vezes", cont);
    }
}


int main(){
    setlocale(LC_ALL, "portuguese");


    geraVet();
    geraVetBusca();
    busca();


return 0;
}
