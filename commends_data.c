//
// Created by noam ambar on 01/06/2018.
#include "commends.h"
#include "commends_data.h"
#include "io.h"
#include "prompt.h"
void add_commend_list_node_to_tail(struct commend_list_node* commend_list_node1,struct commend_list* lst);
void commends_saver(char* commend,char** recent_commends_array,struct commend_list* lst)
{
    commends_amount++;
    create_commend_list_node_and_add_to_head(recent_commends_array[6],lst);//adding the last commend in the array to the head of commend list.
    make_room_for_new_commend_in_array(recent_commends_array);
    recent_commends_array[0]=commend;

}
void create_commend_list_node_and_add_to_head(char* commend,struct commend_list* lst)
{
    if(commend==NULL)
        return;
    struct commend_list_node* commend_list_node1;
    commend_list_node1=(struct commend_list_node*)malloc(sizeof(struct commend_list_node));
    commend_list_node1->commend=commend;
    commend_list_node1->next=NULL;
    add_commend_list_node_to_head(commend_list_node1,lst);
}
void add_commend_list_node_to_tail(struct commend_list_node* commend_list_node1,struct commend_list* lst)
{
    if(lst->head==NULL)
    {
        lst->head=commend_list_node1;
        lst->tail=commend_list_node1;
    } else{
            lst->tail->next=commend_list_node1;
            lst->tail=commend_list_node1;
    }
}
//deletes the the oldest commend,and make the newest one NULL,so now new commend can be inserted.assuming size of array is 7.
void make_room_for_new_commend_in_array(char** recent_commends_array)
{
    int i;
    for(i=6;i>0;i--)
    {
        recent_commends_array[i]=recent_commends_array[i-1];
    }
    recent_commends_array[0]=NULL;
}

//given a number of a commend,send the commend to be executed.
void repeat_commend_by_number(char *init, char** recent_commends_array,struct commend_list* c_lst,struct apart_list* lst)
 {
     int i=0;
	int num;
	char *substring1 = NULL, *substring2 = NULL;
	char *new;
	char buff[MAXLINE];
	 if(init[0] == '\0')
		 return;
	 if(init[0] == '!')
		 num = 1;
	else if(!strstr(init, "^"))
		num = atoi(init);
	else
	{
		num = atoi(strtok(init, "^"));
		substring1 = strtok(NULL, "^");
		substring2 = strtok(NULL, "^");
	}
     num=commends_amount-num;//reaches the "num" oldest commend in the data base.
     struct commend_list_node* p=c_lst->head;
	 if(num<=7)
		 strcpy(buff,recent_commends_array[num]);
	 else
	{
		 for(int i=0;i<num-7;i++)
		 {
			 if(p) p = p->next;
		 }
		strcpy(buff, p->commend);
	}
	 printf(KRED "The amount is %d, buff is %s" KNRM "\n",commends_amount, buff);
	if(!substring1)
		interpert(buff, lst, recent_commends_array, c_lst);
	 else
	{
		new = str_replace(buff, substring1, substring2);
		interpert(new, lst, recent_commends_array, c_lst);
	}
    /* if(num<=7)
	{
		if(!substring1)
        	interpert(recent_commends_array[num], lst, recent_commends_array, c_lst);
		else
		{
			new = str_replace(recent_commends_array[num],substring1, substring2);
			interpert(new, lst, recent_commends_array, c_lst);
		}
	}*/
}
void initialize_commends_to_null(struct commend_list* c_lst,char** recent_commends_arr)
{
    int i;
    for(i=0;i< RECENT_COMMENDS_SIZE;i++)
    {
        recent_commends_arr[i]=NULL;
    }
    c_lst->head=NULL;
    c_lst->tail=NULL;
}
void save_commends_to_file(struct commend_list* c_lst,char** recent_commends_arr)
{

    FILE* file;
    file=fopen("commends_file","w");
    int i;
    struct commend_list_node * p;
    p=c_lst->head;
    for(i=0;i<RECENT_COMMENDS_SIZE;i++)
    {
        if(recent_commends_arr[i]!=NULL) {
            fputs(recent_commends_arr[i], file);
            fputc('\n',file);
        }
    }
    while(p!=NULL)
    {
        if(p->commend!=NULL) {
            fputs(p->commend, file);
           if(p->next!=NULL)
               fputc('\n',file);
           else
               fputc(' ',file);
        }
        p = p->next;
    }
    fclose(file);
}
void read_commends_from_file(struct commend_list* c_lst,char** recent_commends_arr)
{

    FILE* file;
    file=fopen("commends_file","rt");
    if(!file)
    {
        printf(KRED"no commend file exist"KNRM"\n");
        return;
    }
    char buffer[MAXLINE];
    int i,a,b;
    struct commend_list_node * p;
    p=c_lst->head;
    for(i=0;i<RECENT_COMMENDS_SIZE;i++)
    {

            fgets(buffer, MAXLINE, file);
        if(!feof(file)) {
            recent_commends_arr[i]=malloc(sizeof(char)*strlen(buffer));
            strcpy(recent_commends_arr[i],buffer);
            recent_commends_arr[i][strlen(buffer)-1]='\0';
            commends_amount++;
        }

    }
    while(!feof(file))
    {
        char*string;
        fgets(buffer, MAXLINE, file);
        string=malloc(sizeof(char)*strlen(buffer));
        strcpy(string,buffer);
        string[strlen(buffer)-1]='\0';
        create_commend_list_node_and_add_to_head(string,c_lst);
        commends_amount++;
    }
    fclose(file); }
void printlist(struct commend_list lst)
{
    int j=1;
    struct commend_list_node *p;
    reverse(&lst.head);
    p=lst.head;
    while (p!=NULL)
    {
        printf("%d:%s\n",j,p->commend);
        p=p->next;
        j++;
    }
    reverse(&lst.head);
}
void print_com_arr(char** arr)
{
  int i,j=commends_amount-6,lsize;
    if(commends_amount<7)
    {
        lsize=commends_amount;
        j=1;
    } else
        lsize=RECENT_COMMENDS_SIZE - 1;
    for(i=lsize;i>-1;i--)
    {
        if(arr[i]!=NULL)
         printf("%d:%s\n",j++,arr[i]);
    }
}
void history (struct commend_list lst,char** arr)
{
    printlist(lst);
    print_com_arr(arr);

}
void add_commend_list_node_to_head(struct commend_list_node* commend_list_node1,struct commend_list* lst)
{
    if(lst->head==NULL)
    {
        lst->head=commend_list_node1;
        lst->tail=commend_list_node1;
    }
    else{
        commend_list_node1->next=lst->head;
        lst->head=commend_list_node1;
    }
}
//gets a pointer to the head and reverse the list.
void reverse(struct commend_list_node** head)
{
    struct commend_list_node* prev  = NULL;
    struct commend_list_node* current = *head;
    struct commend_list_node* next = NULL;
    while (current != NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void free_commends_lst(struct commend_list* lst)
{
    struct commend_list_node* p=lst->head;
    while(p!=NULL)
    {
        free(p->commend);
        p=p->next;
    }
}
void free_commends_arr(char**arr)
{
    int i;
    for(i=0;i<RECENT_COMMENDS_SIZE;i++)
    {
        free(arr[i]);
    }
    free(arr);
}

