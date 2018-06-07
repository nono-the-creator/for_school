#include <stdio.h>
#include "mainhadder.h"

int main() {

    int commends_amount=0;
    struct apart_list aprtlst;
	struct commend_list cmdlst;
	char command[128];
	char **commend_array;
	commends_amount = 0;
	aprtlst = read_apartments();
    commend_array = malloc(sizeof(char *)* 7);
    initialize_commends_to_null(&cmdlst,commend_array);
    read_commends_from_file(&cmdlst,commend_array);
    reverse(&(cmdlst.head));
    printf("Please enter one of the following commands:\n""add-an-apt, get-an-apt, buy-an-apt or delete-an-apt\n""For reconstruction commands, please enter:\n""!!, !num, history, short_history or !num^str1^str2\nTo exit, enter exit.");
    printf("\n>>");
    gets(command);
    while(strcmp(command, "exit"))
	{
		interpert(command, &aprtlst, commend_array, &cmdlst);
		printf(">> ");
		gets(command);
    }
    save_commends_to_file(&cmdlst,commend_array);
	save_apartments(aprtlst);
    return 0;
}
