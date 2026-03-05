#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "services.h"
#include "../../src/api/api.h"

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

