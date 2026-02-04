#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#include ".././interfaces/structs.h"
#include "api.h"

void createUser(User *user) {
  sqlite3 *db;
  char *errmsg = NULL;
  char sql[500];
  
  int rc = sqlite3_open("database/api.db", &db);
  if (rc != SQLITE_OK) {
    printf("Erro ao conectar-se ao banco de dados");
    sqlite3_close(db);
  }

  sprintf(sql, "INSERT INTO User(name, email, password) VALUES('%s', '%s', '%s');", user->name, user->email, user->password);

  rc = sqlite3_exec(db, sql, callback, NULL, &errmsg);
  if (rc != SQLITE_OK) {
    printf("Erro ao cadastrar Usuário\n");
  }

  printf("Usuário cadastrado com sucesso !\n");

  sqlite3_close(db);
}
