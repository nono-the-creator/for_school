#include "mainhadder.h"

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
