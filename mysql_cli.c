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
	strcpy(db_p->table, "Counter");
	db_p->tc_num = 2;

	//Заполняем наименования колонок таблицы и их тип.
	strcpy(db_p->col[0].name, "Voltage"); // "CHAR(20)"};
	strcpy(db_p->col[0].type, "CHAR(20)");


	strcpy(db_p->col[1].name, "Ampers"); // "CHAR(20)"};
	strcpy(db_p->col[1].type, "INT");

	add_to_db(db_p);
}

int add_to_db(DBDAT *db){
	MYSQL *con = mysql_init(NULL);
	char buffer[1000];

	//Подключаемся к базе (сервер, пользователь, пароль)
	if (mysql_real_connect(con, db->server, db->user, db->passwd, NULL, 0, NULL, 0) == NULL) {
		printf("%s\n", mysql_error(con)); 
		return -1;
	}

	char *create_db = "CREATE DATABASE %s";
	char *select_db = "USE %s";

	sprintf(buffer, select_db, db->name);

	//Работа с базой.
	
	//Если база выбрана неудачно:
	if(mysql_select_db(con, db->name)){
		//создаем базу, если неудачно, то выходим.
		if(mysql_query(con, buffer)){
			return -1;
		}
	}


	//Работа с таблицей

	char *create_table = "CREATE TABLE %s (%s)";
	char *param_pair = "%s %s%s";
	char tmp[200];

	for(int i=0; i < db->tc_num; i++){
		sprintf(tmp, param_pair, db->col[i].name, db->col[i].type, ", ");
		printf("%s", tmp);
		strcat(buffer, tmp);
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

/*
int add_to_table(struct table_dat_t *table){
	printf("Add function\n");
	printf("Struct field: %s\n", table->name);
}
*/
