#include <stdio.h>
#include <locale.h>
main(){
    setlocale(LC_ALL, "Portuguese");
    int a, b;
    printf("Digite um n�mero inteiro:");
    scanf("%i", &a);
    b = a%2;
    if (b==0)
        {
         printf("O n�mero %i � par!", a);
        }
    else
        {
         printf("O n�mero %i � �mpar!", a);
        }
    }
