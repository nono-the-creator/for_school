#include <stdio.h>
#include "mainhadder.h"

int main() {

	struct apart_list aprtlst;
	struct commend_list cmdlst;
	char command[128];
	char **commend_array;
	aprtlst.head = aprtlst.tail = NULL; //remove
	aprtlst = read_apartments();
    commend_array = malloc(sizeof(char *)* 7);
    initialize_commends_to_null(&cmdlst,commend_array);
    //read_commends_from_file(&cmdlst,commend_array);
    printf(">> ");
    gets(command);
    while(strcmp(command, "exit"))
	{
		interpert(command, &aprtlst, commend_array, &cmdlst);
		printf(">> ");
		gets(command);

	}
    save_commends_to_file(&cmdlst,commend_array);

    return 0;
}
