/*
 * This file contains the functions that interact with the FS
 */

#include "mainhadder.h"

void print_binary(char c)
{
	int i;
	int mask;
	printf(KRED);
	for (i = 7; i >= 0; i--)
	{
		mask = 1 << i;
		putchar((c & mask) ? '1' : '0');
		if (i % 4 == 0)
			putchar(' ');
	}
	printf(KNRM "\n");
}

void save_apartments(struct apart_list lst)
{
	short int len;
	unsigned char binary;
	FILE *fp;
	struct apart *p;
	fp = fopen("apartments.db", "wb");
	p = lst.head;
	while(p)
	{
		fwrite(&(p->code),sizeof(short int), 1, fp );
		len = strlen(p->addr);
		fwrite(&len, sizeof(short int), 1, fp);
		fwrite(p->addr, len, 1, fp);
		fwrite(&(p->price), sizeof(int), 1, fp);
		binary = 0;
		binary = ((p->rooms)<<4) |(p->date_of_entrance.day >> 1);
		print_binary(binary);
		fwrite(&binary, 1, 1, fp);
		binary = 0;
		binary = ((p->date_of_entrance.day << 7) | (p->date_of_entrance.month << 3) | (p->date_of_entrance.year >> 4));
		print_binary(binary);
		fwrite(&binary, 1, 1, fp);
		binary = 0;
		binary = p->date_of_entrance.year << 4;
		print_binary(binary);
		fwrite(&binary, 1, 1, fp);
		binary = 0;
		printf(KRED "date time on write: %d-%d-%d" KNRM "\n", p->date_stamp.day, p->date_stamp.month, p->date_stamp.year);
		binary = ((p->date_stamp.day << 3) | (p->date_stamp.month >> 1));
		print_binary(binary);
		fwrite(&binary, 1, 1, fp);
		binary = 0;
		binary = ((p->date_stamp.month << 7) | (p->date_stamp.year >> 1));
		print_binary(binary);
		fwrite(&binary, 1, 1, fp);

		p = p->next;
	}
}
struct apart_list read_apartments()
{
	struct apart_list ret;
	char *addr;
	unsigned int code;
	int price, rooms;
	short int len;
	struct date entdate, date_stamp;
	FILE *fp;
	unsigned char binary1, binary2, binary3;
	int rflag;
	ret.head = NULL;
	ret.tail = NULL;
	fp = fopen("apartments.db", "rb");
	if(!fp)
	{
		printf(KRED "apartments file doesn't exist" KNRM "\n");
		return ret;
	}
	while(1)
	{
		rflag = fread(&code, sizeof(short int), 1, fp);
		if(!rflag) break;
		fread(&len, sizeof(short int), 1, fp);
		addr = malloc(sizeof(char) * len + 1);
		fread(addr,sizeof(char), len,fp);
		addr[len] = '\0';
		fread(&price, sizeof(int), 1, fp);
		fread(&binary1, 1, 1, fp);
		fread(&binary2, 1, 1, fp);
		fread(&binary3, 1, 1, fp);
		rooms = binary1 >> 4;
		entdate.day = ((binary1 << 1) & 0x1E) | binary2>>7;
		entdate.month = ((binary2 >> 3) & 0x0F);
		entdate.year = ((binary2 << 4) & 0x70) | binary3>>4;

		fread(&binary1, 1, 1, fp);
		fread(&binary2, 1, 1, fp);
		print_binary(binary1);
		print_binary(binary2);
		date_stamp.day = binary1 >> 3;
		date_stamp.month = (0x07 & binary1) << 1 | binary2 >> 7;
		date_stamp.year = (binary2 & 0x7F);
		printf(KRED "%d: %d, %d, %d" KNRM "\n", rooms, entdate.day, entdate.month, entdate.year);
		printf(KRED "Date stamp: %d-%d-%d" KNRM "\n", date_stamp.day, date_stamp.month, date_stamp.year);

		add_apart_by_price(&ret, addr, price, rooms, entdate, code, date_stamp);

	}
	return ret;
}
