#include "vetor.h"

int main() {
  Vetor *v = criarVetor(10);
  // outras operações com vetor

  inserir(v, 2);
  inserir(v, 2);
  inserir(v, 20);
  inserir(v, 2);
  inserir(v, 2);
  inserir(v, 200);
  inserir(v, 2);
  inserir(v, 2);

  listar(v);

  liberarVetor(v);

  return 0;
}