#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../interfaces.h"
#include "../structs.h"
#include "../../services/registerService.h"
#include "registerInterface.h"

void nameRegisterInterface(char *);
void emailRegisterInterface(char *);
void passwordRegisterInterface(char *);

void registerInterface(void) {
  User *user = malloc(sizeof(User));
  clearScreen();

  printf("\n+----------------------+\n");
  printf("| %-20.20s |\n", "Cadastre-se");
  printf("+----------------------+\n");

  nameRegisterInterface(user->name);
  emailRegisterInterface(user->email);
  passwordRegisterInterface(user->password);

  printf("\n+----------------------+\n");
  printf("| %-20.20s |\n", "Cadastro realizado com sucesso!");
  printf("+----------------------+\n");

  free(user);
}
static void nameRegisterInterface(char *name) {
  printf("+----------------------+\n");
  printf("| %-20.20s |\n| %-20.20s |\n", "Digite o nome", ">");
  printf("+----------------------+\n");
  printf("\033[2A\033[4C");
  scanf("%s", name);
}

static void emailRegisterInterface(char *email) {
  bool emailIsValid = false;

  while(!emailIsValid) {
    printf("+----------------------+\n");
    printf("| %-20.20s |\n| %-20.20s |\n", "Digite o email", ">");
    printf("+----------------------+\n");
    printf("\033[2A\033[4C");
    scanf("%s", email);
    emailIsValid = validateRegisterEmail(email);

    if(!emailIsValid) {
      printf("+----------------------+\n");
      printf("| %-20.20s |\n", "Email invalido!");
      printf("+----------------------+\n");
    }
  }
}

static void passwordRegisterInterface(char *password) {
  bool passwordIsValid = false;

  while(!passwordIsValid) {
    printf("+----------------------+\n");
    printf("| %-20.20s |\n| %-20.20s |\n", "Digite a senha", ">");
    printf("+----------------------+\n");
    printf("\033[2A\033[4C");
    scanf("%s", password);
    passwordIsValid = validateRegisterPassword(password);

    if(!passwordIsValid) {
      printf("+----------------------+\n");
      printf("| %-20.20s |\n", "Senha muito curta!");
      printf("+----------------------+\n");
    }
  }
}

