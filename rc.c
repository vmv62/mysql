#include <stdio.h>
#include <string.h>
#include "rc.h"

int rdbpar(char *file, db_t *param){
	FILE *fd;
	char buff[BUF_SZ];
	int param_count = 0;
	char *indx;

	fd = fopen(file, "r");
	if(fd == NULL){
		perror("RC_PROG_ERROR: ");
	}


	while(fgets(buff, BUF_SZ, fd)){
		if(strstr(buff, "db_user")){
			getarg(buff, param->db_user);
		}

		if(strstr(buff, "db_passwd")){
			getarg(buff, param->db_passwd);
		}

		if(strstr(buff, "db_addr")){
			getarg(buff, param->db_addr);
		}

		if(strstr(buff, "db_name")){
			getarg(buff, param->db_name);
		}

		if(strstr(buff, "db_table")){
			getarg(buff, param->db_table);
		}

		param_count++;
	}

#ifdef DEBUG
	printf("%s\t%s\t%s\t%s\t%s\n", param->db_user, param->db_passwd, param->db_addr, param->db_name, param->db_table);
#endif

	fclose(fd);

	return param_count;
}

char *getarg(char *buff, char *arg){
	char *token;
	int ln;
	const char delim[2] = "=";

	token = strpbrk(buff, delim);
	ln = strrchr(token, '"') - (strchr(token, '"') + 1);
	strncpy(arg, strchr(token, '"') + 1, ln);
	return arg;
}
