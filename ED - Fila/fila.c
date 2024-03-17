#include <stdlib.h>
#include <stdio.h>
#include "fila.h"



Fila *criarFila(int limit) {
  Fila *f = malloc(sizeof(Fila));
  if(f == NULL) return NULL;
  f->dados = malloc(sizeof(unsigned int) * limit);
  if(f->dados == NULL) { // Erro na inicialização da fila
    free(f);
    return NULL;
  }
  f->length = 0;
  f->limit = limit;
  return f;
}

void liberarFila(Fila *f) {
  free(f->dados);
  free(f);
}

void exibirFila(Fila *f) 
{
  printf("\nValores na fila:\n");
  for (int i = (f->length-1); i >=0 ; i--)
    printf("%u ", f->dados[i]);
  printf("\nO primeiro da fila eh o %d\n",f->dados[f->length-1]);
  printf("\n");
}

// a ser imflementado felo aluno

void enfileira(Fila *f, unsigned int dado) //insere elemento ao final da fila
{
  if (f->length == f->limit)
  {
    printf("Fila cheia!\n");
    return;
  }
  f->dados[f->length] = dado;
  f->length++;
  exibirFila(f);
}

// int desenfileira(Fila *f);