#include <stdio.h>
#include <locale.h>
main(){
    setlocale (LC_ALL, "portuguese");
    int a,b,c;
    printf ("Digite um número inteiro:");
    scanf("%i", &a);
    b=0;
    for (c=1;c<=a;c++){
        if (a%c==0)
            b=b+1;
        }
        if (b==2)
                printf ("\nO número %i é primo!",a);
            else
                printf("\nO número %i não é primo",a);
}
