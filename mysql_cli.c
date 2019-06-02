#include <stdio.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"

int main(int argc, char **argv){
	float mmm[4] = {23.3, 56, 78.4};

	//Создаем указатель и выделяем память под настройки базы данных
	db_t *param;
	param = (db_t *)malloc(sizeof(db_t));

	rdbpar("./conf", param);

	printf("%s\n", param->db_addr);
	add_to_db(param, insert_to_table);
	free(param);
	return 0;
}

int add_to_db(db_t *db, char *query){
	MYSQL *con = mysql_init(NULL);

	//Подключаемся к базе (сервер, пользователь, пароль)
	if (mysql_real_connect(con, db->db_addr, db->db_user, db->db_passwd, NULL, 0, NULL, 0) == NULL) {
//		perror("%s\n", mysql_error(con)); 
				return -1;
	}


	//Работа с базой.
	//Если база выбрана неудачно:
	if(mysql_select_db(con, db->db_name)){
//		puts("No database, i am create it now!\n");
		if(mysql_query(con, query)){
			return -1;
		}
	}



	//Отправка запроса на сервер
	if(mysql_query(con, query)){
		printf("%s\n", mysql_error(con));
	}



	mysql_close(con);
	return 0;
}


