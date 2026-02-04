#include "api.h"
#include ".././interfaces/structs.h"
#include "../interfaces/interfaces.h"

#include <sqlite3.h>
#include <stdio.h>

void updateUser(User *user) {
  sqlite3 *db;
  int rc;
  char sql[500];

  rc = sqlite3_open("database/api.db", &db);
  if(rc != SQLITE_OK) {
    printf("Erro na conexão do banco de dados\n");
    return;
  }

  sprintf(sql, "UPDATE User SET name = '%s', WHERE email = %s;", user->name, user->email);

  rc = sqlite3_exec(db, sql, callback, NULL, NULL);
  if (rc != SQLITE_OK) {
    card("Erro ao atualizar os dados");
    sqlite3_close(db);
    return;
  }

  card("dados do Usuário foram atualiados com sucesso");

  sqlite3_close(db);
}
