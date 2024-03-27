#include "enca.h"

int main()
{
    // -- CRIANDO NÓS E JÁ ENCADEANDO --

    //primeira etapa: é criado um primeiro nó (com dado e endereço do próximo, que no caso é NULL)
    No *inicio = criarNo(1);
    if(!inicio)     //caso a alocação dinâmica tenha falhado ao criar o nó, o ponteiro início receberá NULL.
        return 1;   // e ao receber NULL, ela se torna booleanamente falsa. Esse if(!inicio) testa se o inicio é NULL. Se for, sai da função retornando 1;
    
    //segunda etapa: é criado um segundo nó, com dado e o endereço do próximo, que no caso é NULL),
    //mas o endereço desse nó recém criado (retorno da função criarNO) vai ser armazenado 
    //na parte de endereço do nó inicio. Ou seja, o nó inicio irá apontar para o segundo nó criado. 

    inicio->prox = criarNo(2); //ao atributo próx da estrutura do ponteiro início (ponteiro para Nó), é atribuído o retorno da função criarNo, 
    //que retorna o endereço do nó criado pelo malloc
    if(!inicio->prox)     //caso a alocação dinâmica tenha falhado ao criar o nó, o ponteiro início receberá NULL.
        return 1;

    //terceira etapa: será criado um novo nó por meio da função criarNo e seu retorno (endereço do nó criado) será armazenado no atributo prox do atributo próx do nó início.
    inicio->prox->prox = criarNo(3); //o início, como uma variável do tipo nó, possui duas partes, uma de dados e outra que é um ponteiro do tipo Nó (estrutura de Nó) que 
    //por sua vez tem também duas partes: o campo de dados e um ponteiro do tipo Nó, que por sua vez também tem dois campos: dados e ponteiro
    //Dessa forma, é possível acessar o atributo prox, do atributo próx do nó início.
    if(!inicio->prox->prox)     //caso a alocação dinâmica tenha falhado ao criar o nó, o ponteiro inicio->prox->prox receberá NULL.
        return 1;
    
    
    inicio->prox->prox->prox = criarNo(4);

    if(!inicio->prox->prox->prox)  //com essa disposição dos IFs, a cada criação e encadeamento de nó é feita uma verificação se a alocação dinâmica foi correta.)
        return 1;

    listar(inicio);

    listarV2(inicio);

    inserirInicio(&inicio, 5);

    listarV2(inicio);

    inserirFim(&inicio, 15);

    listar(inicio);

    inserirFim(&inicio, 199);

    listar(inicio);

    deletar_inicio(&inicio); //quando a variável a ser alterada pela função já é um ponteiro, usa-se ponteiro para ponteiro para alterá-la. 

    listar(inicio);

    deletar_fim(&inicio);

    listar(inicio);

    deletar(&inicio, 4);

    listar(inicio);

}
