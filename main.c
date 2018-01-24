#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv){
	MYSQL *con = mysql_init(NULL);
	printf("MySQL client version: %s\n", mysql_get_client_info());

	if (mysql_real_connect(con, "localhost", "root", "23272829", NULL, 0, NULL, 0) == NULL) {
		printf("%s\n", mysql_error(con));
	        mysql_close(con);
	        exit(1); 
	}

	if (mysql_query(con, "CREATE DATABASE sensors")) 
	  {
	        printf("%s\n", mysql_error(con));
	        mysql_close(con);
	  	exit(1);
	  }


	if (mysql_query(con, "CREATE TABLE Counter(Id INT, Voltage DECIMAL(5,2), Ampers DECIMAL(5,2), Activ_Pow DECIMAL(5,2), App_Pow DECIMAL(5,2), Rect_Pow DECIMAL(5,2), Pow_Fact DECIMAL(5,2), Freq DECIMAL(5,2), Imp_Act_En DECIMAL(5,2), Exp_Act_en DECIMAL(5,2), Imp_React_En DECIMAL(5,2), Exp_React_En DECIMAL(5,2), Tot_Act_En DECIMAL(5,2), Tot_React_En DECIMAL(5,2))")) {
      		printf("%s\n", mysql_error(con));
        }

	return 0;
}
