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
    Caixa *c1 = malloc(sizeof(Caixa));
    c1->altura = altura;
    c1->comprimento = comp;
    c1->largura = largura;
    printf("A caixa foi criada no endereço: %p\n", c1);
    return c1;
}

void liberar_caixa(Caixa *c)
{
    if(!c) // tratamento de exceção, para caso se queira liberar uma caixa que não existe.
        printf("A caixa indicada para liberação não existe!\n");
    free(c);
    printf("A caixa foi liberada da memória");
}

void exibir_caixa(Caixa *c)
{
    if(!c) // tratamento de exceção, para caso se queira exibir uma caixa que não existe.
        printf("A caixa indicada para exibição não existe!\n");
    printf("A largura, comprimento e altura da caixa é respectivamente: %.2f %.2f %.2f\n", c->largura, c->comprimento, c->altura);
}

float area_caixa(Caixa *c)
{
    if(!c) // tratamento de exceção, para caso se queira calcular a área de uma caixa que não existe.
        printf("A caixa indicada para cálculo de área não existe!\n");
    float area = (c->comprimento) * (c->altura) * 2 + (c->comprimento) * (c->largura) * 2 + (c->altura) * (c->largura) * 2;
    return printf("A área total da caixa é: %.2f m²\n", area);
}

float volume_caixa(Caixa *c)
{
    if(!c) // tratamento de exceção, para caso se queira calcular o volume de uma caixa que não existe.
        printf("A caixa indicada para cálculo de volume não existe!\n");
    float volume = (c->comprimento) * (c->altura) * (c->largura);
    return printf("O volume da caixa é: %.2f m³\n", volume);
}