#ifndef SERVICRS_H
#define SERVICRS_H

#include "../../src/interfaces/structs.h"

bool validateUser(User *user);

bool validateEmail(const char *email);
bool validateRegisterEmail(const char *email);
void sanitiseEmail(char *email);

bool validateLoginPassword(const char *password);
bool validateRegisterPassword(const char *password);

#endif
