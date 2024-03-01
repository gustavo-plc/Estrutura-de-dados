#ifndef BUSCA_L
#define BUSCA_L

typedef struct vetor Vetor;

Vetor *cria_vetor(int qtd_elementos);
int busca_linear(int tamanho, Vetor *vetor, int valor);


#endif