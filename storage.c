#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gdbm.h>

/* application includes */
#include "storage.h"

#define datum_set(um, buf) { um.dptr = buf; um.dsize = strlen(buf); }

char * get_db_path()
{
	int MAX_PATH = 256;
	char path[MAX_PATH];
	snprintf(path, MAX_PATH, "%s/%s", getenv("HOME"), db_name);

	return strdup(path);
}

int db_count()
{
	GDBM_FILE dbf;
	
	dbf = gdbm_open(get_db_path(), 0, GDBM_READER, 0, NULL);
	if (!dbf) {
		//printf("%s\n", gdbm_strerror(gdbm_errno));
		return 0;
	}

	datum key, next;
	int n = 0;

	key = gdbm_firstkey(dbf);
	while (key.dptr) {
		n++;
		next = gdbm_nextkey(dbf, key);
		free(key.dptr);
		key = next;
	}
    
	gdbm_close(dbf);

	return n;
}

char ** db_all_keys(int count)
{
	GDBM_FILE dbf;

	dbf = gdbm_open(get_db_path(), 0, GDBM_READER, 0, NULL);
	if (!dbf) {
		//printf("%s\n", gdbm_strerror(gdbm_errno));
		return NULL;
	}

	// resize keys container according to the number of records 
	char ** keys = (char **)malloc(count * sizeof(char*));

	// allocate space for each string
	for (int i = 0; i < count; i++) {
		keys[i] = (char*)malloc(2 * sizeof(char) + 1);
	}

	// get all keys
	datum key, next;
	int n = 0;
	key = gdbm_firstkey(dbf);
	while (key.dptr) {
		strcpy(keys[n], key.dptr); // assign value
		
		next = gdbm_nextkey(dbf, key);
		free(key.dptr);
		key = next;
		n++;
	}

	gdbm_close(dbf);

	return keys;
}

int db_ls()
{
	GDBM_FILE dbf;

	dbf = gdbm_open(get_db_path(), 0, GDBM_READER, 0, NULL);
	if (!dbf) {
		printf("%s\n", gdbm_strerror(gdbm_errno));
		return 1;
	}

	datum key, next, data;
	int n = 1;

	key = gdbm_firstkey(dbf);
	while (key.dptr) {
		data = gdbm_fetch(dbf, key);
		printf("(%d) %s:\t%s\n", n++, key.dptr, data.dptr);
		next = gdbm_nextkey(dbf, key);
		free(key.dptr);
		key = next;
	}

	gdbm_close(dbf);

	return 0;
}

int db_rm(char keyb[2])
{
	GDBM_FILE dbf;
	datum key;

	dbf = gdbm_open(get_db_path(), 0, GDBM_WRITER, 0, NULL);
	if (!dbf) {
		//printf("%s\n", gdbm_strerror(gdbm_errno));
		return 1;
	}

	key.dptr = keyb; key.dsize = strlen(keyb);
	if (gdbm_delete(dbf, key)) {
		//printf("%s\n", gdbm_strerror(gdbm_errno));
		gdbm_close(dbf);
		return 1;
	}

	gdbm_close(dbf);

	return 0;
}

int db_add(char * keyb)
{
	GDBM_FILE dbf;
	datum key, data;

	if (!(dbf = gdbm_open(get_db_path(), 0, GDBM_WRCREAT, 0644, NULL))) {
		//printf("%s\n", gdbm_strerror(gdbm_errno));
		return 1;
	}

	datum_set(key, keyb);
	datum_set(data, keyb);

	if (gdbm_store(dbf, key, data, GDBM_INSERT)) {
		//printf("%s\nRecord may be exist.\n", gdbm_strerror(gdbm_errno));
		gdbm_close(dbf);
		return 1;
	}

	gdbm_close(dbf);

	return 0;
}
