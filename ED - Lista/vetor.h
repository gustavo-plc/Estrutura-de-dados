#ifndef VETOR_H
#define VETOR_H

typedef struct vetor Vetor;

Vetor *criarVetor(int limit);
void liberarVetor(Vetor *v);
void listar(Vetor *v);
void zerar(Vetor *v); // basta definir lenght como zero
void inserir(Vetor *v, int dado); // o dado é inserido no índice em que está o length do vetor. Caso length seja igual ao limite, a inserção nao pode ser realizada.
void atualizarUm(Vetor *v, int dadoAntigo, int dadoNovo);
void atualizarTodos(Vetor *v, int dadoAntigo, int dadoNovo);
void atualizarIndice(Vetor *v, int indice, int dadoNovo);
int buscarElemento(Vetor *v, int elemento);
int obterElemento(Vetor *v, int indice);
int deletarElemento(Vetor *v, int indice);
int deletarIndice(Vetor *v, int indice);

#endif // VETOR_H