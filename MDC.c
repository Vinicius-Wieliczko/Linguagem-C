#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int x, y, z;
    printf("Insira o numerador: \n");
    scanf("%d", &x);
    printf("Insira o denominador: \n");
    scanf("%d", &y);

    z = x % y;
    while(z != 1){
        z = x % y;
        printf("%d/%d tem resto %d: ", x, y, z);
        printf("\n\n92");
        x = y;
        y = z;
    }
    printf("O MDC é: %d", y);



return 0;
}
