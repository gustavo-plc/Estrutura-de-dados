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
   
}

