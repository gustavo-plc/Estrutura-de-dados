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
    for (int i = 0; i < tamanho; i++)
    {
        if ((vetor->vetor[i]) == valor)
            return i;   
    }
    return -1;
}

int num_ocorrencias(int tamanho, Vetor *vetor, int valor)
{
    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if ((vetor->vetor[i]) == valor)
        {
            cont = cont + 1;
            return cont;
        }
    }
    return -1;
}

int ult_ocorrencia(int tamanho, Vetor *vetor, int valor)
{
    int posicao = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if ((vetor->vetor[i]) == valor)
        {
            posicao = i;
            return posicao;
        }       
    }
    return -1;
}


int maior_menor(Vetor *vetor)
{
    float maior,menor;
    menor = vetor->vetor[0];
    maior = vetor->vetor[0];
    
    for (int i = 0; i < vetor->quantidade; i++)
    {
        if ((vetor->vetor[i]) >= (maior))
            maior = vetor->vetor[i]; 
        if ((vetor->vetor[i]) <= (menor))
            menor = vetor->vetor[i];
    }
    return -1;
}