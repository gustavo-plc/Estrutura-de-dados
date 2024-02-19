#include <stdio.h> // incluído para possibilitar o printf da função exibeResultado
#include "calc.h"

struct calc
{
    float ans;
};

Calc* somaCalc(Calc *c, float n)
{
    c->ans = c->ans + n;
}

Calc* subtCalc(Calc *c, float n)
{
    c->ans = c->ans - n;
}

Calc* multCalc(Calc *c, float n)
{
    c->ans = c->ans * n;
}

Calc* divCalc(Calc *c, float n)
{
    c->ans = c->ans / n;
}

void exibeResultado(Calc *c)
{
    if(!c)
        return printf("Calculadora não existe!\n");
    printf("Resultado: %.2f\n", c->ans);
}

void destroiCalc(Calc *c)
{
    if(!c)
        return printf("Calculadora não existe!\n");
    free(c);
}

void zeraCalc(Calc *c)
{
    if(!c)
        return printf("Calculadora não existe!\n");
    c->ans = 0;
}

Calc* criaCalc()
{
    Calc *c = malloc(sizeof(Calc));
    c->ans = 0;
    return c;
}