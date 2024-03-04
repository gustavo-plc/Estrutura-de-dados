#include <stdio.h>
#include "ordena.h"

int main()
{
    int qtd = 8;
    int array[] = {5, 3, 7, 1, 2, 4, 9, 8};
    bubbleSort(array, qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("O indice %d do array ordenado eh: %d\n", i, array[i]);
    }
    return 0;
}