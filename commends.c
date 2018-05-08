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
    if (date1.year >= date2.year)
        return true;
    if (date1.year < date2.year)
        return false;
    if (date1.month >= date2.month)
        return true;
    if (date1.month < date2.month)
        return false;
    if (date1.day >= date2.day)
        return true;
    if (date1.day < date2.day)
        return false;
}

char *gets_dynamic()
{
	char *ret;
	char ch;
	int size, physize;
	size = 0;
	physize = 2;
	ret = malloc(sizeof(char)*physize);
	ch = getchar();
	while(ch!='\n')
	{
		if(size >= physize)
		{
			physize*=2;
			ret = realloc(ret, sizeof(char)*physize);
		}
		ret[size] = ch;
		size++;
	}
	return ret;
}

struct date str_to_date(char *str)
{
	struct date ret;
	int temp;
	temp = atoi(str);
	ret.year = temp%10000;
	temp/=10000;
	ret.month = temp%100;
	temp/=100;
	ret.day = temp%100;
	return ret;

}

void interpert_get(char *str)
{
	int max_price, max_rooms, min_rooms;
	struct date min_date;
	char *p;
	p = strtok(str, " ");
	while(p)
	{
		if(strcmp(p,"-MaximumPrice") == 0)
		{
			p = strtok(NULL, " ");
			max_price = atoi(p);

		}
		else if(strcmp(p, "-MinimumNumRooms") == 0)
		{
			p = strtok(NULL, " ");
			min_rooms = atoi(p);
		}
		else if(strcmp(p, "-MaximumNumRooms") == 0)
		{
			p = strtok(NULL, " ");
			max_rooms = atoi(p);

		}
		else if(strcmp(p, "-Date") == 0)
		{
			p = strtok(NULL, " ");
			min_date = str_to_date(p);
		}
		p = strtok(NULL, " ");
	}
	// call the print function with the proper paramters
}

void interpert_add(char *str)
{
	char *addr;
	int price,rooms;
	struct date dt;
	addr = strtok(str, " ");
	price = atoi(strtok(NULL, " "));
	rooms = atoi(strtok(NULL, " "));
	//call add with the paramters;
}
void buy_apartment(struct apart_list lst, unsigned int code)
{
	struct apart **p;
	struct apart *entry;
	p = &(lst.head);
	entry = lst.head;
	while(entry)
	{
		if(entry->code == code) //TODO:Add free
			*p = entry->next;
		p = &(entry->next);
		entry = entry->next;
	}
}
void interpert_buy(char *str)
{
	unsigned int code;
	code = atoi(strtok(str, " "));
	//call buy with the parameter;
}
void interpert_get_enter(char *str)
{
	int days_env;
	days_env = atoi(strtok(str, " "));
	//call get_Enter with days_env;

}

void interpert(char *str)
{
	char *command;
	command = strtok(str, " ");
	if(strcmp(command, "get-an-apt") == 0)
	{
		interpert_get(str + strlen(command));
	}
	else if(strcmp(command, "add-an-apt") == 0)
	{
		interpert_add(str + strlen(command));
	}
	else if(strcmp(command, "buy-an-apt") == 0)
	{
		interpert_buy(str+strlen(command));
	}
	else if(strcmp(command, "get-an-apt-Enter") == 0)
	{
		interpert_get_enter(str+strlen(command));
	}
	else if(strcmp(command, "delete-an-apt-Enter") == 0)
	{
		//deal with delete an apartment
	}
	else
	{
		printf("Use a proper command!\n");
	}
}
