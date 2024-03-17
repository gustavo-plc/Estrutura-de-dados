#include <stdio.h>
#include "pilha.h"

int main() {
  Pilha *p = criarPilha(4);
  p->dados[0] = 10;
  p->length++;
  p->dados[1] = 20;
  p->length++;
  p->dados[2] = 30;
  p->length++;
  p->dados[3] = 40;
  p->length++;
  pop(p);

  liberarPilha(p);
  return 0;
}