#ifndef FILA_H
#define FILA_H


struct fila {
  unsigned int *dados;
  int length;
  int limit;
};

// protótipo da estrutura
typedef struct fila Fila;

// protótipo das operações
Fila *criarFila(int limit);
void liberarFila(Fila *p);
void exibirFila(Fila *f);

// a ser implementado pelo aluno
void enfileira(Fila *p, unsigned int dado);
int desenfileira(Fila *p);

#endif // FILA_H