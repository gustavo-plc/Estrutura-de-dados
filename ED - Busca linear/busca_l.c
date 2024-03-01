#include <stdlib.h>
#include <stdio.h>
#include "busca_l.h"

struct vetor 
{
    int quantidade;
    int vetor[];
};

void cria_vetor(int qtd_elementos)
{
    Vetor* v1 = malloc(sizeof(Vetor));
    v1->quantidade = qtd_elementos;
    for (int i = 0; i < v1->quantidade; i++)
    {
        v1->vetor[i] = i;
        printf("O valor da posição %d do vetor é: %d\n", i, v1[i]);
    }
}


int busca_linear(int tamanho, int vetor[], int valor);