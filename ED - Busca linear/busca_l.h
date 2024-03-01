#ifndef BUSCA_L
#define BUSCA_L

typedef struct vetor Vetor;

void cria_vetor(int qtd_elementos, Vetor);
void exibe_vetor(int vetor[]);
int busca_linear(int tamanho, int vetor[], int valor);


#endif