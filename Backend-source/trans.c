/*
Copyright (C) 2009 Puneet Singh

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"trans.h"

int main(int a,char *b[])
{
	FILE *f;
	char *c;//Read whole file and put the text in this string
	
	setlocale(LC_CTYPE, "");
	if(a==3)
	{
		f=fopen(b[2],"r");
		c=readfilestr(f);
		setlocale(LC_CTYPE, "");
		retWord(c);
	}
	else if(a==2)
	{
		if(strcmp("-f",b[1])==0)
		printf("\n%s: no file as input\n",b[0]);
		setlocale(LC_CTYPE, "");
		retWord(b[1]);
	}
	else
	printf("\nUsage: %s [option] [String/File]\n",b[0]);
	
return 0;
}
