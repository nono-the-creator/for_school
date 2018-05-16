/*
 * This file contains the functions that interact with the FS
 */

#include "mainhadder.h"

void save_apartments(struct apart_list lst)
{
	int len;
	unsigned char binary;
	FILE *fp;
	struct apart *p;
	fp = fopen("apartments.db", "rb");
	p = lst.head;
	while(p)
	{
		fwrite(&(p->code),sizeof(short int), 1, fp );
		len = strlen(p->addr);
		fwrite(&len, sizeof(short int), 1, fp);
		fwrite(p->addr, len, 1, fp);
		fwrite(&(p->price), sizeof(int), 1, fp);
		binary = ((p->rooms)>>4) |(p->date_of_entrance.day >> 3);
		fwrite(&binary, 1, 1, fp);

		p = p->next;
	}
}
