#include <stdio.h>

//#include "api/api.h"
#include "interfaces/interfaces.h"
//#include "interfaces/structs.h"


int main(void) {
  printf("<== Bem vindo ==>\n");
//  User *userTest;
  
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

      /*case 4:
        createUser(userTest);
      break;*/

      default:
        printf("\nOpcao invalida!\n");
      break;
    }
  
  }

  return 0;
}
