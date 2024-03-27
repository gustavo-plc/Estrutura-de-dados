#include <stdlib.h>
#include <stdio.h>
#include "abstracoes.h"


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

Lista *criarFila() //cria uma lista vazia
{
    Lista *fila = malloc(sizeof(Lista)); //ou retorna NULL ou retorna um endereço de memória
    if(fila) //no != NULL
    {
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->length = 0;
    }
    return fila;
}

Lista *criarPilha() //cria uma lista vazia
{
    Lista *pilha = malloc(sizeof(Lista)); //ou retorna NULL ou retorna um endereço de memória
    if(pilha) //no != NULL
    {
        pilha->inicio = NULL;
        pilha->fim = NULL;
        pilha->length = 0;
    }
    return pilha;
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
    if(lista->fim == NULL)  //para verificar se a lista é vazia, se trata-se de uma primeira inserção. Fim da lista
    //e não do nó, até pq o último nó sempre vai apontar para NULL.
    //caso seja o primeiro elemento, o ponteiro fim também deve ser atualizado
        lista->fim = novo; 
    lista->length++;
}

void inserirFim(Lista *lista, int dado)  // terminar de fazer com base no código anterior
{
    if(!lista)
        return;
    No *novo_fim = criarNo(dado);
    if(!novo_fim)
        return;
    if(lista->fim == NULL)  //para verificar se a lista é vazia
    {
        lista->fim = novo_fim; // atualiza o fim da lista para o novo nó criado, já que estou inserindo no fim, o descritor fim da lista apontará para ele.
        lista->inicio = novo_fim; //o início da lista também receberá esse nó, já que ele é o primeiro.
        lista->length++;
        return;
    }
    No *antigo_fim = lista->fim;
    antigo_fim->prox = novo_fim;
    lista->fim = novo_fim; 
    lista->length++;
}

//as funções abaixo usarão a estrutura de lista para representar filas e pilhas.
//ILUSTRAÇÃO INICIAL
/*
ini           fim
\/            \/
(p1)->   ... (p8)-> NULL
*/


enfileira(fila, int dado)
{
    if(!fila)
        return;
    No *novo = malloc(sizeof(No));
    if(!novo)
        return;
    fila->fim
    novo->dado = dado;

}

/*Enfileira
ini                  fim
\/                   \/
(p1)->   ... (p8)-> (p9) -> NULL
*/



No *desenfileira(fila)
{

}

/*Desenfileira
ini                  fim
\/                   \/
(p2)->   ... (p8)-> (p9) -> NULL
retorna: p1
*/

push(pilha, p1)
{

}

/*Push
topo
\/
(p1) -> NULL
*/

push(pilha, p2)
{

}

/*Push
topo
\/
(p2) -> (p1) -> NULL
*/

push(pilha, p3)
{

}

/*Push
topo
\/
(p3) -> (p2) -> (p1) -> NULL
*/

No *pop(pilha)
{

}

/*Pop
topo
\/
(p2) -> (p1) -> NULL
retorna: p3
*/
