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



    return 0;
}