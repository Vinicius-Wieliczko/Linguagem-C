#include <stdio.h>
#include <time.h>
#include <locale.h>
#define N 1999999

int V[N];


void geraVet(){
    int i;
    srand(10);
    for(i = 0; i<N; i++){
        V[i] = rand() % (N*10);
    }
}


void troca(int V[], int i, int j){
    int aux = V[i];
    V[i] = V[j];
    V[j] = aux;
}


int divide(int V[], int esq, int dir){
    int pivo, i, j;

    pivo = V[(esq + dir)/2];

    i = esq-1;
    j = dir +1;

    while (i<j){
        do{
            j -= 1;
        }while (V[j]> pivo);
        do {
            i += 1;
        }while (V[i] < pivo);
        if (i<j){
            troca(V, i, j);
        }
    }
    return j;
}


void quickSort(int V[], int p, int r){
    int q;

    if(p<r){
        q = divide(V, p, r);
        quickSort(V, p, q);
        quickSort(V, q+1, r);
    }
}


void verificaOrdem(){
    for(int i = 0; i < N; i++){
        if(V[i] > V[i+1]){
            printf("O vetor não está ordenado!\n");
            return;
        }
    }
    printf("O vetor está ordenado!\n");
}


int main(){
    setlocale(LC_ALL, "portuguese");

    clock_t temp1, temp2;

    geraVet();
    temp1 = clock();
    quickSort(V, 0, N);
    temp2 = clock() - temp1;
    verificaOrdem();

    printf("%0.2f\n\n", (float) temp2/ CLK_TCK);


return 0;
}

