#include <sqlite3.h>
#include <stdio.h>

int select(void *, int, char **, char **);

void getUser(int id) {
  sqlite3 *db;
  int rc;
  char sql[100];

  rc = sqlite3_open("database/api.db", &db);
  if(rc != SQLITE_OK) {
    printf("Erro ao conectar no banco de dados");
  }

  sprintf(sql, "SELECT name FROM User WHERE id = %d", id);

  rc = sqlite3_exec(db, sql, select , NULL, NULL);
  if(rc != SQLITE_OK) {
    printf("Erro ao deletar o Usuário");
    sqlite3_close(db);
  }

  sqlite3_close(db);
}

int select(void *NotUse, int argc, char **argv, char **arColName) {
  (void) NotUse; (void) argc;
  printf("%s = %s\n", arColName[0], argv[0]);
  return 0;
}
