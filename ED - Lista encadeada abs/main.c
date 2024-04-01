#include <stdio.h>
#include <stdlib.h>
#include "abstracoes.h"

int main()
{
    //criação e concatenação dos nós
    No *inicio = criarNo(1);
    if(!inicio)
        return -1;

    inicio->prox = criarNo(2);
    if(!inicio->prox)
        return -1;

    inicio->prox->prox = criarNo(3);
    if(!inicio->prox->prox)
        return -1;

    inicio->prox->prox->prox = criarNo(4);
    if (!inicio->prox->prox->prox)
        return -1;

    inicio->prox->prox->prox->prox = criarNo(5);
    if(!inicio->prox->prox->prox->prox)
        return -1;

    //criação da lista
    Lista *lista = criarLista();

    listar(lista);

    inserirInicio(lista, 1);

    listar(lista);

    inserirInicio(lista, 2);

    listar(lista);

    inserirFim(lista, 3);

    listar(lista);

    enfileira(lista, 9); //entra no rabo da fila, ou seja, no final da lista

    listar(lista);

    desenfileira(lista); //sai da cabeça da fila, ou seja, do ínicio da lista

    listar(lista);

    push(lista, 10); //inserir novo elemento no topo da pilha, ou seja, no começo da lista.

    listar(lista);

    push(lista, 20); //inserir novo elemento no topo da pilha, ou seja, no começo da lista.

    listar(lista);

    push(lista, 30); //inserir novo elemento no topo da pilha, ou seja, no começo da lista.

    listar(lista);

    pop(lista);

    listar(lista);

    pop(lista);

    listar(lista);

    inserirOrdenado(lista, 4);

    listar(lista);

    deletarInicio(lista);

    listar(lista);

    deletarInicio(lista);

    listar(lista);
    
    return 0;

}