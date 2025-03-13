//Luis Roberto Molotto e Vinicius Eduardo Wieliczko

#include <stdio.h>
#include <locale.h>
#define TAM 10

int fim = 0;
int lista[TAM];

void insereLista(int valor){
    int i;
    if(fim == TAM){
        printf("\nLista cheia!\n");
    }

    for(i = fim; i>0 && valor < lista[i-1]; i--){
           lista[i] = lista[i-1];
    }
    lista[i] = valor;
    fim++;
}

void recuperaLista(int posicao){
    if (fim == 0)
        printf("\nLista vazia!\n");

    if (posicao < fim){
    printf("\nO nъmero da posiзгo %d й: %d\n", posicao, lista[posicao]);
    }
    else printf("\nNгo existe nenhum nъmero na posiзгo %d\n", posicao);
}

void removeLista(int posicao){
    posicao-=1;
    if (fim == 0){
        printf("\nLista vazia!\n");
        return;
    }
    for(int i = posicao; i < fim; i++){
        lista[i] = lista[i+1];
    }
    fim--;
}

void removeValor(int valor){
    if (fim == 0){
        printf("\nLista vazia!\n");
        return;
    }
    for(int i = 0; i < fim && valor >= lista[i]; i++){
        if(lista[i] == valor){
            for(int j = i; j < fim-1; j++){
                lista [j] = lista[j+1];
            }
        fim--;
        return;
        }
    }
    printf("\nNъmero nгo encontrado!\n");
}

void imprime(){
    if(fim == 0){
        printf("\nLista vazia!\n");
    }
    else for(int i = 0; i < fim; i++){
        printf ("%d\t", lista[i]);
    }
    printf("\n\n");
}

int main(){
    setlocale(LC_ALL, "portuguese");
    removeValor(2);
    removeLista(5);

    insereLista(5);
    insereLista(4);
    insereLista(3);
    insereLista(1);
    insereLista(2);
    imprime();

    removeValor(2);
    imprime();

    removeLista(3);
    imprime();


return 0;
}
