#include "api.h"
#include ".././interfaces/structs.h"

#include <sqlite3.h>
#include <stdio.h>

void updateUser(User *user, int id) {
  sqlite3 *db;
  int rc;
  char sql[500];

  rc = sqlite3_open("database/api.db", &db);
  if(rc != SQLITE_OK) {
    printf("Erro na conexão do banco de dados\n");
    return;
  }

  snprintf(sql, sizeof(sql), "UPDATE User SET name = '%s', email = '%s', password = '%s' WHERE id = %d;", user->name, user->email, user->password, id);

  rc = sqlite3_exec(db, sql, callback, NULL, NULL);
  if (rc != SQLITE_OK) {
    printf("Erro ao atualizar os dados\n");
    sqlite3_close(db);
    return;
  }

  printf("dados do Usuário foram atualiados com sucesso\n");

  sqlite3_close(db);
}
