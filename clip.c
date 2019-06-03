#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clip.h"

cliparam_t *get_cli_param(int argc, char **argv){
	cliparam_t *clip;

	clip = (cliparam_t *)malloc(sizeof(cliparam_t));
	clip->mode = 0;

	int argcnt = 0;
			if(argc > 1){
				while(argcnt < argc){
					if(argv[argcnt][0] == '-'){	//This is atribute of parametr.
						switch(argv[argcnt][1]){
							case 'c':	strcpy(clip->col_name, argv[argcnt + 1]);				//Задание имени колонки
											clip->mode |= PREQMODE;
											break;
							case 'v':	strcpy(clip->col_value, argv[argcnt + 1]); //Ручное задание адреса устройства.
											break;
							case 'q':	strcpy(clip->pre_query, argv[argcnt + 1]); //Ручное задание адреса устройства.
											clip->mode |= SINCMODE;
											break;

						}
					}
					if(argv[argcnt][0] == '?'){
						printf("Ключи программы:\n\t-c\t Наименование стобца таблицы.\n\t-v\t Значение столбца.\n\t-q\t Для прямой отправки строки запроса.\n\t-?\t Данная справка.\n");
						return 0;
					}
					argcnt++;
				}
			}
	return clip;
}
