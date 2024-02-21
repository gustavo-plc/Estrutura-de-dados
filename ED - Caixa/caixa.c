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
    free(c);
    printf("A caixa foi liberada da memória");
}

void exibir_caixa(Caixa *c)
{


}

float area_caixa(Caixa *c)
{


}

float volume_caixa(Caixa *c)
{


}