#include "mainhadder.h"
#ifndef __PROMPT_H
#define __PROMPT_H
char *get_dyn();

void interpert_add(char *str, struct apart_list *lst);

void interpert_get(char *str, struct apart_list lst);

void interpert_buy(char *str, struct apart_list *lst);

void interpert_get_enter(char *str, struct apart_list lst);

void interpert_del_enter(char *str, struct apart_list lst);


char *str_replace(char *str, char *orig, char *rep);


void interpert(char *str, struct apart_list *lst, char **recent_commends_array, struct commend_list *clst);
#endif 
