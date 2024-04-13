#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "busca_b.h"

struct vetor 
{
    int quantidade;
    int vetor[];
};

Vetor* cria_vetor(int qtd_elementos)
{
    Vetor* v1 = malloc(sizeof(Vetor));
    v1->quantidade = qtd_elementos;
    for (int i = 0; i < v1->quantidade; i++)
    {
        v1->vetor[i] = i + 1;
        printf("O valor da posicao %d do vetor eh: %d\n", i, v1->vetor[i]);
    }
    return v1;
}




int buscaBinaria(Vetor *vetor, int tamanho, int valor)
{
    if(!vetor)
    {
        printf("\nProblema ao carregar o vetor!");
        return -1;
    }
    if(tamanho == 0)
    {
        printf("\nVetor vazio!");
        return -1;
    }
    int inicio = 0;
    int fim = tamanho - 1;
    int meio = (inicio + fim) / 2;
    while(inicio != fim)
    {
        if(valor == vetor->vetor[meio])
        {
            printf("Valor encontrado na posicao: %d", meio);
            return -1;
        }
        else
        {
            if(valor > vetor->vetor[meio])
            {
                inicio = meio + 1;
            }
            else
            {
                fim = meio - 1;
                meio = (inicio + fim) / 2;
            }
        }
    }
}

