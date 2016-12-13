#ifndef STORAGE_H
#define STORAGE_H

static const char *dbname = ".footin.db";
char * get_dbpath();

int db_count();
char ** db_allKeys(int count);
int db_ls();
int db_rm(char * keyb);
int db_add(char keyb[2]);

#endif
