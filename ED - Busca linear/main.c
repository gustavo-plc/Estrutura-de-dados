#include <stdio.h>
#include "busca_l.h"

int main()
{
    int tamanho = 6;
    int valor = 8;
    Vetor *v = cria_vetor(tamanho);
    int pos = busca_linear(tamanho, v, valor);
    if (pos == -1)
        printf("O valor nao foi encontrado no vetor!\n");
    else
        printf("O valor procurado esta na posicao %d do vetor!\n", pos);
}