#include <stdio.h>

int main(void) {
  int n = 100;

  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum = sum + i * i;
  }

  int nsum = 0;
  for (int i = 1; i <= n; ++i) {
    nsum = nsum + i;
  }

  int square = nsum * nsum;

  int difference = square - sum;

  printf("%d\n", difference);

  return 0;
}
