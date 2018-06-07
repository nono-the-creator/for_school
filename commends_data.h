#ifndef __COMMENDS_DATA_H
#define __COMMENDS_DATA_H
#include "mainhadder.h"
void add_commend_list_node_to_tail(struct commend_list_node* commend_list_node1,struct commend_list* lst);
void commends_saver(char* commend,char** recent_commends_array,struct commend_list* lst);
void create_commend_list_node_and_add_to_head(char* commend,struct commend_list* lst);

void add_commend_list_node_to_tail(struct commend_list_node* commend_list_node1,struct commend_list* lst);
void make_room_for_new_commend_in_array(char** recent_commends_array);

void repeat_commend_by_number(char *init, char** recent_commends_array,struct commend_list* c_lst,struct apart_list* lst);

void initialize_commends_to_null(struct commend_list* c_lst,char** recent_commends_arr);

void save_commends_to_file(struct commend_list* c_lst,char** recent_commends_arr);

void read_commends_from_file(struct commend_list* c_lst,char** recent_commends_arr);

void printlist(struct commend_list lst);

void print_com_arr(char** arr);

void history (struct commend_list lst,char** arr);

void add_commend_list_node_to_head(struct commend_list_node* commend_list_node1,struct commend_list* lst);
void reverse(struct commend_list_node** head);

void free_commends_lst(struct commend_list* lst);

void free_commends_arr(char**arr);
#endif 
