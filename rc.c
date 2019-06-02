#include <stdio.h>
#include "rc.h"

int main(int argc, char **argv){
	FILE *fd;
	char buff[BUF_SZ];

	fd = fopen("conf", "r");
	if(fd == NULL){
		perror("RC_PROG_ERROR: ");
	}


	while(fgets(buff, BUF_SZ, fd)){
		printf("%s", buff);
	}

	fclose(fd);

	return 0;
}
