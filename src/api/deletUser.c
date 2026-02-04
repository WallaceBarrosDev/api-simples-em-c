#include <sqlite3.h>
#include <stdio.h>

#include "api.h"

void deleteUser(int id) {
  sqlite3 *db;
  char sql[100];
  int rc;

  rc = sqlite3_open("database/api.db", &db);
  if (rc != SQLITE_OK) {
    printf("Erro na concexão com o banco de dados");
    return;
  }

  sprintf(sql, "DELETE FROM User WHERE id = %d", id);

  rc = sqlite3_exec(db, sql, callback, NULL, NULL);
  if (rc != SQLITE_OK) {
    printf("Erro ao excluir o Usuário");
    sqlite3_close(db);
  }

  printf("Usuário excluido\n");

  sqlite3_close(db);
}
