#define BUF_SZ	200

typedef struct{
	char tb_name[20];
	char *tb_params[20];
	char *tb_parval[20];
}tb_t;

typedef struct{
	char db_addr[20];
	char db_user[20];
	char db_passwd[20];
	char db_name[20];
	tb_t table;
}db_t;

db_t param;

int rdbpar(char *file, db_t *param);
char *getarg(char *buff, char *arg);
