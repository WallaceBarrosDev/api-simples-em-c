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
  printf("| %-20.20s |\n| %-20.20s |\n| %-20.20s |\n| %-20.20s |\n", "[1] Login", "[2] Registre-se", "[3] Sair", "|>");
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

bool validateEmail(char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
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

bool validateUser(User *user) {
  return (!strcmp(user->email, "w@w") && !strcmp(user->password, "abc123"));
}

bool validateLoginPassword(char *password) {
  return (strlen(password) >= 6) ? true : false;
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

void nameRegisterInterface(char *name) {
  printf("+----------------------+\n"); 
  printf("| %-20.20s |\n| %-20.20s |\n", "Digite o nome", ">");
  printf("+----------------------+\n"); 
  printf("\033[2A\033[4C");
  scanf("%s", name);
}

bool validateRegisterEmail(char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
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

    if(!emailIsValid) {
      printf("+----------------------+\n"); 
      printf("| %-20.20s |\n", "Email invalido!");
      printf("+----------------------+\n"); 
    }
  }
}

bool validateRegisterPassword(char *password) {
  return (strlen(password) >= 6) ? true : false;
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

    if(!passwordIsValid) {
      printf("+----------------------+\n"); 
      printf("| %-20.20s |\n", "Senha muito curta!");
      printf("+----------------------+\n"); 
    }
  }
}

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
