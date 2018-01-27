#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"
#include <string.h>

int main(int argc, char **argv){
	float mmm[4] = {23.3, 56, 78.4};
	
	DBDAT *db_p;
	db_p = (DBDAT *)malloc(sizeof(DBDAT));


	if(argc < 4){
		puts("Usage: command 'db_name' 'table_name' 'colomn_name' 'colomn_type'");
	}

	strcpy(db_p->user, "root");
	strcpy(db_p->passwd, "23272829");
	strcpy(db_p->server, "localhost");
	strcpy(db_p->name, argv[1]);
	strcpy(db_p->table, argv[2]);
	db_p->tc_num = 2;

	//Заполняем наименования колонок таблицы и их тип.
	strcpy(db_p->col[0].name, argv[3]); // "CHAR(20)"};
	strcpy(db_p->col[0].type, argv[4]);


//	strcpy(db_p->col[1].name, "Note"); // "CHAR(20)"};
//	strcpy(db_p->col[1].type, "Text");

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
	char tmp[200];

	memset(buffer, 0, sizeof(buffer));


	for(int i=0; i < db->tc_num; i++){
		sprintf(tmp, "%s %s", db->col[i].name, db->col[i].type);
		strncat(buffer, tmp, strlen(tmp));
		if(i < (db->tc_num - 1)){
			strncat(buffer, ", ", strlen(", "));
		}
	}

	char query_string[2000];

	sprintf(query_string, create_table, db->table, buffer);
	printf("%s\n", query_string);

	if(mysql_query(con, query_string)){
		printf("%s\n", mysql_error(con));
	}




//	sprintf(tmp_str, "INSERT INTO Counter(Voltage, Ampers) VALUES(%.2f, %.2f)", 23.78, 612.3);
//	printf("%s\n", tmp_str);
/*
	if(mysql_query(con, query_string)){
		printf("%s\n", mysql_error(con));
	}

*/

	mysql_close(con);
	return 0;
}

/*
int add_to_table(struct table_dat_t *table){
	printf("Add function\n");
	printf("Struct field: %s\n", table->name);
}
*/
