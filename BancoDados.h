/** \file BancoDados.h
 * \brief Documento com todas as classes de acesso ao banco de dados
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 21/05/19
 * \version 1.0
 */
//Histórico de alterações:
#ifndef BANCODADOS_H_INCLUDED
#define BANCODADOS_H_INCLUDED

#include "sqlite3.h"



class Database
{
public:

    sqlite3* db;

    char* zErrMsg = 0;

    int rc;

    sqlite3_stmt* stmt;


    int open_database (sqlite3** db)
    {
        if(sqlite3_open("test.db", db) != SQLITE_OK) {
            printf("SQL error: can't open database: %s\n", sqlite3_errmsg(*db));
            sqlite3_close(*db);
            return -1;
        }
        return 0;
    }


    int prepare_v2_database (sqlite3* db, const char* zSql, int nByte, sqlite3_stmt** ppStmt, const char* pzTail);


    int step_text_database (sqlite3_stmt* stmt, const unsigned char** sql);


    int exec_database (sqlite3* db, const char* sql, int (* callback)(void* , int, char** , char** ), void* , char** errmsg);


    void close_database (sqlite3* db)
    {
        sqlite3_close(db);
    }


    static void print_error (Database* database)
    {
        printf("ERROR: %s\n", sqlite3_errmsg(database->db));
        setbuf(stdin, nullptr);
        getchar();
    }


    static int callback (void* NotUsed, int argc, char** argv, char** azColName)
    {
        int i;

        for (i = 0; i < argc; i++)
        {
            printf ("%s: %s\t", azColName[i], argv[i] ? argv[i] : "NULL");
        }

        printf ("\n\n");

        return 0;
    }


};



#endif
