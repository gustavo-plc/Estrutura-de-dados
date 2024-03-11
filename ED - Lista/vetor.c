#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

struct vetor {
  int *dados;     // ponteiro para array de inteiros
  int length;   // comprimento
  int limit;  // tamanho máximo
};

Vetor *criarVetor(int limit) {
  Vetor *v = malloc(sizeof(Vetor));
  if(v == NULL) return; // Erro na alocação
  v->dados = malloc(sizeof(int) * limit);
  if(v->dados == NULL) return; // Erro na alocação
  v->length = 0;
  v->limit = limit;
}

void liberarVetor(Vetor *v) {
  free(v->dados);
  free(v);
}

void listar(Vetor *v) {
  for(int i = 0; i < v->length; i++) {
    printf("%d ", v->dados[i]);
  }
  printf("\n");
}

void zerar(Vetor *v) {
  v->length = 0;
}