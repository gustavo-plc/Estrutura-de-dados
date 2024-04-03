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


void enfileira(Lista *fila, int dado)
{
    if(!fila)
        return;
    No *novo = criarNo(dado);
    if(!novo)
        return;

    if(fila->fim == NULL)  //para verificar se a lista é vazia
    {
        fila->fim = novo;
        fila->inicio = novo;
        fila->length++;
        return;
    }
    No *antigo_fim = fila->fim; 
    antigo_fim->prox = novo;
    fila->fim = novo; 
    fila->length++;
}

/*Enfileira
ini                  fim
\/                   \/
(p1)->   ... (p8)-> (p9) -> NULL
*/



No *desenfileira(Lista *fila) // FIFO: ou seja, sai o primeiro da fila, pois é uma fila!
{
    if(!fila)
        return NULL;
    if(fila->fim == NULL)  //para verificar se a lista é vazia
    {
        printf("Não há elementos para remover!\n");
        return NULL;
    }
    No *novo = fila->inicio;
    fila->inicio = novo->prox;
    fila->length--;
    return fila->inicio;
}

/*Desenfileira
ini                  fim
\/                   \/
(p2)->   ... (p8)-> (p9) -> NULL
retorna: p1
*/

void push(Lista *pilha, int dado)  //LIFO na pilha, exclusões e inclusões são feitas em uma única extermidade, ou seja, no final da lista.
//se estou inserindo um dado, ele "entra" na pilha na forma de nó.
//Portanto, devo criar um nó!
{
    if(!pilha)
        return;
    No *novo = criarNo(dado);
    
    if(pilha->fim == NULL)  //para verificar se a pilha está vazia
    {
        pilha->inicio = novo;
        pilha->fim = novo;
        pilha->length++;
    }
    No *antigo_inicio = pilha->inicio;
    pilha->inicio = novo;
    novo->prox = antigo_inicio;
    pilha->length++;
}

/*Push
topo
\/
(p1) -> NULL
*/

//push(pilha, p2)
//{

//}

/*Push
topo
\/
(p2) -> (p1) -> NULL
*/

//push(pilha, p3)
//{

//}

/*Push
topo
\/
(p3) -> (p2) -> (p1) -> NULL
*/

// No *pop(Lista *pilha)
// {
//     if(!pilha)
//         return NULL;
//     No *novo = pilha->inicio;
//     pilha->inicio = novo->prox;
//     pilha->length--;
//     return novo;
// }

/*Pop
topo
\/
(p2) -> (p1) -> NULL
retorna: p3
*/

// RESOLUÇÃO DA LISTA 5

void inserirOrdenado(Lista *lista, int dado)
{
    if (!lista)
        return;

    No *novo = criarNo(dado);
    if (!novo)
        return;

    No *anterior = NULL;
    No *atual = lista->inicio;

    while (atual != NULL && atual->dado < dado) 
    {
        anterior = atual; //percorre-se a lista, atualizando o nó atual e anterior.
        atual = atual->prox;
    }

    if (anterior == NULL) // caso em que a inserção é no início
    { 
        lista->inicio = novo; // o início da lista será o novo nó
        if (atual == NULL) // só atualiza o fim se o if interno também for NULL
            lista->fim = novo; // o fim da lista também aponta para o novo nó
    } 
    else 
    { 
        anterior->prox = novo; // inserção no meio
        if (atual == NULL) // ao chegar no último nó, o atual será NULL, porque ali em cima ele recebe o atual->prox(NULL)
            lista->fim = novo; //insere o novo nó no final da lista.
    }

    novo->prox = atual; //aponta o novo nó para o nó posterior. 
    lista->length++; // incremento do tamanho da lista
}

void deletarInicio(Lista *lista)
{
    if(!lista)
        return;
    No *aux = lista->inicio->prox;
    lista->inicio = aux;
    lista->length--;
}

void deletarFim(Lista *lista)
{
    if(!lista)
        return;
    if(lista->length == 0)
    {
        printf("\nLista vazia, impossível deletar!\n");
        return;
    }
    if(lista->length == 1)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->length--;
        return;
    }
    No *aux = lista->inicio;
    No *anterior = NULL;
    while(aux->prox != NULL)
    {
        anterior = aux;
        aux = aux->prox; 
    }
    anterior->prox = NULL;
    lista->fim = anterior;
    lista->length--;
}

int topo(Pilha *pilha)
{
    if(!pilha)
        return -1;
    if(pilha->length == 0)
    {
        printf("\nPilha vazia!\n");
        return -1;
    }
    printf("\nO dado do topo eh: %d\n", pilha->topo->dado);
    return pilha->topo->dado;
}

void listarPilha(Pilha *pilha)
{
    if(pilha->topo == NULL)
    {
        printf("\nPilha vazia!\n");
        return;
    }
    No *atual = pilha->topo; // o início da lista é atribuída ao nó atual criado
    while(atual != NULL)
    {
        printf("(%d)->", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n"); 
}

Pilha *criarPilha() 
{
    Pilha *pilha = malloc(sizeof(Pilha)); //ou retorna NULL ou retorna um endereço de memória
    if(pilha) //no != NULL
    {
        pilha->topo = NULL;
        pilha->length = 0;
    }
    return pilha;
}

void empilha(Pilha *pilha, uint dado)
{
    if(!pilha)
        return;
    No *novo = criarNo(dado);
    if(pilha->length == 0)
    {
        pilha->topo = novo;
        novo->prox = NULL;
        pilha->length++;
        return;
    }
    novo->prox = pilha->topo; // o novo nó apontará (novo->prox) para o atual topo (pilha->topo), pois será inserido em cima dele. 
    pilha->topo = novo; // atualização do novo topo para apontar para o novo nó
    pilha->length++;
}

int pop(Pilha *pilha) //desempilha / deleta o nó do topo da pilha e retorna o seu valor, ou -1, caso a pilha esteja vazia
{
    if(!pilha)
        return -1;
    if(pilha->length == 0)
    {
        printf("\nPilha vazia!\n");
        return -1;
    }
    No *aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    pilha->length--;
    printf("\nO dado do topo eh: %d\n", aux->dado);
    return aux->dado;
}



