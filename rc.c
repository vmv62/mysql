#include <stdio.h>
#include <string.h>
#include "rc.h"

int main(int argc, char **argv){
	FILE *fd;
	char buff[BUF_SZ];
	char *token;
	const char delim[2] = "=";
	int param_count = 0;

	fd = fopen("conf", "r");
	if(fd == NULL){
		perror("RC_PROG_ERROR: ");
	}


	while(fgets(buff, BUF_SZ, fd)){
		//Чистим строку от ненужных символов.
		//Ищем разделитель.
		if(strstr(buff, "db_addr")){
			printf("Find db addr");
		}
		token = strpbrk(buff, delim);	
		//Забираем название параметра
		strncpy(params[param_count].param_name, buff,  token - buff);
		//Забираем значение параметра.
		strcpy(params[param_count].param_value, token + 1);
		printf("%s\t%s", params[param_count].param_name, params[param_count].param_value);
		param_count++;

	}
	printf("Params count: %d\n", param_count);

	fclose(fd);

	return 0;
}
