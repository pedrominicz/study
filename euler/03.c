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

bool is_prime1(long int x) {
  if (x < 2) return false;
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

/*

   se `n` é primo, então só eh div por `n` e 1

   if n == 2 { return true }
   if n % 2 == 0 { return false }

   aqui, se `n` é div por `x` (n % x == 0)

   ser div por `x` == existir um `y` tal que `n * y == x`

   x != n, pq a gente para o `for` antes
   x > n, também pq a gente para o `for` antes

   x * 2 == 2 * x



   exemplo: 1009

   3... não eh div
   5... não eh div
   7... não eh div

   ...

   501... não eh div
   503... não eh div

   505 * 2 == 1010 > 1009

*/

bool is_prime2(long int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (long int odd = 3; odd < x / 2; odd = odd + 2) {
    if (x % odd == 0) {
      return false;
    }
  }
  return true;
}

/*

   continuando o raciocínio

   exemplo: 1009

   3... não eh div
   aqui eu já sei que 1009 não eh div por 3, ou seja, se 1009 for div por x
   então x * y == 1009, y != 2 e y != 3
   5... não eh div
   7... não eh div

   ...

   335... não eh div

   337 * 3 = 1011 > 1009

*/

bool is_prime3(long int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  long int limit = x / 2;
  for (long int odd = 3; odd < limit; odd = odd + 2) {
    if (x % odd == 0) {
      return false;
    }
    limit = x / odd;
  }
  return true;
}

bool is_prime4(long int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  long int limit = x / 2;
  long int odd = 3;
  while (odd < limit) {
    if (x % odd == 0) {
      return false;
    }
    limit = x / odd;
    odd = odd + 2;
  }
  return true;
}

bool is_prime5(long int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  long int odd = 3;
  while (odd < x / (odd - 2)) {
    if (x % odd == 0) {
      return false;
    }
    odd = odd + 2;
  }
  return true;
}

bool is_prime6(long int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  long int odd = 3;
  while (odd * (odd - 2) < x) {
    if (x % odd == 0) {
      return false;
    }
    odd = odd + 2;
  }
  return true;
}

bool is_prime(long int x) {
  if (x < 2) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (long int odd = 3; odd * odd <= x; odd = odd + 2) {
    if (x % odd == 0) {
      return false;
    }
  }
  return true;
}

void test_pos(long int x) {
  if (!is_prime1(x)) printf("error: is_prime1(%ld)\n", x);
  if (!is_prime2(x)) printf("error: is_prime2(%ld)\n", x);
  if (!is_prime3(x)) printf("error: is_prime3(%ld)\n", x);
  if (!is_prime4(x)) printf("error: is_prime4(%ld)\n", x);
  if (!is_prime5(x)) printf("error: is_prime5(%ld)\n", x);
  if (!is_prime6(x)) printf("error: is_prime6(%ld)\n", x);
  if (!is_prime(x)) printf("error: is_prime(%ld)\n", x);
}

void test_neg(long int x) {
  if (is_prime1(x)) printf("error: is_prime1(%ld)\n", x);
  if (is_prime2(x)) printf("error: is_prime2(%ld)\n", x);
  if (is_prime3(x)) printf("error: is_prime3(%ld)\n", x);
  if (is_prime4(x)) printf("error: is_prime4(%ld)\n", x);
  if (is_prime5(x)) printf("error: is_prime5(%ld)\n", x);
  if (is_prime6(x)) printf("error: is_prime6(%ld)\n", x);
  if (is_prime(x)) printf("error: is_prime(%ld)\n", x);
}

void test_is_prime(void) {
  // testar casos positivos
  test_pos(2);
  test_pos(3);
  test_pos(5);
  test_pos(7);
  test_pos(11);
  test_pos(179);
  test_pos(10607);

  // testar casos negativos
  test_neg(-1);
  test_neg(0);
  test_neg(1);
  test_neg(4);
  test_neg(6);
  test_neg(9);
  test_neg(10);
}

long int solution1(long int n) {
  long int result = 0; // maior fator primo

  if (n % 2 == 0) {
    result = 2;
    while (n % 2 == 0) n = n / 2;
  }

  for (long int x = 3; x <= n; x = x + 2) {
    // verificar se x é um divisor de n
    // e verificar se x é primo
    if (n % x == 0 && is_prime(x)) {
      result = x;
    }
  }

  return result;
}

/*

   1000

   1000 % 2 == 0 então 2 eh um divisor
   is_prime(2)   então 2 eh um divisor primo
   maior_por_enquanto = 2

   1000 % 3 != 0

   1000 % 4 == 0
   !is_prime(4)

   1000 % 5 == 0
   is_prime(5)
   maior_por_enquanto = 5



   1000 % 2 == 2000 % 2 == 3000 % 2 == (1000 * x) % 2 == 0
    500 % 2 ==  250 % 2 ==  125 % 2 == 0


   1000

   1000 % 2 == 0
   opa, agora eu posso diminuir meu problema
   1000 -> 500 -> 250 -> 125
   is_prime(2)
   maior_por_enquanto = 2

   125 % 3 != 0

   125 % 4 != 0

   125 % 5 == 0
   opa, agora eu posso diminuir meu problema
   125 -> 25 -> 5
   is_prime(5)
   maior_por_enquanto = 5

   mas agora eu cheguei no meu limite (que eh 5)

*/

long int solution2(long int n) {
  long int result = 0;

  if (n % 2 == 0) {
    result = 2;
    while (n % 2 == 0) n = n / 2;
  }

  for (long int x = 3; x <= n; x = x + 2) {
    if (n % x == 0 && is_prime(x)) {
      result = x;
      while (n % x == 0) n = n / x;
    }
  }

  return result;
}

long int solution3(long int n) {
  long int result = 0;

  if (n % 2 == 0) {
    result = 2;
    while (n % 2 == 0) n = n / 2;
  }

  for (long int x = 3; x <= n; x = x + 2) {
    if (n % x == 0) {
      result = x;
      while (n % x == 0) n = n / x;
    }
  }

  return result;
}

int main(void) {
  test_is_prime();

  printf("%ld\n", solution3(600851475143));
  return 0;
}
