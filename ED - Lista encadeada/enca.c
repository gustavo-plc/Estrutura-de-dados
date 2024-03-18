#include <stdlib.h>

//linterface (protótipo)
typedef struct no No;

struct no
{
    int dado;
    No *prox; //struct no *prox;
}

no *criarNo(int dado)
{
    No *novo_no = malloc(sizeof(No));
    if(novo_no) //novo_no != NULL
    {
        novo_no->dado = dado;
        novo_no->prox = NULL;
    }
    return novo_no;
}

void listar_for(No *inicio) 
{ 
    for (No *no = inicio; no != NULL; no = no->prox)   //LISTANDO COM FOR
    
        printf(" (%d)->", ptr_no->dado); ptr_no = ptr_no->prox;
        printf("NULL\n");
    
}

void inserirInicio(No *inicio, int dado)
{
    
}
