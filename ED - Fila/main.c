#include "fila.h"

int main() {
  int tamanho = 5;
  Fila *f = criarFila(tamanho);

  for (int i = 0; i < tamanho-1; i++) // não cria uma fila toda completa, para sobrar espaço ao final para inserção de elementos.
  {
    f->dados[i] = (i+2)*10;
    f->length++;
  }
  
  exibirFila(f);

  enfileira(f, 100);

  desenfileira(f);

  liberarFila(f);
  return 0;
}