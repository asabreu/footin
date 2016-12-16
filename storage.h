#ifndef STORAGE_H
#define STORAGE_H

static const char * db_name = ".footin.db";
char * get_db_path();

int db_count();
char ** db_all_keys(int count);
int db_ls();
int db_rm(char * keyb);
int db_add(char keyb[2]);

#endif
