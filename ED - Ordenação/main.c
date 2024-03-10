#include <stdio.h>
#include "ordena.h"

int main()
{
    int qtd = 8;
    int array[] = {5, 3, 7, 1, 2, 4, 9, 8};

    int array2[] = {15, 13, 17, 11, 12, 14, 19, 18};

    int array3[] = {25, 23, 27, 21, 22, 24, 29, 28};


    bubbleSort_invertido(array, qtd);

    selectionSort(array2, qtd);

    heapSort(qtd, array3);

    for (int i = 0; i < qtd; i++)
        printf("O indice %d do array 1 ordenado eh: %d\n", i, array[i]);
    
    for (int i = 0; i < qtd; i++)
        printf("O indice %d do array 2 ordenado eh: %d\n", i, array2[i]);

    for (int i = 0; i < qtd; i++)
        printf("O indice %d do array 3 ordenado eh: %d\n", i, array3[i]);

    return 0;
}