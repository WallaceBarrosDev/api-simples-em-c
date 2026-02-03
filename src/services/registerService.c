#include <string.h>

#include "registerService.h"

bool validateRegisterEmail(const char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
}

bool validateRegisterPassword(const char *password) {
  return (strlen(password) >= 6) ? true : false;
}
