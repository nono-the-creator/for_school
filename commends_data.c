//
// Created by noam ambar on 01/06/2018.
#include "mainhadder.h"
void commends_saver(char* commend,char** recent_commends_array,struct commend_list* lst)
{
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
    for(i=6;i>0;i--)
    {
        recent_commends_array[i]=recent_commends_array[i-1];
    }
    recent_commends_array[0]=NULL;
}

//given a number of a commend,send the commend to be executed.
void repeat_commend_by_number(int num, char** recent_commends_array,struct commend_list* c_lst,struct apart_list* lst)
{
    int i=0;
    struct commend_list_node* p=c_lst->head;
    if(num<=7)
        interpert(recent_commends_array[num], lst, recent_commends_array, c_lst);

    else
    {
        while(i!=num&&p!=NULL)
        {
            p=p->next;
            i++;
        }
        if(p==NULL)
            return;
        interpert((p->commend), lst, recent_commends_array, c_lst);

    }
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
    initialize_commends_to_null(c_lst,recent_commends_arr);
    FILE* file;
    file=fopen("commmends_file","rt");
    int i;
    struct commend_list_node * p;
    p=c_lst->head;
    for(i=0;i<RECENT_COMMENDS_SIZE;i++)
    {
        fputs(recent_commends_arr[i],file);
    }
    while(p!=NULL)
    {
        fputs(p->commend,file);
        p = p->next;
    }
    fclose(file);
}
void read_commends_from_file(struct commend_list* c_lst,char** recent_commends_arr)
{
    FILE* file;
    file=fopen("commmends_file","wt");
    int i;
    struct commend_list_node * p;
    p=c_lst->head;
    for(i=0;i<RECENT_COMMENDS_SIZE;i++)
    {
        fgets(recent_commends_arr[i],MAXLINE,file);
    }
    while(p!=NULL)
    {
        fgets(p->commend,MAXLINE,file);
        p = p->next;
    }
    fclose(file);
}