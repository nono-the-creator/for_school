#include "mainhadder.h"

char *get_dyn()
{
	char *ret;
	char ch;
	int logic=0,phy=2;
	ret = malloc(sizeof(char) *phy );
	ch = getchar();
	do
	{
		if(logic>=phy)
		{
			phy*=2;
			ret = realloc(ret, sizeof(char)*phy);
		}
		ret[logic] = ch;
		logic++;
		ch = getchar();
	}while(ch!='\n');
	ret[logic] = '\0';
	printf(KRED "The returned string is: %s" KNRM "\n",ret);
	ret =realloc(ret, sizeof(char)*logic);
	return ret;
}

void interpert_add(char *str, struct apart_list *lst)
{

	char *addr, *_addr;
	int adrlen;
	int price,rooms;
	struct date dt, st;
	//strtok(str, "\"");
	_addr = strtok(str, "\"");
	adrlen = strlen(_addr);
	addr = malloc(sizeof(char) * (adrlen + 1));
	strcpy(addr, _addr);
	addr[adrlen + 1] = '\0';
	price = atoi(strtok(NULL, " "));
	rooms = atoi(strtok(NULL, " "));
	dt.day = (short)atoi(strtok(NULL, " "));
	dt.month = (short)atoi(strtok(NULL, " "));
	dt.year = (short)atoi(strtok(NULL, " "));
	st.year = -1;

	//call add with the paramters;
	printf(KRED "created: addr: %s, price: %d, rooms: %d, day: %d, month: %d, year: %d"KNRM"\n", addr, price, rooms, dt.day, dt.month, dt.year);
	add_apart_by_price(lst, addr, price, rooms, dt, -1, st);
}

void interpert_get(char *str, struct apart_list lst)
{
	int max_price=-1, max_rooms=-1, min_rooms=-1;
	bool sort = true;
	struct date min_date;
	min_date.day = -1;
	str[strlen(str)]= ' ';
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
		else if(strcmp(p, "-sr") == 0)
		{
			p = strtok(NULL, " ");
			sort = false;
		}
		p = strtok(NULL, " ");
	}
	// call the print function with the proper paramters
	printf(KRED "Sending print with price: %d, max_rooms: %d, min_rooms: %d, sort: %d, date: %d-%d-%d" KNRM "\n", max_price, max_rooms, min_rooms,sort, min_date.day,min_date.month,min_date.year);
	print_by_values(lst, max_price, max_rooms, min_rooms, min_date, sort);
}
void interpert_buy(char *str, struct apart_list *lst)
{
	//FIXME: might not work because lst is sent by value.
	unsigned int code;
	code = atoi(strtok(str, " "));
	buy_apartment(lst, code);
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

char *str_replace(char *str, char *orig, char *rep)
{
	char *ret;
	char *ind;
	unsigned lenstr, lenorig, lenrep, lenind;
	lenstr = strlen(str);
	lenorig = strlen(orig);
	lenrep = strlen(rep);
	ret = malloc( sizeof(char) *(lenstr + lenrep - lenorig));
	ind = strstr(str, orig);
	if(!ind) return NULL;
	lenind = strlen(ind);
	strncpy(ret, str, lenstr - lenind);
	strcpy(ret + lenstr - lenind, rep);
	strcpy(ret + lenstr - lenind + lenrep, ind + lenorig );

	printf(KRED "The string is now: %s" KNRM "\n", ret);


	return ret;
}

void interpert(char *str, struct apart_list *lst, char **recent_commends_array, struct commend_list *clst)
{
	char *command;
	char *copy;
	if(str==NULL) {
		printf("Use a proper command!\n");
		return;
	}

	if(strstr(str, "short_history"))
	{
		print_com_arr(recent_commends_array);
		return;
	}
	if(strstr(str, "history"))
	{
		history( *clst, recent_commends_array);
		return;
	}

	printf(KRED "Command entered: %s\n" KNRM, str); //DEBUG
	if(!str) return;
	if(str[0]== '!')
	{
		repeat_commend_by_number(str+1, recent_commends_array, clst, lst);
		return;
	}
	copy = malloc(sizeof(char) * strlen(str) + 1);
	strcpy(copy, str);
	commends_saver(copy, recent_commends_array, clst);
	command = strtok(str, " ");
	printf(KRED "Current string %s\n" KNRM, command);
	if(strcmp(command, "get-an-apt") == 0)
	{
		interpert_get(str + strlen(command) + 1, *lst);
	}
	else if(strcmp(command, "add-an-apt") == 0)
	{
		interpert_add(str + strlen(command) + 1, lst);
	}
	else if(strcmp(command, "buy-an-apt") == 0)
	{
		interpert_buy(str+strlen(command) + 1, lst);
	}
	else if(strcmp(command, "get-an-apt-Enter") == 0)
	{
		interpert_get_enter(str+strlen(command) + 1, *lst);
	}
	else if(strcmp(command, "delete-an-apt-Enter") == 0)
	{
		interpert_del_enter(str+strlen(command) + 1, *lst);
	}
	else
	{
		printf("Use a proper command!\n");
	}
}
