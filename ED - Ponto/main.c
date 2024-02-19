#include <stdio.h>
#include "Ponto.h"

int main() {
    Ponto *p1, *p2;
    p1 = ponto_cria(10, 21);
    p2 = ponto_cria(7, 25);

    float distancia = ponto_distancia(p1, p2);
    printf("Distancia entre os pontos: %f\n", distancia);
    
    float x, y;
    ponto_acessa(p1, &x, &y);
    printf("P1: %f, %f\n", x, y);
    
    ponto_acessa(p2, &x, &y);
    printf("P2: %f, %f\n", x, y);
    
    ponto_libera(p1);
    ponto_libera(p2);

    return 0;
}