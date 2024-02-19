// arquivo header, ou seja, cabeçalho, apenas para inserir os protótipos 
// das estruturas que serão usadas e também das funções

#ifndef CALC_H  //escrita do if para definir o cabeçalho apenas quando não estiver definido. Para evitar dupla definição
#define CALC_H

typedef struct calc Calc;

Calc* criaCalc();
void zeraCalc(Calc *c);
void destroiCalc(Calc *c);
void exibeResultado(Calc *c);
Calc* divCalc(Calc *c, float n);
Calc* multCalc(Calc *c, float n);
Calc* subtCalc(Calc *c, float n);
Calc* somaCalc(Calc *c, float n);

#endif  //finalização do IF para definição única do cabeçalho





