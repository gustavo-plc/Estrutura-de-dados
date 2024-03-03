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
        v1->vetor[i] = i + 20;
        printf("O valor da posicao %d do vetor eh: %d\n", i, v1->vetor[i]);
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


void maior_menor(Vetor *vetor, int tamanho)
{
    int maior,menor = vetor->vetor[0];
    
    for (int i = 0; i < vetor->quantidade; i++)
    {
        if ((vetor->vetor[i]) >= (maior))
            maior = vetor->vetor[i]; 
        if ((vetor->vetor[i]) <= (menor))
            menor = vetor->vetor[i];
    }
    printf("O maior valor do array eh: %d\n", maior);
    printf("O menor valor do array eh: %d\n", menor);
}

void atualiza(Vetor *vetor, int tamanho, int valor, int novo_valor)
{
    for (int i = tamanho - 1; i >= 0; i--)
    {
        if ((vetor->vetor[i]) == valor)
        {
            vetor->vetor[i] = novo_valor;
            printf("Valor constante no índice %d atualizado para %d!\n", i, novo_valor);
            i = 0;
        }
        else
            printf("Valor nao encontrado no array. Substituicao nao realizada!\n");
    }
}

int buscaBinaria(Vetor *vetor, int tamanho, int valor)
{
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (vetor->vetor[meio] == valor)
        {
            return meio;
        } else if (vetor->vetor[meio] < valor)
        {
            inicio = meio + 1;
        } else 
        {
            fim = meio - 1;
        }
    }
    return -1; //elemento não encontrado.
}