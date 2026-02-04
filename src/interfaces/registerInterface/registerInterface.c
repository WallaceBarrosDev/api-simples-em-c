#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../interfaces.h"
#include "../structs.h"
#include "../../services/registerService.h"
#include "registerInterface.h"
#include "../../api/api.h"

void nameRegisterInterface(char *);
void emailRegisterInterface(char *);
void passwordRegisterInterface(char *);

void registerInterface(void) {
  User *user = malloc(sizeof(User));
  
  clearScreen();
  card("Cadastre-se");

  nameRegisterInterface(user->name);
  emailRegisterInterface(user->email);
  passwordRegisterInterface(user->password);

  createUser(user);

  free(user);
}
void nameRegisterInterface(char *name) {
  printf("+----------------------+\n");
  printf("| %-20.20s |\n| %-20.20s |\n", "Digite o nome", ">");
  printf("+----------------------+\n");
  printf("\033[2A\033[4C");
  scanf("%s", name);
}

void emailRegisterInterface(char *email) {
  bool emailIsValid = false;

  while(!emailIsValid) {
    printf("+----------------------+\n");
    printf("| %-20.20s |\n| %-20.20s |\n", "Digite o email", ">");
    printf("+----------------------+\n");
    printf("\033[2A\033[4C");
    scanf("%s", email);
    emailIsValid = validateRegisterEmail(email);

    if(!emailIsValid) card("Email invalido!");
  }
}

void passwordRegisterInterface(char *password) {
  bool passwordIsValid = false;

  while(!passwordIsValid) {
    printf("+----------------------+\n");
    printf("| %-20.20s |\n| %-20.20s |\n", "Digite a senha", ">");
    printf("+----------------------+\n");
    printf("\033[2A\033[4C");
    scanf("%s", password);
    passwordIsValid = validateRegisterPassword(password);

    if(!passwordIsValid) card("Senha muito curta!");
  }
}
