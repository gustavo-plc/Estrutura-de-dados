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
  if(arvore) { // no != NULL
        if(arvore->esq == NULL && arvore->dir == NULL)
        {
            printf("(%d)", arvore->dado);
            return;
        }
    exibir_nos_folha(arvore->esq);
    exibir_nos_folha(arvore->dir);
    }
  }

void exibir_nos_internos(No *arvore) {
    if(arvore) { // no != NULL
        if(!(arvore->esq == NULL && arvore->dir == NULL))
            printf("(%d)", arvore->dado);
    exibir_nos_internos(arvore->esq);
    exibir_nos_internos(arvore->dir);
    }
}

void inserir_ordenado(No *arvore, int dado)
{
  if(!arvore) return; // no != NULL
  if (arvore == NULL) 
    {               
      criar_no(dado); //  árvore vazia, o dado é inserido como um novo nó
      return;
    }

  if (dado < arvore->dado) // Se o dado é menor que o dado atual, insere à esquerda
  { 
    if (arvore->esq == NULL) // Se a esquerda é nula, cria um novo nó para inserir o dado
      arvore->esq = criar_no(dado); 
    else   
      inserir_ordenado(arvore->esq, dado);
      
  } 
  else if (dado > arvore->dado) // Se o dado é maior que o dado atual, insere à direita
  {
    if (arvore->dir == NULL)    
      arvore->dir = criar_no(dado);
    else 
      inserir_ordenado(arvore->dir, dado);
  }
}

int altura(No *arvore) {
    if (arvore == NULL) 
    {
      return -1; // árvore vazia
    } 
    else 
    {
      int altura_esq = altura(arvore->esq);
      int altura_dir = altura(arvore->dir);
      int max;
      if (altura_esq > altura_dir) 
        max = altura_esq;
      else
        max = altura_dir;
      return max + 1;
    }
}


int main(void) {
  //       (1)
  //   (2)     (3)
  // (4) (5) (6) (7)
  No *raiz = criar_no(1);
        raiz->esq = criar_no(3);
          raiz->esq->esq = criar_no(7);
          raiz->esq->dir = criar_no(9);
        raiz->dir = criar_no(5);
          raiz->dir->esq = criar_no(11);
          raiz->dir->dir = criar_no(13);
  exibir_pre_ordem(raiz);
  printf("\n");
  exibir_nos_folha(raiz);
  printf("\n");
  exibir_nos_internos(raiz);
  printf("\n");

  inserir_ordenado(raiz, 8);

  exibir_pre_ordem(raiz);
  printf("\n");
  exibir_nos_folha(raiz);
  printf("\n");
  exibir_nos_internos(raiz);
  printf("\n");

  printf("a altura eh: %d",altura(raiz));

  return 0;
}