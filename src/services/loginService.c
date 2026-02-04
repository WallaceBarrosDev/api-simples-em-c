#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "loginService.h"
#include "../api/api.h"

bool validateEmail(const char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
}

bool validateLoginPassword(const char *password) {
  return (strlen(password) >= 6) ? true : false;
}

#include <string.h>

bool validateUser(User *user) {
    User *dbUser = getUser(user->email);
 
    if(dbUser == NULL) return false;

    if(strcmp(dbUser->password, user->password) != 0) {
      free(dbUser);
      return false;
    }

    strcpy(user->name, dbUser->name);

    free(dbUser);
    return true;
}

