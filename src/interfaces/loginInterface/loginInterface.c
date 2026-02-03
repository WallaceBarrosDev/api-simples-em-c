#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../interfaces.h"
#include "../structs.h"
#include "../../services/loginService.h"

void emailLoginInterface(char *);
void passwordLoginInterface(char *);
void UserLoginInterface(User *);

void loginInterface() {
  User *user = malloc(sizeof(User));
  
  clearScreen();
  printf("\n+----------------------+\n");
  printf("| %-20.20s |\n", "Logue com o usuario");
  printf("+----------------------+\n");
  
  emailLoginInterface(user->email);
  passwordLoginInterface(user->password);
  UserLoginInterface(user);

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
    emailIsValid = validateEmail(email);

    if(!emailIsValid) {
      printf("+----------------------+\n");
      printf("| %-20.20s |\n", "Email invalido!");
      printf("+----------------------+\n"); 
    }
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

    if(!passwordIsValid) {
      printf("+----------------------+\n");
      printf("| %-20.20s |\n", "Senha muito curta!");
      printf("+----------------------+\n");
    }
  }
}

void UserLoginInterface(User *user) {
  if(validateUser(user)) {
    printf("olá %s, seja bem vindo\n", user->email);
  }

  printf("+----------------------+\n"); 
  printf("| %20.20s |\n", "Email ou senha invalido");
  printf("+----------------------+\n"); 
}
