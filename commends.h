#ifndef __COMMENDS_H
#define __COMMENDS_H
#include "mainhadder.h"
struct apart* create_apart(unsigned int code,char *addr,int price,short int rooms,struct date date_of_entrance,struct apart* prev ,struct apart* next,struct date time_stamp);
void add_apart_by_price(struct apart_list* lst,char *addr,int price,short int rooms,struct date date_of_entrance,unsigned int code,struct date time_stamp);
struct apart* find_prev(struct apart_list* lst,int price,bool* replace_tail);
void print_apart(struct apart apart1);
void print_by_values(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce,bool sr);
void print_by_values_up(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce);
void print_by_values_down(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce);
bool is_later (struct date date1,struct date date2);
struct date str_to_date(char *str);
void buy_apartment(struct apart_list *lst, unsigned int code);
void buy_apartment(struct apart_list* lst, unsigned int code);
void get_an_apart_enter(struct apart_list lst,int days_env);

void delte_apart_in_env(struct apart_list* lst,int days_env);
void make_empty_tm(struct tm* date);

unsigned int max_between_codes(unsigned int a,unsigned int b);
void free_apt_lst(struct apart_list* lst);
void free_apt(struct apart* p);
#endif 
