#ifndef BUSCA_L
#define BUSCA_L

typedef struct vetor Vetor;

Vetor *cria_vetor(int qtd_elementos);
int busca_linear(int tamanho, Vetor *vetor, int valor);
int num_ocorrencias(int tamanho, Vetor *vetor, int valor);
int ult_ocorrencia(int tamanho, Vetor *vetor, int valor);
void maior_menor(Vetor *vetor);
void atualiza(Vetor *vetor, int tamanho, int valor_busca, int novo_valor);

#endif