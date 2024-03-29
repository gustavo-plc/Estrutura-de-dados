#include <stdio.h>
#include "busca_l.h"

int main()
{
    int tamanho = 5;
    int valor = 5;
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
    for (int i = 0; i < tamanho; i++)
        printf("O valor do indice %d do vetor eh %d\n", i, v->vetor[i]);

    int busca = buscaBinaria(v, tamanho, valor);
    if (busca == -1)
        printf("Algoritmo de busca nao realizou divisoes no array!\n");
    else
        printf("Algoritmo de busca realizou %d divisoes no array!\n", busca);

    int busca_linear_v2 = busca_linearv2(tamanho, v, valor);
    if (busca_linear_v2 == -1)
        printf("Valor nao encontrado no array!\n");
    else
        printf("Valor encontrado na posicao %d do array!\n", busca_linear_v2);

    int valor_usuario;
    printf("Insira um valor: \n");
    scanf("%d", &valor_usuario);
    int resultado = buscaProxima(v, tamanho, valor_usuario);
    printf("O valor do array mais proximo do valor fornecido pelo usuario eh o %d\n", resultado);
}