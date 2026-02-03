#ifndef INTERFACES
#define INTERFACES

typedef struct {
  char name[100];
  char email[100];
  char password[100];
} User;

int initInterface();
void finishInterface();
void loginInterface();
void registerInterface();

#endif
