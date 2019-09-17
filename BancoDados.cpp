/** \file BancoDados.cpp
 * \brief Documento com todas as classes de acesso ao banco de dados
 * \author Alexandre Mitsuru Kaihara e Lucas silva
 * \since 21/05/19
 * \version 1.0
 */
#include <stdio.h>
#include "BancoDados.h"



int Database::prepare_v2_database (sqlite3* db, const char* zSql, int nByte, sqlite3_stmt** ppStmt, const char* pzTail)
{
    if (sqlite3_prepare_v2(db, zSql, -1, ppStmt, NULL) != SQLITE_OK) {

        sqlite3_finalize(stmt);
        return -1;
    }
    return 0;
}



int Database::exec_database (sqlite3* db, const char* sql, int (* callback)(void* , int, char** , char** ), void* a, char** errmsg)
{
    if (sqlite3_exec (db, sql, callback, a, errmsg) != SQLITE_OK) {
        printf("ERROR: %s\n", sqlite3_errmsg(db));

        setbuf(stdin, nullptr);
        getchar();

        return -1;
    }

    return 0;
}



int Database::step_text_database (sqlite3_stmt* stmt, const unsigned char** sql)
{
    // O sqlite3_step deve rodr enquanto o ret_code for igual a 100
    // Quando alacançar o valor 101 deve-se encerrar a execução do step
    // Caso ret_code for diferente de 100 e 101, que dizer que deu errado
    int ret_code = 0;

    if ((ret_code = sqlite3_step(stmt)) == SQLITE_ROW) {
        *sql = sqlite3_column_text(stmt, 0);
        return ret_code;
    }
    else if(ret_code != SQLITE_DONE) {
        //this error handling could be done better, but it works
        printf ("SQL error: %s\n", sqlite3_errmsg(db));

        setbuf(stdin, nullptr);
        getchar();

        return -1;
    }

    return ret_code;
}





