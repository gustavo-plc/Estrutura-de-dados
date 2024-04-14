#include "vetor.h"

int main() {
  Vetor *v = criarVetor(10);
  // outras operações com vetor

  inserir(v, 1);
  inserir(v, 2);
  inserir(v, 3);
  inserir(v, 4);
  inserir(v, 5);
  inserir(v, 6);
  inserir(v, 7);
  inserir(v, 8);

  listar(v);

  deletarElementoV2(v, 5);

  listar(v);

  liberarVetor(v);

  return 0;
}