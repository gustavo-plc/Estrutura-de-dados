#include <stdio.h>
#include <stdlib.h>
#include "abtracoes.h"

int main()
{
    No *inicio = criarNo(1);
    if(!inicio)
        return;

    No *inicio->prox = criarNo(2);
    if(!inicio->prox)
        return;

    No *inicio->prox->prox = criarNo(3);
    if(!inicio->prox->prox)
        return;

    No *inicio->prox->prox->prox = criarNo(4);
    if (!inicio->prox->prox->prox)
        return;

    No *inicio->prox->prox->prox->prox = criarNo(5);
    if(!inicio->prox->prox->prox->prox)
        return;

        
    return 0;
}