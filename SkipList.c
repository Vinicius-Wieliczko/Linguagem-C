#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

struct no
{
    int chave;
    struct no **prox;
    struct no **ant;
};

struct skiplist
{
    int nivelMax;
    float p;
    int nivel;
    struct no *inicio;
};

struct no* novoNo(int chave, int nivel)
{
    struct no* novo = (struct no*)malloc(sizeof(struct no));
    novo->chave = chave;
    novo->prox = (struct no**)malloc((nivel + 1) * sizeof(struct no*));
    novo->ant = (struct no**)malloc((nivel + 1) * sizeof(struct no*));
    int i;
    for (i = 0; i <= nivel; i++)
    {
        novo->prox[i] = NULL;
        novo->ant[i] = NULL;
    }
    return novo;
}

struct skiplist* criaSkip(int nivelMax, float p)
{
    struct skiplist *sk = (struct skiplist*)malloc(sizeof(struct skiplist));
    sk->nivelMax = nivelMax;
    sk->p = p;
    sk->nivel = 0;
    sk->inicio = novoNo(-1, nivelMax);
    return sk;
}


int sorteiaNivel(struct skiplist *sk)
{
    float r = (float)rand() / RAND_MAX;
    int nivel = 0;

    while (r < sk->p && nivel < sk->nivelMax)
    {
        nivel++;
        r = (float)rand() / RAND_MAX;
    }

    return nivel;
}

int insere(struct skiplist *sk, int chave)
{
    if (sk == NULL)
    {
        return 0;
    }
    int i;
    struct no *atual = sk->inicio;
    struct no **aux;

    aux = (struct no**)malloc((sk->nivelMax + 1) * sizeof(struct no*));

    for (i = 0; i <= sk->nivelMax; i++)
    {
        aux[i] = NULL;
    }

    for (i = sk->nivel; i >= 0; i--)
    {
        while (atual->prox[i] != NULL && atual->prox[i]->chave < chave)
        {
            atual = atual->prox[i];
        }
        aux[i] = atual;
    }

    atual = atual->prox[0];

    if (atual == NULL || atual->chave != chave)
    {
        int novo_nivel = sorteiaNivel(sk);
        struct no *novo = novoNo(chave, novo_nivel);

        // Atualizando os níveis se novo_nivel > sk->nivel
        if (novo_nivel > sk->nivel)
        {
            for (i = sk->nivel + 1; i <= novo_nivel; i++)
            {
                aux[i] = sk->inicio;
            }
            sk->nivel = novo_nivel;
        }

        // Inserindo o nó
        for (i = 0; i <= novo_nivel; i++)
        {
            novo->prox[i] = aux[i]->prox[i];
            if(aux[i]->prox[i] != NULL)
            {
                aux[i]->prox[i]->ant[i] = novo;
            }
            aux[i]->prox[i] = novo;
            novo->ant[i] = aux[i];
        }

        free(aux);
        return 1;
    }

    free(aux);
    return 0;
}

void imprime(int posicao, struct skiplist *sk)
{
    if (sk == NULL || sk->inicio->prox[0] == NULL)
    {
        printf("SkipList vazia ou invalida.\n\n");
        return;
    }

    struct no *atual;
    int i;

    if (posicao == 0)
    {
        // Imprime da posição inicial
        for (i = 0; i <= sk->nivel; i++)
        {
            printf("nivel %d: ", i);
            atual = sk->inicio->prox[i];
            while (atual != NULL)
            {
                printf("%d ", atual->chave);
                atual = atual->prox[i];
            }
            printf("\n");
        }
    }
    else if (posicao == 1)
    {
        // Imprime a partir do último nó em cada nivel
        for (i = 0; i <= sk->nivel; i++)
        {
            printf("nivel %d: ", i);
            atual = sk->inicio;
            // Caminha até o último nó neste nivel
            while (atual->prox[i] != NULL)
            {
                atual = atual->prox[i];
            }
            // Agora imprime de trás para frente
            while (atual != sk->inicio)
            {
                printf("%d ", atual->chave);
                atual = atual->ant[i];
            }
            printf("\n");
        }
    }
    else
    {
        printf("Posição invalida. Use 0 para inicio ou 1 para fim.\n");
    }
    printf("\n\n");
}

void busca(struct skiplist *sk,int chave, int posicao)
{
    if(sk == NULL)
    {
        return 0;
    }
    struct no *atual = sk->inicio;
    int i;
    if(posicao == 0)
    {
        for(i=sk->nivel; i>=0; i--)
        {
            while(atual->prox[i]!=NULL && atual->prox[i]->chave <= chave)
            {
                if(atual->prox[i]->chave == chave)
                {
                    printf("Valor %d encontrado pela esquerda\n", chave);
                    return;
                }
                atual = atual->prox[i];
            }
        }
        printf("Valor %d nao encontrado pela esquerda\n", chave);
    }
    else if(posicao == 1)
    {
        for(i=sk->nivel; i>=0; i--)
        {
            while(atual->prox[i] != NULL)
            {
                atual = atual->prox[i];
            }
            while(atual!= sk->inicio && atual->chave >= chave)
            {
                if(atual->chave == chave)
                {
                    printf("Valor %d encontrado pela direita\n", chave);
                    return;
                }
                if(atual->ant[i] != NULL)
                {
                    atual = atual->ant[i];
                }
                else
                {
                    break;
                }
            }
        }
        printf("Valor %d nao encontrado pela direita\n", chave);
    }
    else
    {
        printf("Posição invalida. Use 0 para inicio ou 1 para fim.\n");
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    struct skiplist *sk = criaSkip(10, 0.6);

    insere(sk, 10);
    insere(sk, 20);
    insere(sk, 30);
    insere(sk, 40);
    insere(sk, 60);
    insere(sk, 70);
    insere(sk, 50);
    insere(sk, 90);
    insere(sk, 80);
    insere(sk, 110);
    insere(sk, 100);
    insere(sk, 140);
    insere(sk, 150);
    insere(sk, 160);
    insere(sk, 180);
    insere(sk, 190);
    insere(sk, 200);
    insere(sk, 210);
    insere(sk, 220);
    insere(sk, 230);
    insere(sk, 240);
    insere(sk, 250);
    insere(sk, 260);
    insere(sk, 270);
    insere(sk, 280);
    insere(sk, 290);
    insere(sk, 300);

    printf("impressao da SkipList pelo inicio:\n");
    imprime(0, sk);

    printf("\n\nimpressao da SkipList pelo fim:\n");
    imprime(1, sk);

    busca(sk, 30, 0);
    busca(sk, 30, 1);
    busca(sk, 25, 0);
    busca(sk, 25, 1);

    return 0;
}
