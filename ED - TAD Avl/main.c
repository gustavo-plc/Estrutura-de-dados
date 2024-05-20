#include "../includes/TADAVL.h"

struct avltree {
  AVLTree *esq;
  AVLTree *dir;
  int dado;
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