#include <stdlib.h>
#include "abtracoes.h"


//criar nó
No *criarNo(int dado)
{
    No *no = malloc(sizeof(No));
    if(no) //no != NULL
    {
        no->dado = dado;
        no->prox = NULL;
    }
    return no;
}

Lista *criarLista() //cria uma lista vazia
{
    Lista *lista = malloc(sizeof(Lista)); //ou retorna NULL ou retorna um endereço de memória
    if(lista) //no != NULL
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->length = 0;
    }
    return lista;
}

void listar(Lista *lista)
{
    if(lista->inicio == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }
    No *atual = lista->inicio; // o início da lista é atribuída ao nó atual criado
    while(atual != NULL)
    {
        printf("(%d)->", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void inserirInicio(Lista *lista, int dado)  //inserir o primeiro elemento da lista
{ //uma lista é composta de vários nós
    if(!lista)
        return;
    No *novo = criarNo(dado);
    novo->dado = dado;
    if(!novo)
        return;
    novo->prox = lista->inicio;  // o novo nó apontará para o início antigo, pois o novo nó está agora antes dele.
    lista->inicio = novo; //o início da lista é atualizado com o endereço do novo nó criado.
    if(lista->fim == NULL)  //para verificar se a lista é vazia, se trata-se de uma primeira inserção.
    //caso seja o primeiro elemento, o ponteiro fim também deve ser atualizado
        lista->fim = novo; 
    lista->length++;
}

void inserirFim(Lista lista, int dado)  // terminar de fazer com base no código anterior mmm
{
    if(!lista)
        return;
    No *novo_fim = criarNo(dado);
    if(!novo_fim)
        return;
   
    if(lista->fim == NULL)  //para verificar se a lista é vazia
    {
        lista->fim = novo_fim; // atualiza o fim da lista para o novo nó criado, já que estou atualizando no fim
        lista->inicio = novo_fim;
    }

    
        lista->inicio = novo_fim; 
    lista->length++;
}