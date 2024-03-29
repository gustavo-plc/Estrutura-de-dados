#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "busca_l.h"


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
            printf("Valor constante no indice %d atualizado para %d!\n", i, novo_valor);
            i = 0;
        }
    }
}

int buscaBinaria(Vetor *vetor, int tamanho, int valor)
{
    int inicio = 0, fim = tamanho - 1, meio;
    int cont = 0;
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (vetor->vetor[meio] == valor)
        {
            return cont;
        } else if (vetor->vetor[meio] < valor)
        {
            inicio = meio + 1; //busca na metade de cima
            cont++;
        } else 
        {
            fim = meio - 1; //busca na metade de baixo
            cont++;
        }
    }
    return -1; //elemento não encontrado.
}

int busca_linearv2(int tamanho, Vetor *vetor, int valor)
{
    for (int i = 0; i < tamanho/2; i++)
    {
        if ((vetor->vetor[i]) == valor)
            return i;  
        if ((vetor->vetor[tamanho - 1 - i]) == valor)
            return tamanho - 1 - i;     
    }
    return -1;
}

int buscaProxima(Vetor * vetor, int tamanho, int valor_usuario)
{
    int inicio = 0, fim = tamanho - 1, meio;
    int maisProximo = INT_MAX;
    int valorMaisProximo;

    while (inicio<=fim)
    {
        meio = (inicio + fim) / 2;
        
        if (abs(vetor->vetor[meio]-valor_usuario) < maisProximo) //se a distância entre o valor médio do array e o valor fornecido pelo usuário for menor que o mais próximo
        {                                                        // e sempre será, então o valor de maisProximo é atualizado para o valor dessa distância;
            maisProximo = abs(vetor->vetor[meio]-valor_usuario);
            valorMaisProximo = vetor->vetor[meio];
        }
        if (vetor->vetor[meio] > valor_usuario)
        {
            fim = meio - 1;  //busca na metade de baixo, parte inferior 
        } else if (vetor->vetor[meio] < valor_usuario)
        {
            inicio = meio + 1;  //busca na metade de cima, parte superior
        } else
            return meio;
    }
    return valorMaisProximo; //local mais próximo.
}