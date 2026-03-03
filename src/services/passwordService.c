#include <stdbool.h>
#include <string.h>

bool validateRegisterPassword(const char *password) {
  return (strlen(password) >= 6) ? true : false;
}

bool validateLoginPassword(const char *password) {
  return (strlen(password) >= 6) ? true : false;
}
