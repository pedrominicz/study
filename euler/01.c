#include <stdio.h>

/*

If we list all the natural numbers below 10 that are multiples of 3 or 5, we
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

int f0(int entrada) {
  int x = entrada - 1;

  int soma_total = 0;

  while (x > 0) {
    if ((x % 3 == 0) || (x % 5 == 0)) {
      soma_total = soma_total + x;
    }
    x = x - 1;
  }

  return soma_total;
}

int f1(int entrada) {
  int x = entrada - 1;
  int y = 0;

  do {
    if ((x % 3 == 0) || (x % 5 == 0)) {
      y = y + x;
    }
    x = x - 1;
  } while (x > 0);

  return y;
}

int f2(int entrada) {
  int x;
  int y = 0;
  int z;

  x = entrada;
  z = x - 1;

  for (x = z; x > 0; x = x - 1) {
    if ((x % 3 == 0) || (x % 5 == 0)) {
      y = y + x;
    }
  }

  return y;
}

int main(void) {
  for (int i = 0; i <= 10000; ++i) {
    int x0 = f0(i);
    int x1 = f1(i);
    int x2 = f2(i);
    if (x0 != x1) printf("f1(%d) = %d\n", i, x1);
    if (x0 != x2) printf("f2(%d) = %d\n", i, x2);
  }

  printf("%d\n", f0(1000));

  return 0;
}
