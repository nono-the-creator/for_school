//
// Created by noam ambar on 04/05/2018.
//
#include <stdio.h>
#include "mainhadder.h"
//creates an apartment and returns a pointer to it.
struct apart* create_apart(unsigned int code,char *addr,int price,short int rooms,struct date date_of_entrance,struct apart* next)
{
    time_t epoch;
    time(&epoch);
    struct apart* res_apart;
    res_apart=(struct apart*)malloc(sizeof(struct apart*));
    res_apart->next=next;
    res_apart->addr=addr;
    res_apart->code=code;
    res_apart->price=price;
    res_apart->rooms=rooms;
    res_apart->date_of_entrance=date_of_entrance;
    res_apart->date_stamp.day=(short int)localtime(&epoch)->tm_mday;
    res_apart->date_stamp.month=(short int)localtime(&epoch)->tm_mon;
    res_apart->date_stamp.year=(short int)localtime(&epoch)->tm_year;
    return res_apart;

}
void print_apart(struct apart apart1)
{
    printf("Code: %d \n",apart1.code);
    printf("Address: %s \n",apart1.addr);
    printf("Number of rooms: %d \n",apart1.rooms);
    printf("Price: %d \n",apart1.price);
    printf("Entry date: %d.%d.%d \n",apart1.date_of_entrance.day,apart1.date_of_entrance.month,apart1.date_of_entrance.year);
    printf("Database entry date:%d.%d.%d \n",apart1.date_stamp.day,apart1.date_stamp.month,apart1.date_stamp.year);

}
// gets all the conditions,and prints the matching apartments,-1 symbols no condition.
void print_by_values(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce)
{
    struct apart* p;
    p=lst.head;
    while(p!=NULL)
    {
        if((p->price<max_price||max_price==-1))
        {
            if(p->rooms<max_rooms||max_rooms==-1)
            {
                if(p->rooms>min_rooms||min_rooms==-1)
                {
                    if(is_later(p->date_of_entrance,min_date_of_enternce)||min_date_of_enternce.day==-1)
                    {

                    }
                }
            }
        }
        p=p->next;
    }

}
//if date1 is later or the same as date2 return true.
bool is_later (struct date date1,struct date date2) {
    if (date1.year > date2.year)
        return true;
    if (date1.year < date2.year)
        return false;
    if (date1.month > date2.month)
        return true;
    if (date1.month < date2.month)
        return false;
    if (date1.day >= date2.day)
        return true;
    if (date1.day < date2.day)
        return false;
}
