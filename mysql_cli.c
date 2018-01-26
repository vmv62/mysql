#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"
#include <string.h>

int main(int argc, char **argv){
	float mmm[4] = {23.3, 56, 78.4};
	add_to_db(mmm);
}

int add_to_db(float *dat){
	MYSQL *con = mysql_init(NULL);
	DBDAT *db;

	db = (DBDAT *)malloc(sizeof(db));


	if (mysql_real_connect(con, "localhost", "root", "23272829", NULL, 0, NULL, 0) == NULL) {
		printf("%s\n", mysql_error(con));
	}

	if (mysql_query(con, "CREATE DATABASE sensors")) {
	        printf("%s\n", mysql_error(con));
	  }


	if (mysql_select_db(con, "sensors")) {
	        printf("%s\n", mysql_error(con));
	  }

	if (mysql_query(con, "CREATE TABLE Counter(Id INT, Voltage DECIMAL(5,2), Ampers DECIMAL(5,2), Activ_Pow DECIMAL(5,2), App_Pow DECIMAL(5,2), Rect_Pow DECIMAL(5,2), Pow_Fact DECIMAL(5,2), Freq DECIMAL(5,2), Imp_Act_En DECIMAL(5,2), Exp_Act_en DECIMAL(5,2), Imp_React_En DECIMAL(5,2), Exp_React_En DECIMAL(5,2), Tot_Act_En DECIMAL(5,2), Tot_React_En DECIMAL(5,2));")) {
      		printf("%s\n", mysql_error(con));
        }

	char tmp_str[2000];
	sprintf(tmp_str, "INSERT INTO Counter(Voltage, Ampers) VALUES(%.2f, %.2f)", dat[0], dat[1]);
	printf("%s\n", tmp_str);

	if(mysql_query(con, tmp_str)){
		printf("%s\n", mysql_error(con));
	}

//	TDATA *table;
//	table = (TDATA *)malloc(sizeof(table));
//	strcpy(db->table->name, "I am table name");
	db->table->name = "I am table name";
	add_to_table(db->table);

	mysql_close(con);
	return 0;
}


int add_to_table(struct table_dat_t *table){
	printf("Add function\n");
	printf("Struct field: %s\n", table->name);
}

