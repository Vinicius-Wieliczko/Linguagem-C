#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define N 199999


int A[N];

void geraVetor()
{
    int i;
    srand(13);
    for (i = 0; i < N; i++)
    {
        A[i] = rand() % (N * 13);
    }
}

void verficaVetor(clock_t t)
{
    int aux = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] > A[i + 1])
            aux++;
    }
    if (aux == 0)
        printf("\nTempo de excecução: %.2f\n", (float)t / CLOCKS_PER_SEC);
    else
        printf("\nVetor não está ordenado!\n");
}

void merge(int output[], int outputSize, int sublist[], int sublistSize)
{
    int temp[outputSize + sublistSize];
    int i = 0, j = 0, k = 0;

    while (i < outputSize && j < sublistSize)
    {
        if (output[i] < sublist[j])
        {
            temp[k++] = output[i++];
        }
        else
        {
            temp[k++] = sublist[j++];
        }
    }

    while (i < outputSize)
    {
        temp[k++] = output[i++];
    }

    while (j < sublistSize)
    {
        temp[k++] = sublist[j++];
    }

    for (i = 0; i < outputSize + sublistSize; i++)
    {
        output[i] = temp[i];
    }
}

void strandSort(int vet[], int n)
{
    int output[n]; // Lista de saída ordenada
    int outputSize = 0;

    while (n > 0)
    {
        int sublist[n];
        int sublistSize = 0;
        int i = 0;

        sublist[sublistSize++] = vet[i++];
        for (int j = i; j < n; j++)
        {
            if (vet[j] > sublist[sublistSize - 1])
            {
                sublist[sublistSize++] = vet[j];
            }
            else
            {
                vet[i - 1] = vet[j];
                i++;
            }
        }

        merge(output, outputSize, sublist, sublistSize);
        outputSize += sublistSize;
        n = i - 1;
    }

    // Copiar os elementos ordenados de volta para o array original
    for (int i = 0; i < outputSize; i++)
    {
        vet[i] = output[i];
    }
}

void imprimirVetor()
{
    int i;
    printf("Sorted array: ");
    for (i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    clock_t time1, time2;

    geraVetor();
    int tamanho = sizeof(A) / sizeof(A[0]);

    time1 = clock();
    strandSort(A, tamanho);
    time2 = (clock() - time1);
    verficaVetor(time2);

    time1 = clock();
    strandSort(A, tamanho);
    time2 = clock() - time1;
    verficaVetor(time2);
    return 0;
}
