struct table_dat_t{
	char *name;
};


typedef struct {
	char *user;
	char *passwd;
	char *dbname;
	struct table_dat_t *table;
}DBDAT;

int add_to_db(float *dat);
int add_to_table(struct table_dat_t *table);
