#include <stdio.h>
#include "mainhadder.h"

int main() {

	struct apart_list aprtlst;
	struct commend_list cmdlst;
	char *command;
	char **commend_array;
	aprtlst.head = aprtlst.tail = NULL; //remove
	cmdlst.head = cmdlst.tail = NULL; //remove
	commend_array = malloc(sizeof(char *)* 7);
	while(!strcmp(command, "exit"))
	{
		command = gets();
		interpert(command, aprtlst, commend_array, &cmdlst);


	}




    return 0;
}
