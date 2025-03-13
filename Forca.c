#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

enum {BLACK,
      BLUE,
      GREEN,
      CYAN,
      RED,
      MAGENTA,
      BROWN,
      LIGHTGRAY,
      DARKGRAY,
      LIGHTBLUE,
      LIGHTGREEN,
      LIGHTCYAN,
      LIGHTRED,
      LIGHTMAGENTA,
      YELLOW,
      WHITE
     };
enum {_BLACK=0,
      _BLUE=16,
      _GREEN=32,
      _CYAN=48,
      _RED=64,
      _MAGENTA=80,
      _BROWN=96,
      _LIGHTGRAY=112,
      _DARKGRAY=128,
      _LIGHTBLUE=144,
      _LIGHTGREEN=160,
      _LIGHTCYAN=176,
      _LIGHTRED=192,
      _LIGHTMAGENTA=208,
      _YELLOW=224,
      _WHITE=240
     };

typedef struct
{
    char word[20];
} receber;
receber shoot[7];
void arquivo()
{
    receber w;
    FILE *arq;
    arq = fopen ("banco.bin", "ab");
    char *p;
    p = (char *) calloc (20, sizeof(char));
    printf ("\nDigite a palavra a ser inserida:\n");
    scanf ("%s", p);
    strupr(p);
    strcpy (w.word, p);
    fwrite (&w.word, sizeof(receber), 1, arq);
    fclose(arq);
    printf("\n");
    system("pause");
    system("cls");
}
void printarq()
{
    FILE *arq;
    receber w;
    arq = fopen ("banco.bin", "rb");
    while (fread (&w, sizeof(receber), 1, arq))
    {
        printf ("%s\t", w.word);
    }
    fclose (arq);
    printf("\n");
    system("pause");
    system("cls");
}
void clearShoot()
{
    int i;
    for(i = 0; i <= 7; i++)
    {
        strcpy(shoot[i].word, "____________________");
    }
}

int wordAgain(char  p[])
{
    int i;

    for(i = 0; i <= 7; i++)
    {
        if(strcmp(p, shoot[i].word)==0)
        {
            return 1;
        }
    }
    return 0;
}
void jogo()
{
    system("cls");
    char selected[20];
    int qtdd = 0, random, i, p, exit=0, acertou=0, life=7, l=0;
    FILE *arq;
    receber w;
    random=0;
    arq = fopen ("banco.bin", "rb");
    while (fread (&w, sizeof(receber), 1, arq))
    {
        qtdd+=1;
    }
    srand(time(NULL));
    random = rand() % qtdd;
    fseek(arq, random*sizeof(receber), SEEK_SET);
    fread (&w.word, sizeof(receber), 1, arq);
    strcpy(selected, w.word);
    fclose(arq);
    p = strlen(selected);
    char hide[p], guess[20], *aux;
    aux = (char *) calloc (p, sizeof(char));
    for(i=0; i<p; i++)
    {
        hide[i]='_';
        linhaCol(21, 15+(i*2));
        printf ("%c", hide[i]);
    }
    clearShoot();
    while (exit!=1 && life>0 && acertou<2)
    {
        linhaCol(1,1);
        printf ("Bem-vindo ao jogo da forca!!\n                                                              \n ");
        acertou=0;
        box();
        desenho(life);
        linhaCol(22, 1);
        printf("\nEscreva uma letra ou de um palpite ou digite 1 para sair\n");
        scanf("%s", guess);
        strupr(guess);
        linhaCol(27,1);
        printf("                                                       ");
        linhaCol(24, 1);//24 pq foi dado \n no 22
        printf("                    ");
        linhaCol(25, 15);
        printf("Voce tem %d vida(s)", life);
        if (wordAgain(guess)==1)
        {
            printf("\a");
            linhaCol(27,1);
            printf("Essa letra/palavra ja foi utilizada\n");
            acertou=1;
        }
        else
        {
            if (strlen(guess)==1)
            {
                if (guess[0] == '1')
                {
                    exit=1;
                    break;
                }
                else
                {
                    for(i=0; i<p; i++)
                    {
                        if (guess[0] == selected[i])
                        {
                            if (aux[i]==selected[i])
                            {
                                printf("\a");
                            }
                            aux[i] = guess[0];
                            acertou=1;
                            linhaCol(21, 15+(i*2));
                            printf(guess);
                            if (strcmp(aux, selected)==0)
                                acertou = 2;
                        }
                    }
                }

            }
            else if (strcmp(guess, selected)==0)
            {
                acertou=2;
                for(i=0; i<p; i++)
                {
                    linhaCol(21, 15+(i*2));
                    printf("%c", guess[i]);
                }
            }
        }
        if(acertou==0)
        {
            textcolor(RED, _BLACK);
            life-=1;
            strcpy(shoot[life].word, guess);
            linhaCol(8+l,7);
            printf("%s", shoot[life].word);
            l+=1;
            textcolor(WHITE, _BLACK);
        }
        printf("\n");
        linhaCol(25, 15);
        printf("Voce tem %d vida(s)", life);
        desenho(life);
    }

    free(aux);
    if(life==0)
    {
        system("cls");
        perdeu();
        system ("pause");
        system("cls");
        again();
    }
    if (acertou==2)
    {
        exit=1;
        system ("cls");
        venceu();
        system ("pause");
        system("cls");
        again();
    }
}
void textcolor(int letras, int fundo)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letras+fundo);
}

void venceu()
{
    textcolor(GREEN, _BLACK);
    printf("PARABENS!!\nVOCE ACERTOU!!\n");
    textcolor(WHITE, _BLACK);
}
void box()
{
    int i;
    for(i=3 ; i<=27 ; i++)
    {
        linhaCol(7, i);
        printf("%c", 196);
        linhaCol(15, i);
        printf("%c", 196);
    }
    for(i=7 ; i<=15 ; i++)
    {
        linhaCol(i, 3);
        printf("%c", 179);
        linhaCol(i, 27);
        printf("%c", 179);
    }
    linhaCol(7, 3);
    printf("%c", 218);
    linhaCol(7, 27);
    printf("%c", 191);
    linhaCol(15, 3);
    printf("%c", 192);
    linhaCol(15, 27);
    printf("%c", 217);
    linhaCol(8, 4);
    printf("1-");
    linhaCol(9, 4);
    printf("2-");
    linhaCol(10, 4);
    printf("3-");
    linhaCol(11, 4);
    printf("4-");
    linhaCol(12, 4);
    printf("5-");
    linhaCol(13, 4);
    printf("6-");
    linhaCol(14, 4);
    printf("7-");

}

int vida(int life)
{
    life-=1;
    return life;
}

void linhaCol(int lin, int col)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        col-1, lin-1
    });
}

int desenho(int life)
{
    int i;
    for(i=84 ; i<=93 ; i++)
    {
        linhaCol(3, i);
        printf("%c", 196);
    }
    for(i=3 ; i<=4 ; i++)
    {
        linhaCol(i, 84);
        printf("%c", 179);
    }
    for(i=3 ; i<=23 ; i++)
    {
        linhaCol(i, 93);
        printf("%c", 179);
    }
    for(i=78 ; i<=93 ; i++)
    {
        linhaCol(23, i);
        printf("%c", 196);
    }
    switch(life)
    {
    case 7:
        break;
    case 6:
        tronco();
        break;
    case 5:
        pernad();
        break;
    case 4:
        pernae();
        break;
    case 3:
        bracod();
        break;
    case 2:
        bracoe();
        break;
    case 1:
        pescoco();
        break;
    case 0:
        cabeca();
        break;

    }
}
void again()
{
    int z = 0;
    printf("Digite 1-Jogar novamente 2-Voltar ao menu:\n");
    scanf("%d", &z);
    switch(z)
    {
    case 1:
        forca();
        break;
    case 2:
        system("cls");
        break;

    }
}
void perdeu()
{
    textcolor(RED, _BLACK);
    system("cls");
    printf("VOCE FOI ENFORCADO!");
    linhaCol(27,1);
    printf("\n");
    textcolor(WHITE, _BLACK);
}
void cabeca()
{
    int i, j, lin1=4, col1=81, lin2=7, col2=87;

    for(i=col1 ; i<=col2 ; i++)
    {
        linhaCol(lin1, i);
        printf("%c", 196);
        if(i<(col1+2) || i>(col2-2))
        {
            linhaCol(lin2, i);
            printf("%c", 196);
        }
    }
    for(i=lin1 ; i<=lin2 ; i++)
    {
        linhaCol(i, col1);
        printf("%c", 179);
        linhaCol(i, col2);
        printf("%c", 179);
    }
    for(i=lin1+1 ; i<lin2 ; i++)
    {
        for(j=col1+1 ; j<col2 ; j++)
        {
            linhaCol(i, j);
            printf(" ");
        }
    }
    linhaCol(27,1);
    printf("\n");
    system("pause");
    system("cls");
}
void pescoco()
{
    linhaCol(8, 85);
    printf("%c", 192);
    linhaCol(8, 83);
    printf("%c", 217);
    linhaCol(7, 85);
    printf("%c", 218);
    linhaCol(7, 83);
    printf("%c", 191);

}
void bracoe()
{
    int i;
    for(i=9 ; i<=13 ; i++)
    {
        linhaCol(i,78);
        printf("%c", 179);
    }
    linhaCol(9,78);
    printf("%c", 218);
    linhaCol(9,79);
    printf("%c", 196);
    linhaCol(9,80);
    printf("%c", 180);
}
void bracod()
{
    int i;
    for(i=9 ; i<=13 ; i++)
    {
        linhaCol(i,90);
        printf("%c", 179);
    }
    linhaCol(9,90);
    printf("%c", 191);
    linhaCol(9,89);
    printf("%c", 196);
    linhaCol(9,88);
    printf("%c", 195);
}
void pernae()
{
    int i;
    for(i=16 ; i<=20 ; i++)
    {
        linhaCol(i,81);
        printf("%c",179);
    }
    linhaCol(16,81);
    printf("%c",194);
}
void pernad()
{
    int i;
    for(i=16 ; i<=20 ; i++)
    {
        linhaCol(i,87);
        printf("%c",179);
    }
    linhaCol(16,87);
    printf("%c",194);
}
void tronco()
{
    int i, j, lin1=8, col1=80, lin2=16, col2=88;

    for(i=col1 ; i<=col2 ; i++)
    {
        if(i<(col1+4) || i>(col2-4))
        {
            linhaCol(lin1, i);
            printf("%c", 196);
        }
        linhaCol(lin2, i);
        printf("%c", 196);
    }
    for(i=lin1 ; i<=lin2 ; i++)
    {
        linhaCol(i, col1);
        printf("%c", 179);
        linhaCol(i, col2);
        printf("%c", 179);
    }
    for(i=lin1+1 ; i<lin2 ; i++)
    {
        for(j=col1+1 ; j<col2 ; j++)
        {
            linhaCol(i, j);
            printf(" ");
        }
    }
}
void forca()
{
    jogo();
    printf("\n");
    system("pause");
    system("cls");

}
int menu()
{
    int n;
    n=0;
    do
    {
        printf("JOGO DA FORCA!");
        printf("\nDigite 1-Jogar 2-Adicionar palavra 3-Vizualizar arquivo 4-Sair\n");
        scanf("%d", &n );
        switch (n)
        {
        case 1:
            forca();
            break;
        case 2:
            arquivo();
            break;
        case 3:
            printarq();
            break;
        }
    }
    while (n!=4);
}
int main()
{
    menu();
    return 0;
}
