#include <stdio.h>
#include <stdlib.h>

typedef struct no_avl NoAVL;
struct no_avl {
int dado;
NoAVL *esq;
NoAVL *dir;
};

NoAVL *criar_no(int dado) {
  NoAVL *no_avl = malloc(sizeof(NoAVL));
  if(no_avl) { // no != NULL
    no_avl->dado = dado;
    no_avl->esq = NULL;
    no_avl->dir = NULL;
  }
  return no_avl;
}

void exibir_pre_ordem(NoAVL *arvore) {
  if(arvore) { // no != NULL
    printf("(%d)", arvore->dado);
    exibir_pre_ordem(arvore->esq);
    exibir_pre_ordem(arvore->dir);
  }
}

void exibir_nos_folha(NoAVL *arvore) {
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

void exibir_nos_internos(NoAVL *arvore) {
    if(arvore) { // no != NULL
        if(!(arvore->esq == NULL && arvore->dir == NULL))
            printf("(%d)", arvore->dado);
    exibir_nos_internos(arvore->esq);
    exibir_nos_internos(arvore->dir);
    }
}

void inserir_ordenado(NoAVL *arvore, int dado)
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

int maior(int a, int b) {
    return (a > b) ? a : b;
}

int altura(NoAVL *arvore) {
    if (!arvore) return -1; // nó inválido, retorna -1.
    int alturaEsq = altura(arvore->esq);
    int alturaDir = altura(arvore->dir);
    return maior(alturaEsq, alturaDir) + 1;
}
  //       (1)
  //   (3)     (5)
  // (7) (9) (11) (13)

int fb(NoAVL *arvore)

{
  return altura(arvore->esq) + 1 - (altura(arvore->dir) + 1);
}

// rota_esquerda(no_avl)
// {
//   if(!no_avl)
//     return;
//   no_avl->esq->dir = no_avl;
//   no_avl = no_avl->dir;
// }


NoAVL *rotacionar_dir(NoAVL *arvore)
{
  if(!arvore)
    return NULL;
  if(!arvore->esq)
    return arvore;
  NoAVL *esq = arvore->esq;
  NoAVL *aux = esq->dir;
  esq->dir = arvore;
  arvore->esq = aux;
  return esq;
}

int main(void) {
  //       (1)
  //   (3)     (5)
  // (7) (9) (11) (13)
  NoAVL *raiz = criar_no(1);
        raiz->esq = criar_no(3);
          raiz->esq->esq = criar_no(7);
          raiz->esq->dir = criar_no(9);
        raiz->dir = criar_no(5);
          raiz->dir->esq = criar_no(11);
          raiz->dir->dir = criar_no(13);
  // exibir_pre_ordem(raiz);
  // printf("\n");
  // exibir_nos_folha(raiz);
  // printf("\n");
  // exibir_nos_internos(raiz);
  // printf("\n");

  // inserir_ordenado(raiz, 8);

  // exibir_pre_ordem(raiz);
  // printf("\n");
  // exibir_nos_folha(raiz);
  // printf("\n");
  // exibir_nos_internos(raiz);
  // printf("\n");

  printf("a altura eh: %d",altura(raiz));

  return 0;
}