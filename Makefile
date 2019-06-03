all: mysql_cli.c
			gcc mysql_cli.c rc.c clip.c -o mysql -I/usr/include/mysql -L/usr/lib/i386-linux-gnu  -lmariadbclient -lpthread -lz -lm -ldl
clear:
		rm -f mysql
