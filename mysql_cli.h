struct table_dat{
	char *name;
};


typedef struct {
	char *user;
	char *passwd;
	char *dbname;
	struct table_dat table_dat_t;
}DBDAT;

int add_to_table(struct table_dat *table);
