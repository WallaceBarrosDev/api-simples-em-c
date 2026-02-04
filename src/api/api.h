#ifndef API 
#define API

#include ".././interfaces/structs.h"

void createUser(User *user);
void deleteUser(int id);
void getUser(int id);
void updateUser(User *user, int id);
int callback(void *data, int argc, char **argv, char**arColName);

#endif
