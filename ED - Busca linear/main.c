#include <stdio.h>
#include "busca_l.h"

int main()
{
    int tamanho = 5;
    int valor = 4;
    Vetor *v = cria_vetor(tamanho);
    int pos = busca_linear(tamanho, v, valor);
    if (pos == -1)
        printf("O valor nao foi encontrado no vetor!\n");
    else
        printf("O valor procurado esta na posicao %d do vetor!\n", pos);

    int numero_ocorrencias = num_ocorrencias(tamanho, v, valor);
    if (numero_ocorrencias == -1)
        printf("Nao foram observadas ocorrencias do valor dentro do vetor!\n");
    else    
        printf("O numero de ocorrencias do valor buscado eh de: %d\n", numero_ocorrencias);

    int ultima_ocorrencia = ult_ocorrencia(tamanho, v, valor);
    if (ultima_ocorrencia == -1)
        printf("Nao foram observadas ocorrencias do valor dentro do vetor!\n");
    else
        printf("A ultima ocorrencia do valor buscado eh na posicao %d do array!\n", ultima_ocorrencia);

    maior_menor(v, tamanho);

    int novo_valor = 400;
    atualiza(v, tamanho, valor, novo_valor);
}