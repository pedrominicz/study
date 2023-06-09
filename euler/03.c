#include <stdio.h>
#include <stdbool.h>

/*

   um número primo só é divisível por um e ele mesmo

   2 div 3? não
   2 div 4? não
   2 div 5? não
   2 div 6? não

   x div x+1? não

   um número não é divisível por nenhum número maior que ele

*/

// esta função ainda está errada...
bool is_prime(long int x) {
  if (x == 2) return true;
  // se eu chegar aqui então x não é igual a dois
  if (x % 2 == 0) {
    // aqui dento x é um número par
    return false;
  }
  // se chegar aqui então x é um número ímpar, ou seja, x - 1 é par
  // para cada ímpar...
  for (long int odd = 3; odd < x; odd = odd + 2) {
    //printf("%ld\n", odd); // eu como programador espero que seja um número ímpar
    //                      // pq tá no nome!
    if (x % odd == 0) {
      return false;
    }
  }
  // se eu chegar aqui então
  // - x não é divisível por 2
  // - x não é divisível por todos os ímpares maiores que 1 e menores que x
  return true;
}

void test_is_prime(void) {
  // testar casos positivos
  if (!is_prime(2)) printf("error!\n");
  if (!is_prime(3)) printf("error!\n");
  if (!is_prime(5)) printf("error!\n");
  if (!is_prime(7)) printf("error!\n");
  if (!is_prime(11)) printf("error!\n");
  if (!is_prime(179)) printf("error!\n");
  if (!is_prime(10607)) printf("error!\n");

  // testar casos negativos
  if (is_prime(4)) printf("error!\n");
  if (is_prime(6)) printf("error!\n");
  if (is_prime(9)) printf("error!\n");
  if (is_prime(10)) printf("error!\n");
}

int main(void) {
  long int result = 0; // maior fator primo
  long int n = 600851475143;

  for (long int x = 3; x <= n; x = x + 2) {
    // verificar se x é um divisor de n
    // e verificar se x é primo
    if (n % x == 0 && is_prime(x)) {
      result = x;
    }
  }
  printf("%ld\n", result);
  return 0;
}
