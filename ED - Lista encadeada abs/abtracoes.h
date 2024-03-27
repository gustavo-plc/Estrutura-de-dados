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
}

No *criarNo(int dado);
Lista *criarLista(); // cria uma lista vazia
void listar(Lista *lista);
void inserirInicio(Lista *lista, int dado); // inserir o primeiro elemento da lista
void inserirFim(Lista lista, int dado);     // terminar de fazer com base no código anterior mmm

#endif