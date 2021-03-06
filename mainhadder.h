//
// Created by noam ambar on 04/05/2018.
//

#ifndef SCHOOL_PROJECT_MAINHADDER_H
#define SCHOOL_PROJECT_MAINHADDER_H
#include<stdbool.h>
#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RECENT_COMMENDS_SIZE 7
int commends_amount;
#define MAXLINE 1024
struct date{
    short int day;
    short int month;
    short int year;
};


struct apart{
    unsigned int code;
    char *addr;
    int price;
    short int rooms;
    struct date date_of_entrance;
    struct date date_stamp;
    struct apart* next;
    struct apart* prev;
};
//shell
struct commend_list_node{
    char* commend;
    struct commend_list_node* next;

};
struct commend_list{
    struct commend_list_node* head;
    struct commend_list_node* tail;
};
struct apart_list{
    struct apart* head;
    struct apart* tail;
};
/*
char **GetString(char *);

void interpert(char *str, struct apart_list *lst, char **recent_commends_array, struct commend_list *clst);

//db queries
void print_aprt(int maxPrice, int maxRooms, int minRooms, struct date maxDate, bool flag);
bool is_later (struct date date1,struct date date2) ;
void print_by_values_down(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce);
void print_by_values_up(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce);
void print_by_values(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce,bool sr);
void print_apart(struct apart apart1);
struct apart* find_prev(struct apart_list* lst,int price,bool* replace_tail);
void get_an_apart_enter(struct apart_list lst,int days_env);
void buy_apartment(struct apart_list* lst, unsigned int code);
void make_empty_tm(struct tm* date);
void make_room_for_new_commend_in_array(char** recent_commends_array);
void create_commend_list_node_and_add_to_head(char* commend,struct commend_list* lst);
void commends_saver(char* commend,char** recent_commends_array,struct commend_list* lst);
void add_commend_list_node_to_head(struct commend_list_node* commend_list_node1,struct commend_list* lst);
void repeat_commend_by_number(char *head, char** recent_commends_array,struct commend_list* c_lst,struct apart_list *lst);
void save_apartments(struct apart_list lst);
struct apart_list read_apartments();
void add_apart_by_price(struct apart_list* lst,char *addr,int price,short int rooms,struct date date_of_entrance,unsigned int code,struct date time_stamp);
char *str_replace(char *str, char *orig, char *rep);
 *
 * input: max price, rooms range and the latest date to enter the apartment.
 * -1 means ignoring the requirement,
 * output: prints all the apartment that suits the requirements.

char *get_dyn();
struct date str_to_date (char *str);
void delte_apart_in_env(struct apart_list* lst,int days_env);
void save_commends_to_file(struct commend_list* c_lst,char** recent_commends_arr);
void read_commends_from_file(struct commend_list* c_lst,char** recent_commends_arr);
void initialize_commends_to_null(struct commend_list* c_lst,char** recent_commends_arr);
struct apart* create_apart(unsigned int code,char *addr,int price,short int rooms,struct date date_of_entrance,struct apart* prev ,struct apart* next,struct date time_stamp);
void commends_saver(char* commend,char** recent_commends_array,struct commend_list* lst);
void printlist(struct commend_list lst);
unsigned int max_between_codes(unsigned int a,unsigned int b);
void print_com_arr( char** arr);
void history (struct commend_list lst,char** arr);
void reverse(struct commend_list_node** head);
void free_apt(struct apart* p);
void free_apt_lst(struct apart_list* lst);
void free_commends_arr(char**arr);
void free_commends_lst(struct commend_list* lst);
void free_all(struct apart_list* apt_lst,char** com_arr,struct commend_list* cmd_lst);
*/
#endif //SCHOOL_PROJECT_MAINHADDER_H
