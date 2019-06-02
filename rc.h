#define BUF_SZ	200

typedef struct{
	char db_addr[20];
	char db_user[20];
	char db_passwd[20];
	char db_name[20];
	char db_table[20];
}db_t;

db_t param;

int rdbpar(char *file, db_t *param);
char *getarg(char *buff, char *arg);
