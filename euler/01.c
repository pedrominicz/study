#include <stdio.h>

/*

If we list all the natural numbers below 10 that are multiples of 3 or 5, we
get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

*/

int entrada = 1000;

int main(void) {
  int x = entrada - 1;

  int soma_total = 0;

  while (x > 0) {
    if ((x % 3 == 0) || (x % 5 == 0)) {
      soma_total = soma_total + x;
    }
    x = x - 1;
  }

  printf("%d\n", soma_total);

  return 0;
}
