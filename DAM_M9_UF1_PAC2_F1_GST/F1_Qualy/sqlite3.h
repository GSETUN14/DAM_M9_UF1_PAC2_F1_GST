/* sqlite3.h
** SQLite header file.
**
** This file defines the API for SQLite.
**
** For additional documentation see the SQLite website: https://sqlite.org/
*/

#ifndef SQLITE3_H
#define SQLITE3_H

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct sqlite3 sqlite3;
	typedef struct sqlite3_stmt sqlite3_stmt;
	typedef struct sqlite3_value sqlite3_value;

	/* SQLite return codes */
#define SQLITE_OK           0   /* Successful result */
#define SQLITE_ERROR        1   /* SQL error or missing database */
#define SQLITE_BUSY         5   /* Database file is locked */
#define SQLITE_DONE         101 /* Done processing a statement */

/* Open a database */
	int sqlite3_open(const char* filename, sqlite3** ppDb);

	/* Close a database */
	int sqlite3_close(sqlite3* db);

	/* Execute an SQL statement */
	int sqlite3_exec(sqlite3* db, const char* sql, int (*callback)(void*, int, char**, char**), void* arg, char** errmsg);

	/* Prepare an SQL statement */
	int sqlite3_prepare_v2(sqlite3* db, const char* sql, int nByte, sqlite3_stmt** ppStmt, const char** pzTail);

	/* Finalize a prepared statement */
	int sqlite3_finalize(sqlite3_stmt* pStmt);

	/* Step through a prepared statement */
	int sqlite3_step(sqlite3_stmt* pStmt);

	/* Reset a prepared statement */
	int sqlite3_reset(sqlite3_stmt* pStmt);

	/* Get the number of columns in a result set */
	int sqlite3_column_count(sqlite3_stmt* pStmt);

	/* Get the value of a column as a string */
	const char* sqlite3_column_text(sqlite3_stmt* pStmt, int iCol);

	/* Free memory */
	void sqlite3_free(void* p);

	/* Versioning */
	const char* sqlite3_version(void);

#ifdef __cplusplus
}
#endif

#endif /* SQLITE3_H */
