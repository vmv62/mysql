#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"
#include <string.h>

int main(int argc, char **argv){
	float mmm[4] = {23.3, 56, 78.4};

	DBDAT *db_p;
	db_p = (DBDAT *)malloc(sizeof(DBDAT));
/*
Конфигурация подключения должна задаваться из вне
*/
	strcpy(db_p->user, "vmv");
	strcpy(db_p->passwd, "23272829");
	strcpy(db_p->server, "194.67.204.166");
	strcpy(db_p->name, "home");
	strcpy(db_p->table, "dayli_counter");
	db_p->tc_num = 2;



	add_to_db(db_p);
}

int add_to_db(DBDAT *db){
	MYSQL *con = mysql_init(NULL);
	char buffer[1000];

	//Подключаемся к базе (сервер, пользователь, пароль)
	if (mysql_real_connect(con, db->server, db->user, db->passwd, NULL, 0, NULL, 0) == NULL) {
		perror("%s\n", mysql_error(con)); 
				return -1;
	}


	//Работа с базой.
	//Если база выбрана неудачно:
	if(mysql_select_db(con, db->name)){
//		puts("No database, i am create it now!\n");
		if(mysql_query(con, buffer)){
			return -1;
		}
	}



	//Отправка запроса на сервер
	if(mysql_query(con, buffer)){
		printf("%s\n", mysql_error(con));
	}



	mysql_close(con);
	return 0;
}

