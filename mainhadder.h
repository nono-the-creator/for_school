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
void interpet(char **);


//db queries
void print_aprt(int maxPrice, int maxRooms, int minRooms, struct date maxDate, bool flag);
bool is_later (struct date date1,struct date date2) ;
void print_by_values(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce);
void print_apart(struct apart apart1);
struct apart* create_apart(unsigned int code,char *addr,int price,short int rooms,struct date date_of_entrance,struct apart* next);
void add_apart_to_last(struct apart_list* lst,char *addr,int price,short int rooms,struct date date_of_entrance);
void get_an_apart_enter(struct apart_list lst,int days_env);
/*
 *
 * input: max price, rooms range and the latest date to enter the apartment.
 * -1 means ignoring the requirement,
 * output: prints all the apartment that suits the requirements.
 */

struct date str_to_date (char *str);

#endif //SCHOOL_PROJECT_MAINHADDER_H
