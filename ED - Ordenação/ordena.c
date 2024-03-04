#include <stdio.h>
#include "ordena.h"

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++) ;  //para cada iteração do laço externo, o laço interno percorre o array
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
    int i, j, aux;
    for (i = 0; i < n - 1; i++) // no invertido, continuo tendo que fazer n-1 iterações
    {
        for (j = n - 1; j > i; j--)
        {
            if (arr[j]>arr[j-1])
            {
                aux = arr[j];
	            arr[j] = arr[j-1];
	            arr[j-1] = aux;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n ; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void selectionSortV2(int arr[], int n)
{
    int i, j, maior, temp;
    for (i = n - 1; i > 0; i--)
    {
        maior = i;
        for (j = 0; j < i ; j++)
        {
            if(arr[j] > arr[maior])
                maior = j;
        }
        if (maior != i)  //se foi encontrado elemento maior, aí simi faz a troca.
        {
            temp = arr[i];
            arr[i] = arr[maior];
            arr[maior] = temp;
        }
    }
}