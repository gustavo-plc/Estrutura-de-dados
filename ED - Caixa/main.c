#include "caixa.h"

int main ()
{
    //tentativa de executar funções sobre uma caixa que não está criada para visualizar os erros

    //criação de uma vaiável do tipo caixa para insrir no parâmtro das funções abaixo.
    Caixa *c1;
    liberar_caixa(c1);
    exibir_caixa(c1);
    area_caixa(c1);
    volume_caixa(c1);

    //agora o teste criando a caixa
    Caixa *c2 = criar_caixa(0.3, 0.15, 0.20);
    liberar_caixa(c2);
    exibir_caixa(c2);
    area_caixa(c2);
    volume_caixa(c2);

}