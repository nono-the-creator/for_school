//
// Created by noam ambar on 04/05/2018.
//
#include <stdio.h>
#include "mainhadder.h"
//creates an apartment and returns a pointer to it,if theres no value insert -1.
struct apart* create_apart(unsigned int code,char *addr,int price,short int rooms,struct date date_of_entrance,struct apart* prev ,struct apart* next)
{
    time_t epoch;
    time(&epoch);
    struct apart* res_apart;
    res_apart=(struct apart*)malloc(sizeof(struct apart*));
    res_apart->next=next;
    res_apart->prev=prev;
    res_apart->addr=addr;
    res_apart->code=code;
    res_apart->price=price;
    res_apart->rooms=rooms;
    res_apart->date_of_entrance=date_of_entrance;
    res_apart->date_stamp.day=(short int)localtime(&epoch)->tm_mday;
    res_apart->date_stamp.month=(short int)localtime(&epoch)->tm_mon+(short int)1;
    res_apart->date_stamp.year=(short int)localtime(&epoch)->tm_year+(short int)1900;
    return res_apart;

}
//adding the apartment to the lists tail,fitting the proper code.
void add_apart_by_price(struct apart_list* lst,char *addr,int price,short int rooms,struct date date_of_entrance)
{
    bool replace_tail=false;
    struct apart* prev;
    struct apart* p;
    if(lst->head==NULL)
    {
       p=create_apart(1,addr,price,rooms,date_of_entrance,NULL,NULL);
       lst->head=p;
        lst->tail=p;
    }
    else
    {
        prev=find_prev(lst,price,&replace_tail);
        if(prev==NULL)//it means the new apart should be the head.
        {
            p=create_apart(max_code++,addr,price,rooms,date_of_entrance,NULL,lst->head);
            lst->head=p;
        }
        else {
            p = create_apart(max_code++, addr, price, rooms, date_of_entrance, prev, prev->next);
            lst->tail->next = p;
            lst->tail = p;
            if(replace_tail)
                lst->tail=p;
        }
    }
}
//finds the prev apart for the price of a new apartment.if the prev apartment is the head,returns NULL,if the prev apartment is the tail,returns the tail and changes replace_tail to true.
struct apart* find_prev(struct apart_list* lst,int price,bool* replace_tail)
{
    struct apart* p;
    p=lst->head;
    while(p!=NULL)
    {
        if(p->price>price&&p->prev!=NULL)
            return p->prev;
        if(p->price>price&&p->prev==NULL) //means the head has a smaller price,the new apartment needs to be the new head,returns null.
            return NULL;
        p=p->next;

    }
    *replace_tail=true;
    return lst->tail;//no apartment is more expensive,needs to be the new tail.replace_tail indicates the fact the tail needs to be replaced with the new apartment created.

}
//the "" is getting deleted in the print function.
void print_apart(struct apart apart1)
{
    printf("Code: %d \n",apart1.code);
    printf("Address: %s\b\n ",apart1.addr+1);
    printf("Number of rooms: %d \n",apart1.rooms);
    printf("Price: %d \n",apart1.price);
    printf("Entry date: %d.%d.%d \n",apart1.date_of_entrance.day,apart1.date_of_entrance.month,apart1.date_of_entrance.year);
    printf("Database entry date:%d.%d.%d \n",apart1.date_stamp.day,apart1.date_stamp.month,apart1.date_stamp.year);

}
//gets gets all the conditions and sends to the sorted print by sr.
void print_by_values(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce,bool sr)
{
    if(sr)
        print_by_values_up(lst,max_price,max_rooms,min_rooms,min_date_of_enternce);
    else
        print_by_values_down(lst,max_price,max_rooms,min_rooms,min_date_of_enternce);
}
// gets all the conditions,and prints the matching apartments,-1 symbols no condition.prints from lowest price to highest
void print_by_values_up(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce) {
    struct apart *p;
    p = lst.head;
    while (p != NULL) {
        if ((p->price < max_price || max_price == -1)) {
            if (p->rooms < max_rooms || max_rooms == -1) {
                if (p->rooms > min_rooms || min_rooms == -1) {
                    if (is_later(p->date_of_entrance, min_date_of_enternce) || min_date_of_enternce.day == -1) {
                        print_apart(*p);
                    }
                }
            }
        }
        p = p->next;
    }
}

// gets all the conditions,and prints the matching apartments,-1 symbols no condition.prints from highest price to lowest.
void print_by_values_down(struct apart_list lst,int max_price,int max_rooms,int min_rooms,struct date min_date_of_enternce)
{
    struct apart* p;
    p=lst.tail;
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
                        print_apart(*p);
                    }
                }
            }
        }
        p=p->prev;
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
    return false;//we will never get to this result.
}

struct date str_to_date(char *str)
{
	struct date ret;
	short int temp;
	temp = (short int)atoi(str);
	ret.year = temp%(short int)10000;
	temp/=10000;
	ret.month = temp%(short int)100;
	temp/=100;
	ret.day = temp%(short int)100;
	return ret;

}
void buy_apartment(struct apart_list* lst, unsigned int code)
{
	struct apart **p;
	struct apart *entry;
	p = &(lst->head);
	entry = lst->head;
	while(entry)
	{
		if(entry->code == code) //TODO:Add free
			*p = entry->next;
		p = &(entry->next);
		entry = entry->next;
	}
}
//prints the apartments,by minimum distance from currnet time,the distance is indicated by the variable "days_env"
void get_an_apart_enter(struct apart_list lst,int days_env)
{
    time_t treshhold=time(NULL);
    struct tm convertor;
    treshhold=treshhold-(days_env*24*60*60);//the minimum to get printed.
    time_t current_apart_epoch;
    struct apart* p;
    p=lst.head;
    while(p!=NULL)
    {
        convertor.tm_year=p->date_stamp.year;
        convertor.tm_mday=p->date_stamp.day;
        convertor.tm_mon=p->date_stamp.month;
        current_apart_epoch=mktime(&convertor);
        if(current_apart_epoch>treshhold)
        {
            print_apart(*p);
        }

        p=p->next;
    }
}
void delte_apart_in_env(struct apart_list* lst,int days_env)
{
    time_t treshhold=time(NULL);
    struct tm convertor;
    treshhold=treshhold-(days_env*24*60*60);//the minimum to get printed.
    time_t current_apart_epoch;
    struct apart* p;
    p=lst->head;
    while(p!=NULL)
    {
        make_empty_tm(&convertor);
        convertor.tm_year=p->date_stamp.year;
        convertor.tm_mday=p->date_stamp.day;
        convertor.tm_mon=p->date_stamp.month;
        current_apart_epoch=mktime(&convertor);
        if(current_apart_epoch>treshhold)
        {

            buy_apartment(lst,p->code);//because buy is actually deleting an apartment.
        }
        p=p->next;
    }
}
//gets a date and puts all the values to 0.
void make_empty_tm(struct tm* date)
{
    date->tm_mon=0;
    date->tm_mday=0;
    date->tm_year=0;
    //date->tm_gmtoff=0;
    date->tm_hour=0;
    date->tm_isdst=0;
    date->tm_min=0;
    date->tm_sec=0;
    date->tm_wday=0;
    //date->tm_zone=0;
    date->tm_yday=0;

}
void commends_saver(char* commend,char** recent_commends_array,struct commend_list* lst)
{
    struct commend_list_node* commend_list_node1;
    commend_list_node1=create_commend_list_node_and_add_to_head(recent_commends_array[7],lst);//adding the last commend in the array to the head of commend list.
    make_room_for_new_commend_in_array(recent_commends_array);
    recent_commends_array[0]=commend;

}
struct commend_list_node* create_commend_list_node_and_add_to_head(char* commend,struct commend_list* lst)
{
    struct commend_list_node* commend_list_node1;
    commend_list_node1=malloc(sizeof(struct commend_list_node));
    commend_list_node1->commend=commend;
    commend_list_node1->next=NULL;
    add_commend_list_node_to_head(commend_list_node1,lst);
    return commend_list_node1;
}
void add_commend_list_node_to_head(struct commend_list_node* commend_list_node1,struct commend_list* lst)
{
    if(lst->head==NULL)
    {
        lst->head=commend_list_node1;
        lst->tail=commend_list_node1;
    } else{
        commend_list_node1->next=lst->head;
        lst->head=commend_list_node1;
    }
}
//deletes the the oldest commend,and make the newest one NULL,so now new commend can be inserted.assuming size of array is 7.
void make_room_for_new_commend_in_array(char** recent_commends_array)
{
    int i;
    for(i=0;i<6;i++)
    {
        recent_commends_array[i+1]=recent_commends_array[i];
    }
    recent_commends_array[0]=NULL;
}
//given a number of a commend,send the commend to be executed.
void repeat_commend_by_number(int num, char** recent_commends_array,struct commend_list* c_lst,struct apart_list lst)
{
    int i=0;
    struct commend_list_node* p=c_lst->head;
    if(num<=7)
        interpert(recent_commends_array[num],lst,recent_commends_array,c_lst);
    else
    {
      while(i!=num&&p!=NULL)
      {
          p=p->next;
          i++;
      }
        if(p==NULL)
            return;
        interpert((p->commend),lst,recent_commends_array,c_lst);

    }
}
