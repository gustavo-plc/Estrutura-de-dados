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
  if(v == NULL) return NULL; // Erro na alocação
  v->dados = malloc(sizeof(int) * limit);
  if(v->dados == NULL) return NULL; // Erro na alocação
  v->length = 0;
  v->limit = limit;
  return v;
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

void inserir(Vetor *v, int dado)
{
  if (v->length == v->limit)
    printf("Vetor cheio!\n");
  else
  {
    v->dados[v->length] = dado;
    v->length++;
  }
}

void atualizarUm(Vetor *v, int dadoAntigo, int dadoNovo)
{
   for (int i = 0; i < v->length; i++)
    {
        if (v->dados[i] == dadoAntigo)
        {
          v->dados[i] = dadoNovo;
          return;
        }
    }
    printf("Valor buscado não encontrado.\n");
}

void atualizarTodos(Vetor *v, int dadoAntigo, int dadoNovo)
{
   for (int i = 0; i < v->length; i++)
    {
      if (v->dados[i] == dadoAntigo)
        v->dados[i] = dadoNovo;
    }
    //printf("Valor buscado não encontrado.\n");
}

void atualizarIndice(Vetor *v, int indice, int dadoNovo)
{ 
  if (0<=indice<v->length)
    v->dados[indice] = dadoNovo;
  else
    printf("Valor inválido de índice.\n");
}

int buscarElemento(Vetor *v, int elemento)
{
  for (int i = 0; i < v->length; i++)
  {
    if (v->dados[i] == elemento)
      return i;   
  }
  return -1;
}

int obterElemento(Vetor *v, int indice)
{
  if (0<=indice<v->length)
  {
    for (int i = 0; i < v->length; i++)
      {
        if (v->dados[i] == elemento)
        return v->dados[i];   
      }
  }  
  else
    printf("Valor inválido de índice.\n");
}


int deletarElemento(Vetor *v, int elemento) // deletar elemento buscado
{
  int aux;
  for (int i = 0; i < v->length; i++)
  {
    if (v->dados[i] == elemento)
      aux = i;
  }
  for (int i = aux; i < v->length; i++)
  {
      v->dados[aux] = v->dados[aux+1];  
  }
  lenght--;
}



int deletarIndice(Vetor *v, int indice) // deletar elemento pelo índice
{
  if (0<=indice<v->length)
  {
    for (int i = indice; i < v->length; i++)
      {
         v->dados[indice] = v->dados[indice+1];  
      }
      lenght--;
  }
  else
    printf("Valor inválido de índice.\n");
}

