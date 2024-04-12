#include <stdio.h>
#include "calc.h"

int main()
{

Calc *c1 = criaCalc();

somaCalc(c1, 3);
somaCalc(c1, 9);
subtCalc(c1, 1);
multCalc(c1,2);
divCalc(c1, 22);

exibeResultado(c1);

zeraCalc(c1);

destroiCalc(c1);

somaCalc(c1, 3);

}

