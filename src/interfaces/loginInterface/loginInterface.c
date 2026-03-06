#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../interfaces.h"
#include "../structs.h"
#include "../../services/services.h"

void emailLoginInterface(char *);
void passwordLoginInterface(char *);
bool UserLoginInterface(User *);

void loginInterface() {
  int tryAgain = 1;
  User *user = malloc(sizeof(User));
  
  clearScreen();
  card("Logue com o seu usuário");
  
  while(tryAgain) {
    emailLoginInterface(user->email);
    passwordLoginInterface(user->password);
    if (!UserLoginInterface(user)) {
      card("Tente novamente ? 1 - SIM | 0 - NAO");
      scanf("%d", &tryAgain);
    }
  }

  free(user);
}

void emailLoginInterface(char *email) {
  bool emailIsValid = false;

  while(!emailIsValid) {
    printf("+----------------------+\n");
    printf("| %-20.20s |\n| %-20.20s |\n", "Digite o email", ">");
    printf("+----------------------+\n"); 
    printf("\033[2A\033[4C");
    scanf("%s", email);

    sanitiseEmail(email);
    emailIsValid = validateEmail(email);

    if(!emailIsValid) card("Email invalido!");
  }
}

void passwordLoginInterface(char *password) {
  bool passwordIsValid = false;

  while(!passwordIsValid) {
    printf("+----------------------+\n");
    printf("| %-20.20s |\n| %-20.20s |\n", "Digite a senha", ">");
    printf("+----------------------+\n");
    printf("\033[2A\033[4C");
    scanf("%s", password);
    passwordIsValid = validateLoginPassword(password);

    if(!passwordIsValid) card("Senha invalida!");
  }
}

bool UserLoginInterface(User *user) {
  if(validateUser(user)) {
    char message[150];
    sprintf(message, "olá %s, seja bem vindo", user->name);
    card(message);
    return true;
  }

  card("Email ou senha incorretos!");
  return false;
}
