#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interfaces.h"

int initInterface() {
  int option;

  printf("+----------------------+\n");
  printf("| %-22s |\n", "Selecione uma opção");
  printf("+----------------------+\n");
  printf("| %-20.20s |\n| %-20.20s |\n| %-20.20s |\n| %-20.20s |\n", "[1] Login", "[2] cadastre-se", "[3] Sair", "|>");
  printf("+----------------------+\n");
  printf("\033[2A\033[5C");
  scanf("%d", &option);

  return option;
}

void finishInterface() {
  card("Ate logo ...");
  exit(0);
}

void clearScreen() {
  printf("\033[2J\033[1H");
}

void card(const char *msg) {
    const int width = 20;
    int len = strlen(msg);

    printf("+----------------------+\n");

    for (int i = 0; i < len; i += width) {
        printf("| %-20.20s |\n", msg + i);
    }

    printf("+----------------------+\n");
}

