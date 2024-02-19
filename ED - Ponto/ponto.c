#include <stdlib.h>
#include <math.h>

#include "Ponto.h" // inclui os protótipos

struct ponto {
    float x;
    float y;
};

// cria um novo ponto
Ponto* ponto_cria(float x, float y) {
    Ponto *p = (Ponto *) malloc(sizeof(Ponto));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}
// libera um ponto
void ponto_libera(Ponto *p) {
  free(p);
}

// acessa os valores de x e y de um ponto
int ponto_acessa(Ponto *p, float *x, float *y) {
    if(!p) return 0;
    *x = p->x;
    *y = p->y;
    return 1;
}

// atribui novos valores de x e y a um ponto
int ponto_atribui(Ponto *p, float x, float y) {
    if(!p) return 0;
    p->x = x;
    p->y = y;
    return 1;
}

// calcula a distância entre dois pontos
float ponto_distancia(Ponto *p1, Ponto *p2) {
    if(!p1 || !p2) return -1;
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx*dx + dy*dy);
}