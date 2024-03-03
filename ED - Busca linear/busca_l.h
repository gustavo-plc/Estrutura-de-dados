#ifndef BUSCA_L
#define BUSCA_L

struct vetor 
{
    int quantidade;
    int vetor[];
};
typedef struct vetor Vetor;

Vetor *cria_vetor(int qtd_elementos);
int busca_linear(int tamanho, Vetor *vetor, int valor);
int num_ocorrencias(int tamanho, Vetor *vetor, int valor);
int ult_ocorrencia(int tamanho, Vetor *vetor, int valor);
void maior_menor(Vetor *vetor, int tamanho);
void atualiza(Vetor *vetor, int tamanho, int valor, int novo_valor);
int buscaBinaria(Vetor * vetor, int tamanho, int valor);
int busca_linearv2(int tamanho, Vetor *vetor, int valor);
int buscaProxima(Vetor * vetor, int tamanho, int valor);

#endif