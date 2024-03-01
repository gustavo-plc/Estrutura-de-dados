#include <stdio.h>
#include "busca_l.h"

int main()
{
    int tamanho = 6;
    int valor = 8;
    cria_vetor(tamanho);
    int pos = busca_linear(tamanho, v1[], valor);
    if (pos == -1)
        printf("O valor não foi encontrado no vetor!\n");
    else
        printf("O valor procurado está na posição %d do vator!\n", pos);
}