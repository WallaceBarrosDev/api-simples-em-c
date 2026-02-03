#include <stdio.h>
#include <stdlib.h>

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
  printf("+----------------------+\n");
  printf("| %-20.20s |\n", "Fim do programa ...");
  printf("+----------------------+\n");
  exit(0);
}

void clearScreen() {
  printf("\033[2J\033[1H");
}
