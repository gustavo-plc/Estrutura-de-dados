#include <stdlib.h>
#include <stdio.h>
#include "busca_l.h"

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
        v1->vetor[i] = i + 3;
        printf("O valor da posição %d do vetor é: %d\n", i, v1->vetor[i]);
    }
    return v1;
}


int busca_linear(int tamanho, Vetor *vetor, int valor)
{
    int *p = vetor->vetor;
    for (int i = 0; i < tamanho; i++)
    {
        if ((vetor->vetor[i]) == valor)
            return i;   
    }
    return -1;
}