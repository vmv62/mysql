#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"
#include <string.h>

int main(int argc, char **argv){
	float mmm[4] = {23.3, 56, 78.4};
	
	DBDAT *db_p;
	db_p = (DBDAT *)malloc(sizeof(DBDAT));

	strcpy(db_p->user, "root");
	strcpy(db_p->passwd, "23272829");
	strcpy(db_p->server, "localhost");
	strcpy(db_p->name, "sensors");
	add_to_db(db_p);
}

int add_to_db(DBDAT *db){
	MYSQL *con = mysql_init(NULL);


	if (mysql_real_connect(con, db->server, db->user, db->passwd, NULL, 0, NULL, 0) == NULL) {
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
	sprintf(tmp_str, "INSERT INTO Counter(Voltage, Ampers) VALUES(%.2f, %.2f)", 23.78, 612.3);
	printf("%s\n", tmp_str);

	if(mysql_query(con, tmp_str)){
		printf("%s\n", mysql_error(con));
	}

	mysql_close(con);
	return 0;
}


int add_to_table(struct table_dat_t *table){
	printf("Add function\n");
	printf("Struct field: %s\n", table->name);
}

