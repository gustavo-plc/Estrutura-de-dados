#ifndef ENCA_H
#define ENCA_H

typedef struct no No;

struct no
{
    int dado;
    struct no *prox;
};

No *criarNo(int dado);

void listar(No *inicio);

void listarV2(No *inicio);

No *inserirInicio(No **inicio, int dado);

No *inserirFim(No **inicio, int dado);

/*
void inserirFim(No *inicio, int dado);

void listar_for(No *inicio); //(Utilizando laço for)
No *deletar_inicio(No *inicio);
void deletar_fim(No *inicio);
void deletar(No *inicio, int dado);*/

#endif // ENCA_H