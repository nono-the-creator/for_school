#include <stdio.h>
#include "mainhadder.h"

int main() {

	struct apart_list aprtlst;
	struct commend_list cmdlst;
	char command[128];
	char **commend_array;
	char *temp; //DEBUG
	max_code = 0;
	aprtlst.head = aprtlst.tail = NULL; //remove
	aprtlst = read_apartments();
	commend_array = malloc(sizeof(char *)* 7);
    //read_commends_from_file(&cmdlst,commend_array);
    printf(">> ");
    gets(command);
    while(strcmp(command, "exit"))
	{
		interpert(command, &aprtlst, commend_array, &cmdlst);
		printf(">> ");
		gets(command);

	}
	//save_commends_to_file(&cmdlst,commend_array);

    return 0;
}
