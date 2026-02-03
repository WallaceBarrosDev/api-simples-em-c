#ifndef LOGIN_SERVICE_H
#define LOGIN_SERVICE_H

#include <stdbool.h>

#include "../interfaces/structs.h"

bool validateEmail(const char *email);
bool validateLoginPassword(const char *password);
bool validateUser(const User *user);

#endif
