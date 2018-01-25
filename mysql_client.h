int add_to_table(struct table_context *table);

//befoure use this function, you need allocate place fj structure, and fill all members, then pass to function like parametr.


struct table_context{
  char name[500];
  char *tab_names[20];
  void *tab_data[20];
  int val_num;
};
