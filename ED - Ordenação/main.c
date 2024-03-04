#include <stdio.h>
#include "ordena.h"

int main()
{
    int qtd = 8;
    int array[] = {5, 3, 7, 1, 2, 4, 9, 8};

    int array2[] = {15, 13, 17, 11, 12, 14, 19, 18};

    //selectionSortV2(array, qtd);
    //bubbleSort_invertido(array2, qtd);

    bubbleSort_invertido_comCalma(array, qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("O indice %d do array ordenado eh: %d\n", i, array[i]);
    }
    for (int i = 0; i < qtd; i++)
    {
        printf("O indice %d do array ordenado eh: %d\n", i, array2[i]);
    }
    return 0;
}