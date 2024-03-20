#include <stdlib.h>
#include <stdio.h>
#include "enca.h"

//linterface (protótipo)
typedef struct no No;


No *criarNo(int dado)
{
    No *novo_no = malloc(sizeof(No));
    if(novo_no) //novo_no != NULL
    {
        novo_no->dado = dado;
        novo_no->prox = NULL;
    }
    return novo_no;
}




void listar(No *inicio)  //função recebe o nó de início
{
    No *no = inicio; //criação de um ponteiro auxiliar que recebe o endereço do nó de início
    while (no != NULL) //enquanto o ponteiro auxiliar não finaliza a lista... faça:
    {
        printf(" (%d)->", no->dado); // imprime o valor do nó
        no = no->prox; //endereço desse nó (que inicialmente é o nó de início) é atualizado para o endereço que consta no atributo prox do nó, ou seja, 
        //o endereço do próximo nó é colocado no endereço do nó atual. Isso faz o ponteiro auxiliar percorrer a lista.
    }
    printf("NULL\n");
}



/*
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

*/