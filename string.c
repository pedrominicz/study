#include <stdio.h>
#include <string.h>

// Em C, quando se fala "string", não é uma "string" como em Python, etc.
// Em C, quando se fala "string", é simplesmente uma sequencia de caracteres com
// um "zero" no final.

// Em outras linguagens de programação, uma "string" normalmente é uma sequencia
// de caracteres *e* um número que é o tamanho da string.

int main(void) {
  char nomes[100][5] = {0};

  for (int i = 0; i < 5; ++i) {
    scanf("%s", nomes[i]);
  }

  char query[100];
  // Em C, quando vc passa uma array (e.g. char[100]) para uma função, o próprio C
  // automaticamente converte a array pra um ponteiro (char*) para o primeiro elemento
  // da array.
  scanf("%s", query);
  for (int i = 0; i < 5; ++i) {
    if (strcmp(query, nomes[i]) == 0) {
      printf("found\n");
    }
  }

  return 0;
}
