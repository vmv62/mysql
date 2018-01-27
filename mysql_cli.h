struct table_dat_t{
	char *name;
};

//Параметры для подключения к базе данных
typedef struct {
	char user[20];
	char passwd[20];
	char name[20];
	char server[20];
}DBDAT;

int add_to_db(DBDAT *db);
int add_to_table(struct table_dat_t *table);
