#include "caixa.h"
#include <stdio.h>

int main ()
{
    Caixa *c2 = criar_caixa(1, 3, 2);
    
    exibir_caixa(c2);
    area_caixa(c2);
    volume_caixa(c2);

    liberar_caixa(c2);

    exibir_caixa(c2);
    area_caixa(c2);
    volume_caixa(c2);

}