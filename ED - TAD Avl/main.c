#include <stdio.h>
#include <stdlib.h>

#include "../includes/TADAVL.h"

struct avltree {
  AVLTree *esq;
  AVLTree *dir;
  int dado;
  void (*show)(AVLTree *avltree);
};

void exibir(AVLTree *avltree) {
  if(avltree) printf("(%d)", avltree->dado);
}

AVLTree *novaArvore(int dado) {
  AVLTree *raiz = malloc(sizeof(AVLTree));
  if(raiz) {
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->dado = dado;
    raiz->show = exibir;
  }
  return raiz;
}

// a serem implementados
int balancingFactor(AVLTree *avltree);
unsigned int height(AVLTree *avltree);
AVLTree *rotateLeft(AVLTree *avltree);
AVLTree *rotateRight(AVLTree *avltree);
AVLTree *insertNode(AVLTree *avltree, int dado);
AVLTree *deleteNode(AVLTree *avltree, int dado);

// exibir
void preOrder(AVLTree *avltree);
void inOrder(AVLTree *avltree);
void posOrder(AVLTree *avltree);

int main() {
  AVLTree *raiz = novaArvore(5);
  raiz->esq = novaArvore(3);
  raiz->dir = novaArvore(7);
  raiz->show(raiz);
  raiz->esq->show(raiz->esq);
  raiz->dir->show(raiz->dir);
  
  return 0;
}