#define VALSIZE	20
#define COLNAMES	20

#define PREQMODE 0x01
#define SINCMODE 0x02

typedef struct{
	int mode;
	char col_name[COLNAMES];
	char col_value[VALSIZE];
	char pre_query[sizeof(int)];
}cliparam_t;

cliparam_t *get_cli_param(int argc, char **argv);
