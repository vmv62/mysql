static char *use_db = "USE %s";
static char *create_table = "CREATE TABLE %s (%s)";
static char *create_db = "CREATE DATABASE %s";
static char *insert_to_table = "INSERT INTO %s(%s) VALUES(%s)";


//Определили новый тип struct colomn_param и присвоели ему псевдоним colomn
typedef struct colomn_param{
	char name[20];
	char type[20];
	char data[20];
}colomn;

//Параметры для подключения к базе данных ввиде нового типа DBDAT
typedef struct {
	char user[20];
	char passwd[20];
	char name[20];
	char server[20];
	char table[20];
	int tc_num;
	colomn col[20];
}DBDAT;

int add_to_db(DBDAT *db);
//int add_to_table(struct table_dat_t *table);
