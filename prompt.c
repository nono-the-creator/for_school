#include "mainhadder.h"

void interpert_add(char *str, struct apart_list lst)
{

	char *addr;
	int price,rooms;
	struct date dt;
	strtok(str, "\"");
	addr = strtok(str, "\"");
	price = atoi(strtok(NULL, " "));
	rooms = atoi(strtok(NULL, " "));
	dt.day = (short)atoi(strtok(NULL, " "));
	dt.month = (short)atoi(strtok(NULL, " "));
	dt.year = (short)atoi(strtok(NULL, " "));
	//call add with the paramters;
	add_apart_by_price(&lst, addr, price, rooms, dt);
}

void interpert_get(char *str, struct apart_list lst)
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
void interpert_buy(char *str, struct apart_list lst)
{
	//FIXME: might not work because lst is sent by value.
	unsigned int code;
	code = atoi(strtok(str, " "));
	buy_apartment(&lst, code);
	//call buy with the parameter;
}
void interpert_get_enter(char *str, struct apart_list lst)
{
	int days_env;
	days_env = atoi(strtok(str, " "));
	//call get_Enter with days_env;
	get_an_apart_enter(lst, days_env);

}

void interpert_del_enter(char *str, struct apart_list lst)
{
	int days_env;
	days_env = atoi(strtok(str, " "));
	//call del_Enter with days_env;
	//FIXME:might not work because lst is by value.
	delte_apart_in_env(&lst, days_env);
}

void interpert(char *str, struct apart_list lst, char **recent_commends_array, struct commend_list *clst)
{
	char *command;
	if(str[0]== '!')
	{
		repeat_commend_by_number(atoi(str+1), recent_commends_array, clst,lst);
	}
	commends_saver(str, recent_commends_array, clst);
	command = strtok(str, " ");
	if(strcmp(command, "get-an-apt") == 0)
	{
		interpert_get(str + strlen(command), lst);
	}
	else if(strcmp(command, "add-an-apt") == 0)
	{
		interpert_add(str + strlen(command), lst);
	}
	else if(strcmp(command, "buy-an-apt") == 0)
	{
		interpert_buy(str+strlen(command), lst);
	}
	else if(strcmp(command, "get-an-apt-Enter") == 0)
	{
		interpert_get_enter(str+strlen(command), lst);
	}
	else if(strcmp(command, "delete-an-apt-Enter") == 0)
	{
		interpert_del_enter(str+strlen(command), lst);
	}
	else
	{
		printf("Use a proper command!\n");
	}
}
