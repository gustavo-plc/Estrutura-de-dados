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

struct lista 
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

enfileira(fila, int dado);
No *desenfileira(fila);
push(pilha, p1);
push(pilha, p2);
push(pilha, p3);
No *pop(pilha);

#endif