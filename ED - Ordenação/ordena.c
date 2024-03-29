#include <stdio.h>
#include "ordena.h"

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)  //para cada iteração do laço externo, o laço interno percorre o array
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


void bubbleSort_invertido(int arr[], int n) //função para ordem decrescente, percorrendo da direita para a esquerda.
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

void bubbleSortCompTroca(int arr[], int n)
{
    int troca = 0, comp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)  //para cada iteração do laço externo, o laço interno percorre o array
        {
            comp++;
            if ((arr[j]) > (arr[j+1]))
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                troca++;
            }
        }
    }
    printf("O numero de trocas foi: %d\n", troca);
    printf("O numero de comparacoes foi: %d\n",comp);
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
        if (maior != i)  //se foi encontrado elemento maior, aí sim faz a troca.
        {
            temp = arr[i];
            arr[i] = arr[maior]; 
            arr[maior] = temp;
        }
    }
}

void selectionSortHalf(int arr[], int n) //ainda não funciona corretamente, foi o máximo que conseguimos chegar. Sem IA!
{
    int i, j, min, max, temp1, temp2;
    for (i = 0; i < (n - 1)/2; i++)
    {
        min = i; //definição dos extremos como sendo máximo e mínimo
        max = n - 1 - i;
        for (j = i + 1; j <= n - 1 - i; j++)
        {
            if(arr[j] < arr[min])
                min = j;
            if(arr[n-j-1] > arr[max])
                max = n-j-1;    
        }
        if (min != i) // ou seja, se min foi alterado...
        {
            temp1 = arr[i];
            arr[i] = arr[min];
            arr[min] = temp1;
        }
        if (max != n - 1 - i) // ou seja, se max foi alterado
        {
            temp2 = arr[i];
            arr[i] = arr[max];
            arr[max] = temp2;
        }
    }
}

void selectionSortCompTroca(int arr[], int n)
{
   int i, j, min, temp;
   int troca = 0, comp = 0;
   for (i = 0; i < n - 1; i++)
   {
       min = i; //o índice do menor elemento é i a cada iteração
       for (j = i + 1; j < n; j++)
       {
            comp++; //contador de comparações é colocado dentro do laço mais interno
            if (arr[j] < arr[min])
               min = j; // o índice do menor elemento passa a ser j
       }
       if (min != i) //se min tiver sido alterado
       {
           temp = arr[i]; //temp recebe o valor que era tido como menor
           arr[i] = arr[min]; //o menor valor é colocado na posição correta, no índice i
           arr[min] = temp; 
           troca++; //contador de troca
       }
    } 
    printf("O numero de trocas foi: %d\n", troca);
    printf("O numero de comparacoes foi: %d\n", comp); 
}

void ajusta_heap (int n, int arr[n], int i) 
{
    int maior = i;
    int esq, dir, temp;
    while (maior < n) 
    {
        esq = 2*i + 1;
        dir = 2*i + 2;
        if (esq < n && arr[esq] > arr[maior]) 
            maior = esq;
        if (dir < n && arr[dir] > arr[maior]) 
            maior = dir;
        
        if (maior != i) 
        {
            temp = arr[i];
            arr[i] = arr[maior];
            arr[maior] = temp;
            i = maior;
        }
        else
            break;
    }
}

void construir_heap(int n, int arr[n]) 
{
    for (int i = n/2-1; i >= 0; i--)
        ajusta_heap (n, arr, i);
}

void heapSort(int n, int arr[n])
{
    int i, temp;
    construir_heap(n, arr);
    for (i = n-1; i > 0; i--)
    { 
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        ajusta_heap(i, arr, 0);
    }
}

