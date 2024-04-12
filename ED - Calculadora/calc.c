#include <stdio.h> // incluído para possibilitar o printf da função exibeResultado
#include <stdlib.h> // para possibilitar o uso da função free e malloc
#include "calc.h"

struct calc
{
    float ans;
};

Calc* somaCalc(Calc *c, float n)
{
    if(!c)
    {
        printf("Problema ao carregar calculadora!\n");
        return NULL; 
    }
    c->ans = c->ans + n;
}

Calc* subtCalc(Calc *c, float n)
{
    if(!c)
    {
        printf("Problema ao carregar calculadora!\n");
        return NULL; 
    }
    c->ans = c->ans - n;
}

Calc* multCalc(Calc *c, float n)
{
    if(!c)
    {
        printf("Problema ao carregar calculadora!\n");
        return NULL; 
    }
    c->ans = c->ans * n;
}

Calc* divCalc(Calc *c, float n)
{
    if(!c)
    {
        printf("Problema ao carregar calculadora!\n");
        return NULL; 
    }
    c->ans = c->ans / n;
}

void exibeResultado(Calc *c)
{
    if(!c)
    {
        printf("Problema ao carregar calculadora!\n");
        return;
    }
    printf("Resultado: %.2f\n", c->ans);
}

void destroiCalc(Calc *c)
{
    if(!c)
    {
        printf("Calculadora não existe!\n");
        return;
    }
    free(c);
    printf("A Calculadora foi destruida!\n");
}

void zeraCalc(Calc *c)
{
    if(!c)
    {
        printf("Calculadora não existe!\n");
        return;
    }
    c->ans = 0;
    printf("A Calculadora foi zerada!\n");
}

Calc* criaCalc()
{
    Calc *c = malloc(sizeof(Calc));
    if(!c)
    {
        printf("Calculadora não existe!\n");
        return NULL;
    }
    c->ans = 0;
    printf("A Calculadora foi criada!\n");
    return c;
}