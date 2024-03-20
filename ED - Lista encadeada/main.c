int main()
{
    // -- CRIANDO NÓS E JÁ ENCADEANDO --

    //primeira etapa: é criado um primeiro nó (com dado e endereço do próximo, que no caso é NULL)
    No *inicio = criarNo(1);

    //segunda etapa: é criado um segundo nó, com dado e o endereço do próximo, que no caso é NULL),
    //mas o endereço desse nó recém criado (retorno da função criarNO) vai ser armazenado 
    //na parte de endereço do nó inicio. Ou seja, o nó inicio irá apontar para o segundo nó criado. 

    inicio->prox = criarNo(2); //ao atributo próx da estrutura do ponteiro início (ponteiro para Nó), é atribuído o retorno da função criarNo, 
    //que retorna o endereço do nó criado pelo malloc

    //terceira etapa: será criado um novo nó por meio da função criarNo e seu retorno (endereço do nó criado) será armazenado no atributo prox do atributo próx do nó início.
    inicio->prox->prox = criarNo(3); //o início, como uma variável do tipo nó, possui duas partes, uma de dados e outra que é um ponteiro do tipo Nó (estrutura de Nó) que 
    //por sua vez tem também duas partes: o campo de dados e um ponteiro do tipo Nó, que por sua vez também tem dois campos: dados e ponteiro
    //Dessa forma, é possível acessar o atributo prox, do atributo próx do nó início.

    
    inicio->prox->prox->prox = criarNo(4);

    /*inicio = criar_no (1);
    // se inicio == NULL
    if(!inicio)
        return 1;

    inicio->prox = criar_no (2);
    // se inicio->prox == NULL
    if(!inicio->prox)
        return 1;

    inicio->prox->prox = criar_no (3);
    // se inicio->prox->prox == NULL
    if(!inicio->prox->prox)
        return 1;

    inicio->prox->prox->prox = criar_no (4); // se inicio->prox->prox->prox == NULL
    if(!inicio->prox->prox->prox)
        return 1;

    No *nova_lista = NULL;
    inserirInicio(&nova_lista, 1);
    inserirInicio(&nova_lista, 2);
    inserirInicio(&nova_lista, 3);

    nova_lista = inserirFim(nova_lista, 1);
    nova_lista = inserirFim(nova_lista, 2);
    nova_lista = inserirFim(nova_lista, 3);


    return 0;
    */
}