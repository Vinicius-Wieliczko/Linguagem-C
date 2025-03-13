#include <stdio.h>
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int a, b;
    printf("Digite um número inteiro:");
    scanf("%i", &a);
    b = a%2;
    if (b==0)
        {
         printf("O número %i é par!", a);
        }
    else
        {
         printf("O número %i é ímpar!", a);
        }
    }
