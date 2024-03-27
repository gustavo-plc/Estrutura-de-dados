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
        novo_no->prox = NULL; //cria sempre um nó apontando pra NULL
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


void listarV2(No *inicio)  //função recebe o nó de início
{
    for (No *no = inicio; no != NULL/*(condição de continuidade do for)*/; no = no->prox)  //o início do for é feito criando e inicializando uma vriável
    // do tipo nó, com o valor do nó de início. A quantidade de iterações é baseada nos atributos dos nós, pois não 
    //é mais possível contar com os índices de array.  

    //a condição de parada é  o nó ter o endereço NULL, o que indica que a lista chegou ao fim.
    
    //incremento: será atualizado o endereço do nó local (criado dentro do for) com o endereço do próximo nó. Esse é o incremento do for. 
    {
        printf(" (%d)->", no->dado); // imprime o valor do nó
        
    }
    printf("NULL\n");
}



No *inserirInicio(No **inicio, int dado)
{
    if(!(*inicio)) 
        return NULL;
    No *novo_inicio = criarNo(dado); //criação de um nó avulso e atribuição dele à variável local *novo_início
    if(!novo_inicio) 
        return NULL;
    novo_inicio->prox = *inicio;
    *inicio = novo_inicio;
    return novo_inicio;
}


No *inserirFim(No **inicio, int dado)
{
    if(!(*inicio)) 
        return NULL;
    No *novo_fim = criarNo(dado); //criação de um nó avulso e atribuição dele à variável local *novo_fim
    if(!novo_fim) 
        return NULL;
    No *inicio_local = *inicio;
    while((inicio_local->prox) != NULL)
        inicio_local = inicio_local->prox; // para onde o nó está apontando se torna o endereço dele (forma de percorrer a lista encadeada)
    (inicio_local->prox) = novo_fim;
    return novo_fim;
}


No *inserirFimV2(No **inicio, int dado)
{
    if(!(*inicio)) 
        return NULL;
    No *no = *inicio; // criação de um nó local e passagem do nó início para ele
    while(no->prox != NULL)
        no = no->prox; // para onde o nó está apontando se torna o endereço dele (forma de percorrer a lista encadeada)
    No *novo_no = criarNo(dado);
    if(!novo_no)
        return NULL;
    no->prox = novo_no;
    return novo_no;
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
