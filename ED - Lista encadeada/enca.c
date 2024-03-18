#include <stdlib.h>

//linterface (protótipo)
typedef struct no No;

struct no
{
    int dado;
    struct no *prox;
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



void listar(No *inicio)
{
    No *no = inicio; 
    while (no != NULL) 
    {
        printf(" (%d)->", no->dado);
        no = no->prox;
    }
    printf("NULL\n");
}


void inserirInicio(No *inicio, int dado)
{
    if(!inicio) 
        return;
    No *novo_inicio = criar_no (dado);
    if(!novo inicio) 
        return;
    novo_inicio->prox = inicio;
    return novo_inicio;
}

void inserirInicioV2(No **inicio, int dado) //dois asteriscos, acessa-se o nó
{
    if(!inicio) 
        return;
    No *novo_inicio = criar_no (dado);
    if(!novo inicio) 
        return;
    novo_inicio->prox = *inicio;
    *inicio = novo_inicio;
}


void inserirFim(No *inicio, int dado)
{
    No *ant = NULL;
    No *atual = inicio;
    while (atual != NULL) 
    { 
        ant = atual;
        atual = atual->prox;
    }
    No *novo_no = criar_no(dado); 
    ant->prox = novo_no;
}


void inserirFimV3(No **inicio, int dado)
{
    No *no = *inicio;
    No *novo_no = criarNo(dado);
    if (no == NULL)
    {
        *inicio = novo_no;
        return;
    }
    while (no->prox == NULL)
    {
        no = no->prox;
    }
    no->prox = novo_no;
}


void listar_for(No *inicio) 
{ 
    for (No *no = inicio; no != NULL; no = no->prox)   //LISTANDO COM FOR
    
        printf(" (%d)->", ptr_no->dado); ptr_no = ptr_no->prox;
        printf("NULL\n");
    
}



No *deletar_inicio(No *inicio)
{

}


void deletar_fim(No *inicio)
{

}


void deletar(No *inicio, int dado)
{

}