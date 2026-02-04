#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

#include ".././interfaces/structs.h"
#include "../interfaces/interfaces.h"
#include "api.h"

void createUser(User *user) {
  sqlite3 *db;
  char *errmsg = NULL;
  char sql[500];
  
  int rc = sqlite3_open("database/api.db", &db);
  if (rc != SQLITE_OK) {
    printf("Erro ao conectar-se ao banco de dados");
    sqlite3_close(db);
    return;
  }

  sprintf(sql, "INSERT INTO User(name, email, password) VALUES('%s', '%s', '%s');", user->name, user->email, user->password);

  rc = sqlite3_exec(db, sql, callback, NULL, &errmsg);
  char err[200];
  if (rc != SQLITE_OK) {
    if(rc == SQLITE_CONSTRAINT) {
      sprintf(err, "Email %s ja cadastrado", user->email);
    } else {
      sprintf(err, "Erro ao cadastrar o Usuário");
    }
    card(err);
    sqlite3_free(errmsg);
    sqlite3_close(db);
    return;
  }

  card("Usuário cadastrado com sucesso");

  sqlite3_close(db);
}
