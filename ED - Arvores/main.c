#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int dado;
  struct no *esq;
  struct no *dir;
} No;

No *criar_no(int dado) {
  No *no = malloc(sizeof(No));
  if(no) { // no != NULL
    no->dado = dado;
    no->esq = NULL;
    no->dir = NULL;
  }
  return no;
}

void exibir_pre_ordem(No *arvore) {
  if(arvore) { // no != NULL
    printf("(%d)", arvore->dado);
    exibir_pre_ordem(arvore->esq);
    exibir_pre_ordem(arvore->dir);
  }
}

void exibir_nos_folha(No *arvore) {
  
}

void exibir_nos_internos(No *arvore) {
  
}

int main(void) {
  //       (1)
  //   (2)     (3)
  // (4) (5) (6) (7)
  No *raiz = criar_no(1);
        raiz->esq = criar_no(2);
          raiz->esq->esq = criar_no(4);
          raiz->esq->dir = criar_no(5);
        raiz->dir = criar_no(3);
          raiz->dir->esq = criar_no(6);
          raiz->dir->dir = criar_no(7);
  exibir_pre_ordem(raiz);
  return 0;
}