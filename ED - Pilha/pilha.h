#ifndef PILHA_H
#define PILHA_H

//declaração da estrutura
struct pilha {
  unsigned int *dados;
  int length;
  int limit;
};

// protótipo da estrutura
typedef struct pilha Pilha;

// protótipo das operações
Pilha *criarPilha(int limit);
void liberarPilha(Pilha *p);
void exibirPilha(Pilha *p);

// a ser implementado pelo aluno
int top(Pilha *p);
//int pop(Pilha *p);
//void push(Pilha *p, unsigned int dado);

#endif // PILHA_H