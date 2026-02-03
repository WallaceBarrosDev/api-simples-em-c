#include <stdio.h>

#include "interfaces/interfaces.h"


int main(void) {
  printf("<== Bem vindo ==>\n");
  
  while (1) {
    int option = initInterface();

    switch (option) {
      case 1:
        loginInterface();
      break;

      case 2:
        registerInterface();        
      break;
      
      case 3:
        finishInterface();
      break;
      
      default:
        printf("\nOpcao invalida!\n");
      break;
    }
  
  }

  return 0;
}
