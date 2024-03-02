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
    printf("O número de ocorrências do valor buscado é de: %d\n", numero_ocorrencias);

    int ultima_ocorrencia = ult_ocorrencia(tamanho, v, valor);
    printf("A última ocorrências do valor buscado é na posição %d do array!\n", ultima_ocorrencia);

    int maior_menor(v);
}