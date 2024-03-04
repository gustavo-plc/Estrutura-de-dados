#include <stdio.h>
#include "ordena.h"

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++) ;  //para cada iteração do laço externo, o laço interno percorre o array
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSort_invertido(int arr[], int n) //função para ordem decrescente
{
    int i, j;
    for (int i = 0; i < n - 1; i++) // no invertido, continuo tendo que fazer n-1 iterações
    {
        for (int j = n - i - 1; j > 0; j--)
        {
            if (arr[j]>arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}