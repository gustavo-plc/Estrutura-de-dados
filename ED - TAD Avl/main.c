#include <stdio.h>
#include <stdlib.h>

// #include "../includes/TADAVL.h"

struct AVLTree {
  AVLTree *esq;
  AVLTree *dir;
  int dado;
  void (*show)(AVLTree *avltree);
};

typedef struct AVLTree avltree;

void exibir(avltree *avltree) {
  if(avltree) printf("(%d)", avltree->dado);
}

avltree *novaArvore(int dado) {
  avltree *raiz = malloc(sizeof(avltree));
  if(raiz) {
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->dado = dado;
    raiz->show = exibir;
  }
  return raiz;
}

// a serem implementados
int balancingFactor(avltree *avltree)
{
    if(!avltree)
        return 0;
    return height(avltree->esq) - height(avltree->dir);
}

//          (1)
//     (3)       (5)
//  (7)   (9) (11)  (13)

unsigned int height(avltree *avltree)
{
    if(!avltree)
        return 0;
    int alt_esq = height(avltree->esq);
    int alt_dir = height(avltree->dir);
    if (alt_esq > alt_dir)
        return alt_esq+1;
    else
        return alt_dir+1;
}


avltree *rotateLeft(avltree *avltree)
{
  if(!avltree)
    return NULL;
  if((balancingFactor(avltree) == -2) && (avltree->dir->dir != NULL))
    {
      avltree *novo = avltree;
      avltree = avltree->dir;
      novo->dir = avltree->esq;
      avltree->esq = novo;
      return avltree;
    }
}



avltree *rotateRight(avltree *avltree);
avltree *insertNode(avltree *avltree, int dado);
avltree *deleteNode(avltree *avltree, int dado);

// exibir
void preOrder(avltree *avltree);
void inOrder(avltree *avltree);
void posOrder(avltree *avltree);

int main() {
  avltree *raiz = novaArvore(5);
  raiz->esq = novaArvore(3);
  raiz->dir = novaArvore(7);
  raiz->show(raiz);
  raiz->esq->show(raiz->esq);
  raiz->dir->show(raiz->dir);
  
  return 0;
}