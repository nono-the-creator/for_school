//
// Created by noam ambar on 04/05/2018.
//

#ifndef SCHOOL_PROJECT_MAINHADDER_H
#define SCHOOL_PROJECT_MAINHADDER_H
#include<stdbool.h>
#include <stdio.h>
#include <time.h>
#include<stdlib.h>
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
/*
 *
 * input: max price, rooms range and the latest date to enter the apartment.
 * -1 means ignoring the requirement,
 * output: prints all the apartment that suits the requirements.
 */


#endif //SCHOOL_PROJECT_MAINHADDER_H
