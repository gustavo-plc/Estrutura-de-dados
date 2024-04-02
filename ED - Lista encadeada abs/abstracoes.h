#ifndef ABSTRA_H
#define ABSTRA_H

typedef struct lista Lista;
typedef struct no No;
typedef unsigned int uint;
typedef struct pilha Pilha;

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

struct pilha {
No *topo;
uint length;
};

No *criarNo(int dado);
Lista *criarLista(); // cria uma lista vazia
void listar(Lista *lista);
void listarPilha(Pilha *pilha);
void inserirInicio(Lista *lista, int dado); // inserir o primeiro elemento da lista
void inserirFim(Lista *lista, int dado);

void enfileira(Lista *fila, int dado);
No *desenfileira(Lista *fila);
void push(Lista *pilha, int dado);

No *pop(Lista *pilha);

void inserirOrdenado(Lista *lista, int dado);
void deletarInicio(Lista *lista);

void deletarFim(Lista *lista);

Pilha *criarPilha();
void empilha(Pilha *pilha, uint dado);
int topo(Pilha *pilha);

#endif