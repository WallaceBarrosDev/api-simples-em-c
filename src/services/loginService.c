#include <string.h>

#include "loginService.h"

bool validateEmail(const char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
}

bool validateLoginPassword(const char *password) {
  return (strlen(password) >= 6) ? true : false;
}

bool validateUser(const User *user) {
  return (!strcmp(user->email, "w@w") && !strcmp(user->password, "abc123"));
}
