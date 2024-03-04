#include <stdio.h>
#include "ordena.h"

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) ;  //para cada iteração do laço externo, o laço interno percorre o array
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubbleSort_invertido(int arr[], int n)
{

}