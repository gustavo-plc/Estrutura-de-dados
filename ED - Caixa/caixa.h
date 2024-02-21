//arquivo header, somente para cabeçalho das estruturas e operações. Sem detalhar a estrurura e nem as operações.
#ifndef CAIXA_H
#define CAIXA_H

typedef struct caixa Caixa;

Caixa *criar_caixa(float comp, float largura, float altura);
int liberar_caixa(Caixa *c);
int exibir_caixa(Caixa *c);
float area_caixa(Caixa *c);
float volume_caixa(Caixa *c);

#endif