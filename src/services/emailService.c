#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "services.h"

bool validateEmail(const char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
}

bool validateRegisterEmail(const char *email) {
  return (strstr(email, "@") != NULL) ? true : false;
}

void sanitiseEmail(char *email) {
  for(int i = 0; email[i] != '\0'; i++) {
    email[i] = tolower(email[i]);
  }
}
