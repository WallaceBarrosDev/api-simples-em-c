#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#include ".././interfaces/interfaces.h"
#include ".././interfaces/structs.h"

int selectUser(void *, int, char **, char **);

User *getUser(const char *email) {
  sqlite3 *db;
  int rc;
  char sql[100];
  User *user = malloc(sizeof(User));

  rc = sqlite3_open("database/api.db", &db);
  if(rc != SQLITE_OK) {
    card("Erro ao conectar no banco de dados");
    return NULL;
  }

  sprintf(sql, "SELECT name, email, password FROM User WHERE email = '%s';", email);

  rc = sqlite3_exec(db, sql, selectUser , user, NULL);
  if(rc != SQLITE_OK) {
    card("Erro ao buscar o Usuário");
    sqlite3_close(db);
    return NULL;
  }

  sqlite3_close(db);
  return user;
}

int selectUser(void *data, int argc, char **argv, char **arColName) {
  (void) argc; (void) arColName;

  User *user = (User *) data;
  sprintf(user->name, "%s", argv[0]);
  sprintf(user->email, "%s", argv[1]);
  sprintf(user->password, "%s", argv[2]);
  return 0;
}
