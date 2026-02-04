#ifndef INTERFACES_H
#define INTERFACES_H

int initInterface(void);
void finishInterface(void);
void clearScreen(void);
void card(const char *msg);

#include "loginInterface/loginInterface.h"
#include "registerInterface/registerInterface.h"

#endif
