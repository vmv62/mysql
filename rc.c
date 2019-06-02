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
		token = strtok(buff, delim);
		while(token != NULL){
//			printf("%s", token);
			strcpy(params[param_count].param_name, token);
			token = strtok(NULL, delim);
//			strcpy(params[param_count].param_value, token);
		}
			printf("%s", params[param_count].param_name);

//			strcpy(params[param_count].param_value, token);
			param_count++;
//			printf("%s\t\t%s\n", params[param_count].param_name, params[param_count].param_value);
	}
	printf("Params count: %d\n", param_count);

	fclose(fd);

	return 0;
}
