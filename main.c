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
	printf(">> ");
    gets(command);
    while(strcmp(command, "exit"))
	{
		interpert(command, &aprtlst, commend_array, &cmdlst);
		printf(">> ");
		gets(command);

	}




    return 0;
}
