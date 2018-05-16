#include <stdio.h>
#include "mainhadder.h"

int main() {

	struct apart_list aprtlst;
	struct commend_list cmdlst;
	char command[128];
	char **commend_array;
	max_code = 0;
	aprtlst.head = aprtlst.tail = NULL; //remove
	cmdlst.head = cmdlst.tail = NULL; //remove
	commend_array = malloc(sizeof(char *)* 7);
    gets(command);
    while(strcmp(command, "exit"))
	{
		 gets(command);
		interpert(command, aprtlst, commend_array, &cmdlst);


	}




    return 0;
}
