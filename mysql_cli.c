#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include "mysql_cli.h"
#include <string.h>

int main(int argc, char **argv){
	float mmm[4] = {23.3, 56, 78.4};

	DBDAT *db_p;
	db_p = (DBDAT *)malloc(sizeof(DBDAT));

	strcpy(db_p->user, "vmv");
	strcpy(db_p->passwd, "23272829");
	strcpy(db_p->server, "194.67.204.166");
	strcpy(db_p->name, "home");
	strcpy(db_p->table, "dayli_counter");
	db_p->tc_num = 2;

	//Заполняем наименования колонок таблицы и их тип.
	strcpy(db_p->col[0].name, "Command");
	strcpy(db_p->col[0].type, "Tinytext");
	strcpy(db_p->col[0].data, "\"ls -lsa\"");

	strcpy(db_p->col[1].name, "Note");
	strcpy(db_p->col[1].type, "Text");
	strcpy(db_p->col[1].data, "\"Command that print list of files and folders\"");


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

	sprintf(buffer, create_db, db->name);
//	printf("%s\n", buffer);

	//Работа с базой.
	
	//Если база выбрана неудачно:
	if(mysql_select_db(con, db->name)){
//		puts("No database, i am create it now!\n");
		if(mysql_query(con, buffer)){
			return -1;
		}
	}


	//Работа с таблицей

	char tmp[2000];
	char tmp1[2000];
	char tmp2[2000];

	memset(buffer, 0, sizeof(buffer));

	//Для создания таблицы формируем пару: название столбца, тип данных
	for(int i=0; i < db->tc_num; i++){
		sprintf(tmp, "%s %s", db->col[i].name, db->col[i].type);
		strncat(buffer, tmp, strlen(tmp));
		if(i < (db->tc_num - 1)){
			strncat(buffer, ", ", strlen(", "));
		}
	}
	char query_string[2000];
	//Формируем строку запроса.
	sprintf(query_string, create_table, db->table, buffer);
	//Обработка ошибки при запросе
	if(mysql_query(con, query_string)){
//		printf("%s\n", mysql_error(con));
	}


	//Внесение данных в таблицу
	memset(buffer, 0, sizeof(buffer));
	memset(tmp, 0, sizeof(tmp));
	memset(tmp1, 0, sizeof(tmp1));
	memset(tmp2, 0, sizeof(tmp2));

	for(int i=0; i < db->tc_num; i++){
		sprintf(tmp, "%s", db->col[i].name);
		strncat(tmp1, tmp, strlen(tmp));
		if(i < (db->tc_num - 1)){
			strncat(tmp1, ", ", strlen(", "));
		}
	}

	memset(tmp, 0, sizeof(tmp));
	for(int i=0; i < db->tc_num; i++){
		sprintf(tmp, "%s", db->col[i].data);
		strncat(tmp2, tmp, strlen(tmp));
		if(i < (db->tc_num - 1)){
			strncat(tmp2, ", ", strlen(", "));
		}
	}

	sprintf(buffer, insert_to_table, db->table, tmp1, tmp2);

	if(mysql_query(con, buffer)){
//		printf("%s\n", mysql_error(con));
	}



	mysql_close(con);
	return 0;
}

