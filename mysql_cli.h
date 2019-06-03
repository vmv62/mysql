#include "rc.h"
#include "clip.h"

static char *use_db = "USE %s";
static char *create_table = "CREATE TABLE %s (Time TIMESTAMP, %s)";
static char *create_db = "CREATE DATABASE %s";
static char *insert_to_table = "INSERT INTO dayli_counter(%s) VALUE (%s)";


//Определили новый тип struct colomn_param и присвоели ему псевдоним colomn
typedef struct colomn_param{
	char name[20];
	char type[20];
	char data[20];
}colomn;


int add_to_db(db_t *parm, char *query);
//int add_to_table(struct table_dat_t *table);
