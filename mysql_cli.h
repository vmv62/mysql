typedef struct colomn_param{
	char name[20];
	char type[20];
}colomn;

//Параметры для подключения к базе данных
typedef struct {
	char user[20];
	char passwd[20];
	char name[20];
	char server[20];
	colomn col[20];
}DBDAT;

int add_to_db(DBDAT *db);
//int add_to_table(struct table_dat_t *table);
