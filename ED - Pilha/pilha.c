#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"


Pilha *criarPilha(int limit) {
  Pilha *p = malloc(sizeof(Pilha));
  if(p == NULL) return NULL;
  p->dados = malloc(sizeof(unsigned int) * limit);
  if(p->dados == NULL) { // Erro na inicialização da pilha
    free(p);
    return NULL;
  }
  p->length = 0;
  p->limit = limit;
  return p;
}

void liberarPilha(Pilha *p) {
  free(p->dados);
  free(p);
}

// Função para exibir os dados da pilha
void exibirPilha(Pilha *p) 
{
  printf("Valores na pilha:\n");
  for (int i = 0; i < p->length; i++)
    printf("%u\n", p->dados[i]);
  printf("\n");
}


// a ser implementado pelo aluno

int top(Pilha *p)
{
  if (p->length == 0)
  {
    printf("Pilha vazia!\n");
    return -1;
  }
  else
    return (p->dados[p->length - 1]);
}

int pop(Pilha *p)
{
  if(p->length == 0) //pilha vazia
    return -1;
  p->length--;
  return (p->dados[p->length]);
}

int push(Pilha *p, unsigned int dado)
{
  if (p->length == p->limit)
    return -1;
  p->dados[p->length] = dado;
  p->length++;
  exibirPilha(p);
}