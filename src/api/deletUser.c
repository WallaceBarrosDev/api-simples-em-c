#include <sqlite3.h>
#include <stdio.h>

#include "api.h"
#include ".././interfaces/interfaces.h"

void deleteUser(char *email) {
  sqlite3 *db;
  char sql[100];
  int rc;

  rc = sqlite3_open("database/api.db", &db);
  if (rc != SQLITE_OK) {
    printf("Erro na concexão com o banco de dados");
    return;
  }

  sprintf(sql, "DELETE FROM User WHERE email = %s", email);

  rc = sqlite3_exec(db, sql, callback, NULL, NULL);
  if (rc != SQLITE_OK) {
    card("Erro ao excluir o Usuário");
    sqlite3_close(db);
  }

  card("Usuário excluido");

  sqlite3_close(db);
}
