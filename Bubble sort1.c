#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define N 19999

int A[N];

void geraVet(){
    int i;
    srand(10);
    for(i = 0; i<N; i++){
        A[i] = rand() % (N*10);
    }
}


void bubbleSort(){
    for(int i = 1; i<= N+1; i++){
        for(int j = 0; j <= N; j++){
            if (A[j] > A[j+1]){
                int aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}


void bubbleSort2(){
    for(int i = 1; i<= N-1; i++){
        for(int j = N-1; j >= i; j--){
            if (A[j] > A[j-1]){
                int aux = A[j];
                A[j] = A[j-1];
                A[j+1] = aux;
            }
        }
    }
}


void bubbleSort3(){
    int i = 1;
    int troca = 1;


    while(i <= N && troca == 1){
        troca = 0;

        for(int j = 0; j <= N-i; j++){
            if (A[j] > A[j+1]){
                int aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
                troca = 1;
            }
        }
        i += 1;
    }
}


void verificaOrdem(){
    for(int i = 0; i < N; i++){
        if(A[i] > A[i+1]){
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
    bubbleSort();
    temp2 = clock() - temp1;
    verificaOrdem();

    printf("%0.2f\n\n", (float) temp2/ CLK_TCK);


    geraVet();
    temp1 = clock();
    bubbleSort2();
    temp2 = clock() - temp1;
    verificaOrdem();

    printf("%0.2f\n\n", (float) temp2/ CLK_TCK);

    geraVet();
    temp1 = clock();
    printf("\n");
    bubbleSort3();
    temp2 = clock() - temp1;
    verificaOrdem();

    printf("%0.2f\n\n", (float) temp2/ CLK_TCK);


return 0;
}
