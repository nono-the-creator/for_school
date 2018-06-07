#ifndef __IO_H
#define __IO_H
#include "mainhadder.h"
void save_apartments(struct apart_list lst);
struct apart_list read_apartments();
void free_all(struct apart_list* apt_lst,char** com_arr,struct commend_list* cmd_lst);
#endif 
