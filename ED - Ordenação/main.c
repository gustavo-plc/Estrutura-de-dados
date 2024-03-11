#include <stdio.h>
#include "ordena.h"

int main()
{
    int qtd = 8;
    int qtd2 = 10;
    int array[] = {5, 3, 7, 1, 2, 4, 9, 8};

    int array2[] = {15, 13, 17, 11, 12, 14, 19, 18};

    int array3[] = {25, 23, 27, 21, 22, 24, 29, 28};

    int array4[] = {35, 33, 37, 31, 32, 34, 39, 38};

    int arrayLista3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    //bubbleSort_invertido(array, qtd);

    //selectionSort(array2, qtd);

    //heapSort(qtd, array3);

    //selectionSortHalf(array4, qtd);

    //bubbleSortCompTroca(arrayLista3, qtd2);

    selectionSortCompTroca(arrayLista3, qtd2);

    for (int i = 0; i < qtd2; i++)
        printf("O indice %d do array 1 ordenado eh: %d\n", i, arrayLista3[i]);
    
    //for (int i = 0; i < qtd; i++)
        //printf("O indice %d do array 2 ordenado eh: %d\n", i, array2[i]);

    //for (int i = 0; i < qtd; i++)
        //printf("O indice %d do array 3 ordenado eh: %d\n", i, array3[i]);

    //for (int i = 0; i < qtd; i++)
        //printf("O indice %d do array 4 ordenado eh: %d\n", i, array4[i]);

    //for (int i = 0; i < 10; i++)
        //printf("O indice %d do array 5 ordenado eh: %d\n", i, arrayLista3[i]);

    return 0;
}