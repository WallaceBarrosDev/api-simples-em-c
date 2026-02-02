#include <stdio.h>
#include <stdlib.h>

int initInterface() {
  int option;

  printf("+----------------------+\n");
  printf("| %-22s |\n", "Selecione uma opção");
  printf("+----------------------+\n");
  printf("| %-20.20s |\n| %-20.20s |\n| %-20.20s |\n", "[1] Login", "[2] Sair", "|>");
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

void loginInterface() {
  char username[100];

  printf("\n+----------------------+\n");
  printf("| %-20.20s |\n", "Logue com o usuario");
  printf("+----------------------+\n");
  printf("| %-20.20s |\n| %-20.20s |\n", "Digite o usuario", ">");
  printf("+----------------------+\n"); 
  printf("\033[2A\033[4C");
  scanf("%s", username);

  printf("+----------------------+\n"); 
  printf("| %-20.20s |\n| %-20.20s |\n", "Digite a senha", ">");
  printf("+----------------------+\n"); 
  printf("\033[2A\033[4C");
  scanf("%s", username);
  printf("+----------------------+\n");
}

