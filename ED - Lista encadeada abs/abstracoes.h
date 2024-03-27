#ifndef ABSTRA_H
#define ABSTRA_H

typedef struct lista Lista;
typedef struct no No;
typedef unsigned int uint;

struct no
{
    int dado;
    struct no *prox;
};

struct lista  //uma lista é composta por nós
{
    No *inicio, *fim;
    uint length;
    uint capacidade;
};

No *criarNo(int dado);
Lista *criarLista(); // cria uma lista vazia
void listar(Lista *lista);
void inserirInicio(Lista *lista, int dado); // inserir o primeiro elemento da lista
void inserirFim(Lista *lista, int dado);

void enfileira(Lista *fila, int dado);
No *desenfileira(Lista *fila);
void push(Lista *pilha, int dado);

No *pop(Lista *pilha);

#endif