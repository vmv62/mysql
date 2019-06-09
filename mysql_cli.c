#include <stdio.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"
#define DEBUG

int main(int argc, char **argv){
	float mmm[4] = {23.3, 56, 78.4};
	char hquery[200];

	//Создаем указатель и выделяем память под настройки базы данных
	db_t *param;
	param = (db_t *)malloc(sizeof(db_t));

	cliparam_t *dp;

	//Получаем данные для отправки в базу из командной строки
	dp = get_cli_param(argc, argv);

	//Получаем настройки для соединения с базой из файла
	rdbpar("./conf", param);

#ifdef DEBUG
	printf("%s\n", param->table.name);
	printf("%s\t%s\t%s\n", param->table.params[0], param->table.params[1], param->table.params[2]);
	printf("%d\t%d\t%d\t\n", param->prg_tmint, param->prg_connspd, param->prg_pollint);
#endif

	if(dp->mode & SINCMODE){
		//Формируем строку запроса для отправки на сервер
		sprintf(hquery, insert_to_table, dp->col_name, dp->col_value);
		add_to_db(param, hquery);
	}
/*
	if(dp->mode || PREQMODE){
		add_to_db(param, dp->pre_query);
	}
*/
	free(param);
	return 0;
}

int add_to_db(db_t *db, char *query){
	MYSQL *con = mysql_init(NULL);

#ifdef DEBUG
	printf("Start connect o server\n");
#endif

	//Подключаемся к базе (сервер, пользователь, пароль)
	if (mysql_real_connect(con, db->db_addr, db->db_user, db->db_passwd, NULL, 0, NULL, 0) == NULL) {
		printf("%s\n", mysql_error(con));
				return -1;
	}

#ifdef DEBUG
	printf("Connect to server done\n");
#endif

	//Работа с базой.
	//Если база выбрана неудачно:
	if(mysql_select_db(con, db->table.name)){
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


