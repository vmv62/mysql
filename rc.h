#define BUF_SZ	200
#define PNSIZE	20

enum{
	MDB_RTU = 0x01,
	MDB_TCP,
};

typedef struct{
	char name[20];
	char *params[20];
	char *parval[20];
}tb_t;

typedef struct{
	char db_addr[20];
	char db_user[20];
	char db_passwd[20];
	char db_name[20];
	tb_t table;
	int prg_tmint;
	int prg_prot;
	int prg_connspd;
	int prg_pollint;
}db_t;

db_t param;

int rdbpar(char *file, db_t *param);
char *getarg(char *buff, char *arg);
int getintarg(char *buff);
