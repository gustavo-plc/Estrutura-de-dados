#ifndef BUSCA_B
#define BUSCA_B

typedef struct vetor Vetor;

Vetor *cria_vetor(int qtd_elementos);

int buscaBinaria(Vetor * vetor, int tamanho, int valor);


#endif