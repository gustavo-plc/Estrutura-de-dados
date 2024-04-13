#include <stdio.h>
#include "busca_b.h"

int main()
{
    int tamanho = 200;
    int valor = 30;
    Vetor *v = cria_vetor(tamanho);
    

    int busca = buscaBinaria(v, tamanho, valor);
    if (busca == -1)
        printf("Algoritmo de busca nao realizou divisoes no array!\n");
    else
        printf("Algoritmo de busca realizou %d divisoes no array!\n", busca);

}