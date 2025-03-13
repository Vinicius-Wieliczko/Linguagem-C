#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    int bal;
    struct no *esq;
    struct no *dir;
} no;

struct no *raiz_avl = NULL;

struct no* cria_no (int chave)
{
    struct no* aux = (no*) malloc(sizeof (no));
    aux->dado = chave;
    aux->esq = NULL;
    aux->dir = NULL;
    aux->bal = 0;
    return aux;
};

void direita (no* atual)
{
    no *q, *aux;

    q = atual->esq;
    aux = q->dir;

    q->dir = atual;
    atual->esq = aux;

}


void esquerda(no* atual)
{
    no *q, *aux;

    q = atual->dir;
    aux = q->esq;

    q->esq = atual;
    atual->dir = aux;
}

void insere_bal(int chave)
{
    struct no *pp = NULL, *p = raiz_avl, *pajovem = NULL, *ajovem =
                                       raiz_avl, *q, *filho;
    int imbal;
    if (p == NULL)   /* Arvore vazia */
    {
        raiz_avl = cria_no(chave); /* Funcao para criacao de um novo no */
        return;
    }

    /* Insere chave e descobre ancestral mais jovem a ser desbalanceado */
    while (p != NULL)
    {
        if (chave < p-> dado)
            q = p->esq;
        else q = p->dir;
        if (q != NULL)
            if (q-> bal != 0)
            {
                pajovem = p;
                ajovem = q;
            }
        pp = p;
        p = q;
    }
    q = cria_no(chave);
    if (chave < pp-> dado)
        pp->esq = q;
    else pp->dir = q;
    /* Balanceamento de todos os nós entre ajovem e q devem ser
    ajustados */
    if (chave < ajovem-> dado)
        filho = ajovem->esq;
    else filho = ajovem->
                     dir;
    p = filho;
    while (p != q)
    {
        if (chave < p-> dado)
        {
            p->bal = 1;
            p = p->esq;
        }
        else
        {
            p->bal = -1;
            p = p->dir;
        }
    }
    if (chave < ajovem-> dado)
        imbal = 1;
    else imbal = -1;
    if (ajovem-> bal == 0)  /*Não houve desbalanceamento */
    {
        ajovem->bal = imbal;
        return;
    }
    if (ajovem-> bal != imbal)  /*Não houve desbalanceamento */
    {

        ajovem->bal = 0;
        return;
    }
    /* Houve desbalanceamento */
    if (filho-> bal == imbal)
    {
        p = filho;
        if (imbal == 1) /* Faz rotacao simples */
            direita(ajovem);
        else esquerda(ajovem);
        ajovem->bal = 0;
        filho->bal = 0;
    }
    else
    {
        if (imbal == 1)   /*Faz rotacao dupla */
        {
            p = filho->dir;
            esquerda(filho);
            ajovem->esq = p;
            direita(ajovem);
        }
        else
        {
            p = filho->esq;
            direita(filho);
            ajovem->dir = p;
            esquerda(ajovem);
        }
        if (p-> bal == 0)
        {
            ajovem->bal = 0;
            filho->bal = 0;
        }
        else
        {
            if (p-> bal == imbal)
            {
                ajovem->bal = -imbal;
                filho->bal = 0;
            }
            else
            {
                ajovem->bal = 0;
                filho->bal = imbal;
            }
        }
        p->bal = 0;
    }
    if (pajovem == NULL) // Ajusta ponteiro do pai do ancestral mais jovem
        raiz_avl = p;
    else if (ajovem == pajovem-> dir)
        pajovem->dir = p;
    else pajovem->esq = p;
}

void PreOrdem(no *aux)
{
    if(aux == raiz_avl)
    {
        printf("\n\nEm pre-ordem: \n");
    }
    if (aux != NULL)
    {

        printf("%d ", aux->dado);

        PreOrdem(aux->esq);
        PreOrdem(aux->dir);
    }
}

void Ordem(no *aux)
{
    if(aux == raiz_avl)
    {
        printf("\n\nEm ordem: \n", aux->dado);
    }
    if (aux != NULL)
    {
        Ordem(aux->esq);

        printf("%d ", aux->dado);

        Ordem(aux->dir);
    }
}

void PosOrdem(no *aux)
{
    if(aux == raiz_avl)
    {
        printf("\n\nEm pos-ordem: \n", aux->dado);
    }
    if (aux != NULL)
    {
        PosOrdem(aux->esq);
        PosOrdem(aux->dir);

        printf("%d ", aux->dado);
    }
}

int main()
{

    insere_bal(1);
    insere_bal(2);
    insere_bal(3);
    insere_bal(4);

    PreOrdem(raiz_avl);
    Ordem(raiz_avl);
    PosOrdem(raiz_avl);


    return 0;
}
