#include <stdio.h>

int p(int n) {
  // passo recursivo
  if(n > 0) return p(n-1) + 1;
  // critério de parada
  if(n == 0) return 0;
  // n < 0: Exceção
  return 0;
}
//                      i
//    p(n): 0   1   2   3
// Andares: 0 + 1 + 1 + 1
int pIterativo(int n) {
  int andares = 0;
  for(int i = 1; i <= n; i++) {
    andares = andares + 1;
  }
  return andares;
}

int f(int n) {
  printf("fib(%d)\n", n);
  if( n > 1) return f(n-1)+f(n-2); // passo recursivo
  if(n == 1) return 1; // critério de parada
  if(n == 0) return 0; // critério de parada
  // n < 0
  return 0; // exceção
}
// Programação dinâmica
long long fibs[101] = {0};
long long fib(long long n) {
  printf("fib(%lld)\n", n);
  if(fibs[n]) return fibs[n];
  if( n > 1) {
    if(fibs[n-1] == 0) fibs[n-1] = fib(n-1);
    if(fibs[n-2] == 0) fibs[n-2] = fib(n-2);
    return fibs[n-1]+fibs[n-2];
  } ; // passo recursivo
  if(n == 1) return 1; // critério de parada
  if(n == 0) return 0; // critério de parada
  // n < 0
  return 0; // exceção
}

int prod(int n) {
  if(n  > 1) return prod(n-1) * n; // passo recursivo
  if(n == 1) return 1; // critério de parada
  // n < 1
  return 0; // exceção
}

int main() {
  int n;
  printf("introduza o valor de n: ");
  scanf("%d", &n);
  // printf("fib(%d): %lld\n", n, fib(n));
  // printf("fib(%d): %lld\n", n, fib(n));
  printf("prod(%d): %d\n", n, prod(n));
  return 0;
}