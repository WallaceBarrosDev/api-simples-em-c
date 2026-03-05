#ifndef API 
#define API

#include ".././interfaces/structs.h"

void createUser(User *user);
User *getUser(const char *email);
void updateUser(User *user);
void deleteUser(char *email);

int callback(void *data, int argc, char **argv, char**arColName);

#endif
