
#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"

int main(int argc, char **argv){
        float mmm[4] = {23.3, 56, 78.4};
        add_to_db(mmm);
}

int add_to_db(float *dat){
        MYSQL *con = mysql_init(NULL);

        if (mysql_real_connect(con, "localhost", "root", "23272829", NULL, 0, NULL, 0) == NULL) {
                printf("%s\n", mysql_error(con));
        }

        if (mysql_query(con, "CREATE DATABASE sensors")) {
                printf("%s\n", mysql_error(con));
          }


        if (mysql_select_db(con, "sensors")) {
                printf("%s\n", mysql_error(con));
          }

        if (mysql_query(con, "CREATE TABLE Counter(Id INT, Voltage DECIMAL(5,2), Ampers DECIMAL(5,2$
                printf("%s\n", mysql_error(con));
        }

 char tmp_str[2000];
        sprintf(tmp_str, "INSERT INTO Counter(Voltage, Ampers) VALUES(%.2f, %.2f)", dat[0], dat[1]);
        printf("%s\n", tmp_str);

        if(mysql_query(con, tmp_str)){
                printf("%s\n", mysql_error(con));
        }

        TDATA *table;

        table = (TDATA *)malloc(sizeof(table));
        add_to_table(table);

        mysql_close(con);
        return 0;
}

int add_to_table(TDATA *table){
//      amysql_query(con, "INSERT INTO counter(Voltage, Ampers) VALUES(230.5, 1.89)");
        printf("Add function\n");
}
