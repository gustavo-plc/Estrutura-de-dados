#include <stdio.h>
#include "busca_l.h"

int main()
{
    int tamanho = 6;
    int valor = 5;
    Vetor *v = cria_vetor(tamanho);
    int pos = busca_linear(tamanho, v, valor);
    if (pos == -1)
        printf("O valor nao foi encontrado no vetor!\n");
    else
        printf("O valor procurado esta na posicao %d do vetor!\n", pos);

    int numero_ocorrencias = num_ocorrencias(tamanho, v, valor);
    printf("O numero de ocorrencias do valor buscado eh de: %d\n", numero_ocorrencias);

    int ultima_ocorrencia = ult_ocorrencia(tamanho, v, valor);
    printf("A ultima ocorrencia do valor buscado eh na posicaoo %d do array!\n", ultima_ocorrencia);

    maior_menor(v);
}