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


avltree *rotateRight(avltree *avltree) 
{
  avltree *x = avltree->esq;
  avltree *T2 = x->dir;

  x->dir = avltree;
  avltree->esq = T2;

  return x;
}

avltree *insertNode(avltree *avltree, int dado) 
{
  if (avltree == NULL) 
    {
      avltree *node = (avltree *)malloc(sizeof(avltree));
      node->dado = dado;
      node->esq = NULL;
      node->dir = NULL;
      return node;
    }

  if (dado < avltree->dado)
      avltree->esq = insertNode(avltree->esq, dado);
  else if (dado > avltree->dado)
      avltree->dir = insertNode(avltree->dir, dado);
  else
      return avltree;

  int balance = balancingFactor(avltree);

  if (balance > 1 && dado < avltree->esq->dado)
      return rotateRight(avltree);

  if (balance < -1 && dado > avltree->dir->dado)
      return rotateLeft(avltree);

  if (balance > 1 && dado > avltree->esq->dado) 
    {
      avltree->esq = rotateLeft(avltree->esq);
      return rotateRight(avltree);
    }

  if (balance < -1 && dado < avltree->dir->dado) 
    {
      avltree->dir = rotateRight(avltree->dir);
      return rotateLeft(avltree);
    }

  return avltree;
}




avltree *deleteNode(avltree *avltree, int key) 
{
  if (avltree == NULL)
    return avltree;

  if (key < avltree->dado)
    avltree->esq = deleteNode(avltree->esq, key);
  else if (key > avltree->dado)
    avltree->dir = deleteNode(avltree->dir, key);
  else 
    {
      if ((avltree->esq == NULL) || (avltree->dir == NULL)) 
        {
          AVLTree *temp = avltree->esq ? avltree->esq : avltree->dir;
          if (temp == NULL) 
            {
              temp = avltree;
              avltree = NULL;
            } 
          else
            *avltree = *temp;
          free(temp);
        } 
      else 
        {
          avltree *temp = minValueNode(avltree->dir);
          avltree->dado = temp->dado;
          avltree->dir = deleteNode(avltree->dir, temp->dado);
        }
    }

  if (avltree == NULL)
      return avltree;

  int balance = balancingFactor(avltree);

  if (balance > 1 && balancingFactor(avltree->esq) >= 0)
      return rotateRight(avltree);

  if (balance > 1 && balancingFactor(avltree->esq) < 0) 
    {
      avltree->esq = rotateLeft(avltree->esq);
      return rotateRight(avltree);
    }

  if (balance < -1 && balancingFactor(avltree->dir) <= 0)
      return rotateLeft(avltree);

  if (balance < -1 && balancingFactor(avltree->dir) > 0) 
    {
      avltree->dir = rotateRight(avltree->dir);
      return rotateLeft(avltree);
    }
  return avltree;
}

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