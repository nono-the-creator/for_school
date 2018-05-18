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

unsigned int max_code;
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
char **GetString(char *);

void interpert(char *str, struct apart_list lst, char **recent_commends_array, struct commend_list *clst);

//db queries
void print_aprt(int maxPrice, int maxRooms, int minRooms, struct date maxDate, bool flag);
bool is_later (struct date date1,struct date date2) ;
void print_by_values_down(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce);
void print_by_values_up(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce);
void print_apart(struct apart apart1);
struct apart* create_apart(unsigned int code,char *addr,int price,short int rooms,struct date date_of_entrance,struct apart* next,struct apart* prev);
void add_apart_by_price(struct apart_list* lst,char *addr,int price,short int rooms,struct date date_of_entrance);
struct apart* find_prev(struct apart_list* lst,int price,bool* replace_tail);
void get_an_apart_enter(struct apart_list lst,int days_env);
void buy_apartment(struct apart_list* lst, unsigned int code);
void make_empty_tm(struct tm* date);
void make_room_for_new_commend_in_array(char** recent_commends_array);
struct commend_list_node* create_commend_list_node_and_add_to_head(char* commend,struct commend_list* lst);
void commends_saver(char* commend,char** recent_commends_array,struct commend_list* lst);
void add_commend_list_node_to_head(struct commend_list_node* commend_list_node1,struct commend_list* lst);
void repeat_commend_by_number(int num, char** recent_commends_array,struct commend_list* c_lst,struct apart_list lst);

/*
 *
 * input: max price, rooms range and the latest date to enter the apartment.
 * -1 means ignoring the requirement,
 * output: prints all the apartment that suits the requirements.
 */

struct date str_to_date (char *str);
void delte_apart_in_env(struct apart_list* lst,int days_env);

#endif //SCHOOL_PROJECT_MAINHADDER_H
