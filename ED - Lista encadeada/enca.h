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

No *inserirFimV2(No **inicio, int dado);

No *deletar_inicio(No *inicio);

#endif // ENCA_H