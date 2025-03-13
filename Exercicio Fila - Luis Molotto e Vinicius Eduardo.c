//Luis Roberto Molotto e Vinicius Eduardo Wieliczko

#include <stdio.h>
#define TAM 3

int fila[TAM], inicio = 0, fim = 0, aux = 0;


//insere elementos na fila, se, ao inserir, ja estiver cheia, imprime Fila cheia
void insereFila(int valor){
    if(aux < TAM){
        fila[fim] = valor;
        aux++;
        fim++;
        if(fim == TAM)
            fim = 0;
    }
    else printf("\nFila cheia!");

}

//remove o valor do inicio da fila, caso o ultimo elemento ja tenha sido removido, imprime Fila vazia
void removeFila(){
    int valor;
    if (aux != 0){
        valor = fila[inicio];
        aux--;
        inicio++;
        if(inicio == TAM)
            inicio = 0;
    }
    else
        printf("Fila vazia!");
    return valor;
}

//imprime o elemento do inicio da fila
void inicioFila(){
    printf("\n%d", fila[inicio]);
}

//imprime a fila inteira, primeiro verificando se está vazia e depois imprime todos os valores até que a quantidade seja igual a 0
void imprime(){
    int x, y;
        x = inicio;
        y = 0;
        if(aux == 0){
            printf("\nFila vazia!");
            return;
        }
        while(y != aux){
            printf("\n%d", fila[x]);
            x++;
            y++;
            if(x == TAM){
                x=0;
            }
        }
}

int main(){
    removeFila();
    printf("\n-----------------");
    insereFila(10);
    insereFila(8);
    imprime();
    printf("\n-----------------");
    insereFila(12);
    insereFila(14);
    printf("\n-----------------");
    imprime();
    printf("\n-----------------");
    removeFila();
    imprime();
    printf("\n-----------------");
    insereFila(14);
    imprime();
    printf("\n-----------------");
    inicioFila();
    printf("\n-----------------");
    insereFila(16);


return 0;
}
