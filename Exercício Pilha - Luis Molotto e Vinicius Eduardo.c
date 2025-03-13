//Alunos: Luis Roberto Molotto e Vinicius Eduardo Wieliczko

#include <stdio.h>
#define TAM 5
#include <locale.h>

char expr[100];
int pilha[TAM], topo = -1;

//INICIO 1
//verifica se a pilha está cheia e insere valores ao topo
void push(int valor)
{
    if(topo == TAM)
    {
        printf("Não há espaco suficiente");
        return;
    }
    topo ++;
    pilha[topo] = valor;
}


//verifica se a pilha está vazia
int vazia()
{
    if(topo == -1)
    {
        return 1;
    }
    else return 0;
}


//verifica se a pilha ja esta vazia, se não estiver, tira o elemento do topo
int pop()
{
    int valor;

    if(vazia() == 1)
    {
        printf("Pilha vazia\n\n");
    }
    else valor = pilha [topo];
    topo--;
    return valor;
}


//imprime o elemento do topo da pilha se houver
void topoPilha()
{
    if(vazia() == 1)
    {
        printf("Não tem topo, pois a pilha está vazia\n");
    }
    else printf("O elemento do topo é: %d\n", pilha[topo]);
}


//imprime todos os elementos da pilha
void imprime()
{
    int i;
    if(vazia() == 1)
    {
        printf("Pilha vazia\n\n");
        return;
    }
    for(i=topo; i>=0; i--)
    {
        printf("\n|%d|", pilha[i]);
    }
    printf ("\n");
} //FIM 1

//função para zerar a pilha para nao gerar conflitos entre os exercícios
void zeraPilha()
{
    while(topo != -1)
        pop();
}

//INICIO 2
//verifica os parenteses, se estiver com a mesma quantidade de parenteses abertos e fechados imprime Expressão correta, senão imprime Expressão incorreta
void verificarParentesesN2()
{
    int i;
    for(i=0; expr[i]!='\0'; i++)
    {
        if (expr[i] =='(')
        {
            push(1);
        }
        if(vazia() == 0)
        {
            if (expr[i] ==')')
            {
                pop();
            }
        }
        else
        {
            push (1);
        }
    }
    if (vazia())
    {
        printf("\nExpressão correta!");
    }
    else printf("\nExpressão incorreta, reveja os parênteses!\n");
    zeraPilha();
}//FIM 2


//INICIO EXTRA 3
//verifica as chaves, se estiver com a mesma quantidade de chaves abertas e fechadas, chama a função para verificar os colchetes, senão imprime Expressão incorreta
void verificarChaves()
{
    int i;
    for(i=0; expr[i]!='\0'; i++)
    {
        if (expr[i] =='{' || expr[i] =='}')
        {
            if (expr[i] =='{')
            {
                push(1);
            }
            if (!vazia() && expr[i] =='}')
            {
                pop();
            }
            else if (vazia() && expr[i] == '}')
            {
                push(1);
                break;
            }
        }
    }
    if (!vazia())
    {
        printf("\nExpressão incorreta, reveja as chaves!\n");
        zeraPilha();
    }
    else verificarColchetes();

}


//verifica os colchetes, se estiver com a mesma quantidade de colchetes abertos e fechados, chama a função para verificar os parenteses,  senão imprime Expressão incorreta
void verificarColchetes()
{

    int i;
    for(i=0; expr[i]!='\0'; i++)
    {
        if (expr[i] =='[' || expr[i] ==']')
        {
            if (expr[i] =='[')
            {
                push(1);
            }
            if (!vazia() && expr[i] ==']')
            {
                pop();
            }
            else if (vazia() && expr[i] == ']')
            {
                push(1);
                break;
            }
        }
    }
    if (!vazia())
    {
        printf("\nExpressão incorreta, reveja os colchetes!\n");
        zeraPilha();
    }
    else verificarParenteses();

}

void verificarParenteses()
{
    int i;
    for(i=0; expr[i]!='\0'; i++)
    {
        if (expr[i] =='(')
        {
            push(1);
        }
        if (!vazia() && expr[i] ==')')
        {
            pop();
        }
        else if (vazia() && expr[i] == ')')
        {
            push(1);
            break;
        }
    }
    if (vazia())
    {
        if (verificarOrdem())
        {
            printf("\nExpressão correta!");
            return;
        }
        else
        {
            printf("\nReveja a ordem!");
            return;
        }
    }
    else
    {
        printf("\nExpressão incorreta, reveja os parênteses!\n");
        zeraPilha();
    }
}

int verificarOrdem()
{
    int i;
    char aux1, aux2;

    for(i=0; i!='\0'; i++)
    {
        if(expr[i] == '{')
        {
            aux1 = 1;
        }
        if (expr[i] == '}')
        {
            aux1 = 0;
        }

            while(aux1 == 1)
            {
                if(expr[i] == '[')
                {
                    aux2 = 1;
                }
                if (expr[i] == ']')
                {
                    aux1 = 0;
                }
                    while(expr[i] == 1)
                    {
                        if (expr[i] =='(')
                        {
                            push(1);
                        }
                        if(expr[i] == ')')
                        {
                            pop();
                        }
                    }
            }
    }

    if(vazia())
        return 1;
    else return 0;

}


//FIM EXTRA 3

int main()
{
    setlocale (LC_ALL, "portuguese");

//TESTE 1

    printf ("Teste do exercício 1:\n\n");
    push(40);
    push(60);
    pop();
    pop();
    topoPilha();
    imprime();

    push(90);
    push(80);
    push(70);

    topoPilha();
    imprime();
//FIM TESTE 1
    printf ("________________________________________________________________");
    zeraPilha();


//TESTE 2
    /*printf ("\n\nTeste do exercício 2:\n");

    printf ("\nDigite a expressão:");
    scanf("%s", expr);
    verificarParentesesN2();

    printf ("\nDigite a expressão:");
    scanf("%s", expr);
    verificarParentesesN2();*/
//FIM TESTE 2

    printf ("\n________________________________________________________________");

    zeraPilha();

//TESTE 3
    printf ("\n\nTeste do exercício 3:\n");


    printf ("\nDigite a expressão:");
    scanf("%s", expr);
    //printf ("%s", expr);
    verificarChaves();


   printf ("\nDigite a expressão:");
    scanf("%s", expr);
    //printf ("%s", expr);
    verificarChaves();


   printf ("\nDigite a expressão:");
    scanf("%s", expr);
    //printf ("%s", expr);
    verificarChaves();


    printf ("\nDigite a expressão:");
    scanf("%s", expr);
    //printf ("%s", expr);
    verificarChaves();


    printf ("\nDigite a expressão:");
    scanf("%s", expr);
    //printf ("%s", expr);
    verificarChaves();


    printf ("\nDigite a expressão:");
    scanf("%s", expr);
    //printf ("%s", expr);
    verificarChaves();


    printf ("\nDigite a expressão:");
    scanf("%s", expr);
    //printf ("%s", expr);
    verificarChaves();

//FIM TESTE 3

    return 0;
}
