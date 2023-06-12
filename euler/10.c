#include <stdio.h>
#include <stdbool.h>

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

int main(void) {
  long int x = 0;
  long int y = 2000000;
  for (long int z = 0; z < y; ++z) {
    if (is_prime(z)) {
      x = x + z;
    }
  }
  printf("%ld\n", x);
  return 0;
}
