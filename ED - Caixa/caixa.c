#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"


//detalhes da implementação da estrutura Caixa
struct caixa
{
    float comprimento;
    float largura;
    float altura;
} ;

//detalhes da implementação das operações do TAD

Caixa *criar_caixa(float comp, float largura, float altura)
{
    Caixa *c1 = (Caixa*) malloc(sizeof(Caixa));  //Por que fazer esse casting?
    c1->altura = altura;
    c1->comprimento = comp;
    c1->largura = largura;
    printf("\nA caixa foi criada no endereço: %p\n", c1);
    return c1;
}

int liberar_caixa(Caixa *c)
{
    if(!c)
    {
        printf("\nA caixa indicada para liberação não existe!\n");// tratamento de exceção, para caso se queira liberar uma caixa que não existe.
        return 0;
    }
    c->altura = 0;
    c->comprimento = 0;
    c->largura = 0;

    free(c);
    printf("\nA caixa foi liberada da memoria\n");
    return 1;
}

int exibir_caixa(Caixa *c)
{
    if(!c)
    {
        printf("\nA caixa indicada para exibição não existe!\n");// tratamento de exceção, para caso se queira exibir uma caixa que não existe.
        return 0;
    }
    printf("\nA largura, comprimento e altura da caixa sao respectivamente: %.2f %.2f %.2f\n", c->largura, c->comprimento, c->altura);
    return 1;
}

float area_caixa(Caixa *c)
{
    if(!c) // tratamento de exceção, para caso se queira calcular a área de uma caixa que não existe.
        printf("\nA caixa indicada para cálculo de área não existe!\n");
    float area = (c->comprimento) * (c->altura) * 2 + (c->comprimento) * (c->largura) * 2 + (c->altura) * (c->largura) * 2;
    return printf("\nA area total da caixa e: %.2f m2\n", area);
}

float volume_caixa(Caixa *c)
{
    if(!c) // tratamento de exceção, para caso se queira calcular o volume de uma caixa que não existe.
        printf("\nA caixa indicada para cálculo de volume não existe!\n");
    float volume = (c->comprimento) * (c->altura) * (c->largura);
    return printf("\nO volume da caixa e: %.4f m3\n", volume);
}