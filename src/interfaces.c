#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interfaces.h"

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

bool validateEmail(char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
}

bool emailLoginInterface(char *email) {
  printf("| %-20.20s |\n| %-20.20s |\n", "Digite o email", ">");
  printf("+----------------------+\n"); 
  printf("\033[2A\033[4C");
  scanf("%s", email);

  return validateEmail(email);
}

bool validateUser(User *user) {
  return (!strcmp(user->email, "w@w") && !strcmp(user->password, "abc123"));
}

void loginInterface() {
  User *user = malloc(sizeof(User));
  
  printf("\n+----------------------+\n");
  printf("| %-20.20s |\n", "Logue com o usuario");
  printf("+----------------------+\n");
  
  while(!emailLoginInterface(user->email)) {
    printf("\n+----------------------+\n");
    printf("| %-20.20s |\n", "Email invalido!");
    printf("+----------------------+\n");
  };

  printf("+----------------------+\n"); 
  printf("| %-20.20s |\n| %-20.20s |\n", "Digite a senha", ">");
  printf("+----------------------+\n"); 
  printf("\033[2A\033[4C");
  scanf("%s", user->password);
  printf("+----------------------+\n");
  
  if(validateUser(user)) {
    printf("olá %s, seja bem vindo\n", user->email);
    exit(0);
  } else {
    printf("+----------------------+\n"); 
    printf("| %20.20s |\n", "Email ou senha invalido");
    printf("+----------------------+\n"); 
  }
}
