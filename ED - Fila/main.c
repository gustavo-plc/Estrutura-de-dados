#include "fila.h"

int main() {
  int tamanho = 4;
  Fila *f = criarFila(tamanho);

  for (int i = 0; i < tamanho; i++)
  {
    f->dados[i] = (i+2)*10;
    f->length++;
  }
  
  exibirFila(f);

  // espaço para testes das operações criadas pelo aluno

  liberarFila(f);
  return 0;
}