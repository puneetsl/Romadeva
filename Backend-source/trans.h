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
#include <locale.h>
#include <ctype.h>
/*
 * to do 
 * */
int file_length(FILE *f)
{
    int pos;
    int end;

    pos = ftell (f);
    fseek (f, 0, SEEK_END);
    end = ftell (f);
    fseek (f, pos, SEEK_SET);

    return end;
}
char *readfilestr(FILE *f)
{
    char *r;
    r=(char *)malloc(file_length(f)+1);
    fread(r,file_length(f),1,f);
    rewind(f);
    r[strlen(r)-1]=0;
    return r;
}
wchar_t retIndicChar(int psciiCode)
{
    wchar_t ret= L'\u0900';
    setlocale(LC_CTYPE, "");
    return (psciiCode+ret);
}// this function will return indic charachter on providing an integer value
int isconsonent(char verify)
{
    if (verify=='a'||verify=='e'||verify=='i'||verify=='o'||verify=='u')
        return 0;
    return 1;
}// will return 0 if charachter in wovel else 1
int swar(char a,char b)
{
	switch(a)
	{
		case 'a':
			switch(b)
			{
				case 'a':
					printf("%lc",retIndicChar(6));//aa
					return 1;
				case 'e':
					printf("%lc",retIndicChar(5));//a
					return 0;
				case 'i':
					printf("%lc",retIndicChar(16));//ai
					return 1;
				case 'o':
					printf("%lc",retIndicChar(5));//a
					return 0;				
				case 'u':
					printf("%lc",retIndicChar(20));//au
					return 1;
				case 0:
					printf("%lc",retIndicChar(5));//a
					return 1;
			}
			break;
		case 'e':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(15));//e
					return 1;
				case 'e':
					printf("%lc",retIndicChar(8));//ee
					return 1;
				case 'a': case 'i': case 'o': case 'u':
					printf("%lc",retIndicChar(15));//e
					return 0;
			}
			break;
		case 'i':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(7));//i
					return 1;
				case 'i':
					printf("%lc",retIndicChar(8));//ii
					return 1;
				case 'a': case 'e': case 'o': case 'u':
					printf("%lc",retIndicChar(7));//i
					return 0;
			}
			break;
		case 'o':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(19));//o
					return 1;
				case 'o':
					printf("%lc",retIndicChar(10));//oo
					return 1;
				case 'a': case 'i': case 'e': case 'u':
					printf("%lc",retIndicChar(19));//o
					return 0;
			}
			break;
		case 'u':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(9));//u
					return 1;
				case 'e':
					printf("%lc",retIndicChar(10));//uu
					return 1;
				case 'a': case 'i': case 'o': case 'e':
					printf("%lc",retIndicChar(9));//u
					return 0;
			}
			break;
		default:
			return 0;
	}
	return 0;
}
int wovel(char a,char b)
{
	switch(a)
	{
		case 'a':
			switch(b)
			{
				case 'a':
					printf("%lc",retIndicChar(62));//aa
					return 1;
				case 'e':
					return 0;
				case 'i':
					printf("%lc",retIndicChar(72));//ai
					return 1;
				case 'o':
					return 0;				
				case 'u':
					printf("%lc",retIndicChar(76));//au
					return 1;
				case 0:
					return 1;
				default:
					return 1;
			}
		case 'e':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(71));//e
					return 1;
				case 'e':
					printf("%lc",retIndicChar(64));//ee
					return 1;
				case 'a': case 'i': case 'o': case 'u':
					printf("%lc",retIndicChar(71));//e
					return 0;
			}
		case 'i':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(63));//i
					return 1;
				case 'i':
					printf("%lc",retIndicChar(64));//ii
					return 1;
				case 'a': case 'e': case 'o': case 'u':
					printf("%lc",retIndicChar(63));
					return 0;
			}
		case 'o':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(75));//o
					return 1;
				case 'o':
					printf("%lc",retIndicChar(66));//oo
					return 1;
				case 'a': case 'i': case 'e': case 'u':
					printf("%lc",retIndicChar(75));//o
					return 0;
			}
		case 'u':
			switch(b)
			{
				case 0:
					printf("%lc",retIndicChar(65));//u
					return 1;
				case 'u':
					printf("%lc",retIndicChar(66));//uu
					return 1;
				case 'a': case 'i': case 'o': case 'e':
					printf("%lc",retIndicChar(65));//u
					return 0;
			}
	}
}
return 0;
}
int extra(char c)
{
	if(c==' ')
	{
		return 0;
	}
	else 
	return 1;
}
int tackle(char a,char b,char c, char d,char e)// returning in can return own made structure
{
	if(a=='k'||a=='g'||a=='j'||a=='p'||a=='b')
	{
		if(b=='h')
		{
			if(isconsonent(c)&&c!=0&&extra(c))
			{
				if(a=='k')
				printf("%lc%lc",retIndicChar(22),retIndicChar(77));//kh
				if(a=='g')
				printf("%lc%lc",retIndicChar(24),retIndicChar(77));//gh
				if(a=='j')
				printf("%lc%lc",retIndicChar(29),retIndicChar(77));//jh
				if(a=='p')
				printf("%lc%lc",retIndicChar(43),retIndicChar(77));//ph
				if(a=='b')
				printf("%lc%lc",retIndicChar(45),retIndicChar(77));//bh
				return 2;
			}
			
			else
			{
				if(a=='k')
				printf("%lc",retIndicChar(22));//k
				if(a=='g')
				printf("%lc",retIndicChar(24));//g
				if(a=='j')
				printf("%lc",retIndicChar(29));//j
				if(a=='p')
				printf("%lc",retIndicChar(43));//j
				if(a=='b')
				printf("%lc",retIndicChar(45));//j
				if(!extra(c))
				return 2;
				if(isconsonent(d))
				{
					
					wovel(c,0);
					return 3;
				}
				else
				{
					if(wovel(c,d))
					return 4;
					else
					return 3;
				}
			}	
		}
		else
		{
			if(isconsonent(b)&&b!=0&&extra(b))
			{
				if(a=='k')
				printf("%lc%lc",retIndicChar(21),retIndicChar(77));//k
				if(a=='g')
				printf("%lc%lc",retIndicChar(23),retIndicChar(77));//g
				if(a=='j')
				printf("%lc%lc",retIndicChar(28),retIndicChar(77));//j
				if(a=='p')
				printf("%lc%lc",retIndicChar(42),retIndicChar(77));//p
				if(a=='b')
				printf("%lc%lc",retIndicChar(44),retIndicChar(77));//b
				return 1;
			}
			else
			{
				if(a=='k')
				printf("%lc",retIndicChar(21));//k
				if(a=='g')
				printf("%lc",retIndicChar(23));//g
				if(a=='j')
				printf("%lc",retIndicChar(28));//j
				if(a=='p')
				printf("%lc",retIndicChar(42));//j
				if(a=='b')
				printf("%lc",retIndicChar(44));//j
				if(!extra(b))
				return 1;
				if(isconsonent(c))
				{
					wovel(b,0);
					return 2;
				}
				else
				{
					if(wovel(b,c))
					return 3;
					else
					return 2;
				}
			}
		}
	}
	else if(a=='t'||a=='d'||a=='s')
	{
		if(b=='h')
		{
			if(isconsonent(c)&&c!=0&&extra(c))
			{
				if(a=='t')
				printf("%lc%lc",retIndicChar(37),retIndicChar(77));//th
				if(a=='d')
				printf("%lc%lc",retIndicChar(39),retIndicChar(77));//dh
				if(a=='s')
				printf("%lc%lc",retIndicChar(54),retIndicChar(77));//sh
				return 2;
			}
			else
			{
				if(a=='t')
				printf("%lc",retIndicChar(37));//th
				if(a=='d')
				printf("%lc",retIndicChar(39));//dh
				if(a=='s')
				printf("%lc",retIndicChar(54));//sh
				if(!extra(c))
				return 2;
				
				if(isconsonent(d))
				{
					
					wovel(c,0);
					return 3;
				}
				else
				{
					if(wovel(c,d))
					return 4;
					else
					return 3;
				}
			}	
		}
		else if((b=='t'&&a!='s'&&a!='d')||(b=='d'&&a!='t'&&a!='s')||(b=='s'&&a!='t'&&a!='d'))//
		{
			if(c=='h')
			{
				if(isconsonent(d)&&d!=0&&extra(d))
				{
					if(a=='t')
					printf("%lc%lc",retIndicChar(32),retIndicChar(77));//th
					if(a=='d')
					printf("%lc%lc",retIndicChar(34),retIndicChar(77));//dh
					if(a=='s')
					printf("%lc%lc",retIndicChar(55),retIndicChar(77));//sh
					return 3;
				}
				else
				{
					if(a=='t')
					printf("%lc",retIndicChar(32));//th
					if(a=='d')
					printf("%lc",retIndicChar(34));//dh
					if(a=='s')
					printf("%lc",retIndicChar(55));//sh
					if(!extra(d))
					return 3;
					if(isconsonent(e))
					{
					
						wovel(d,0);
						return 4;
					}
					else
					{
						if(wovel(d,e))
						return 5;
						else
						return 4;
					}
				}	
			}
			else
			{
				if(isconsonent(c)&&c!=0&&extra(c))
				{
					if(a=='t')
					printf("%lc%lc",retIndicChar(31),retIndicChar(77));//th
					if(a=='d')
					printf("%lc%lc",retIndicChar(33),retIndicChar(77));//dh
					return 2;
				}
			
				else
				{
					if(a=='t')
					printf("%lc",retIndicChar(31));//th
					if(a=='d')
					printf("%lc",retIndicChar(33));//dh
					if(!extra(c))
					return 2;
					if(isconsonent(d))
					{
						wovel(c,0);
						return 3;
					}
					else
					{
						if(wovel(c,d))
						return 4;
						else
						return 3;
					}
				}
			}		
		}
		else
		{
			if(isconsonent(b)&&b!=0&&extra(b))
			{
				if(a=='t')
				printf("%lc%lc",retIndicChar(36),retIndicChar(77));//th
				if(a=='d')
				printf("%lc%lc",retIndicChar(38),retIndicChar(77));//dh
				if(a=='s')
				printf("%lc%lc",retIndicChar(56),retIndicChar(77));//sh
				return 1;
			}
			
			else
			{
				if(a=='t')
				printf("%lc",retIndicChar(36));//th
				if(a=='d')
				printf("%lc",retIndicChar(38));//dh
				if(a=='s')
				printf("%lc",retIndicChar(56));//sh
				if(!extra(b))
				return 1;
				if(isconsonent(c))
				{
					wovel(b,0);
					return 2;
				}
				else
				{
					if(wovel(b,c))
					return 3;
					else
					return 2;
				}
			}
		}
	}
	else if(a=='n')
	{
		if(b=='y')
		{
			if(isconsonent(c)&&c!=0&&extra(c))
			{
				printf("%lc%lc",retIndicChar(30),retIndicChar(77));//p
				return 2;
			}
			else
			{
				printf("%lc",retIndicChar(30));
				if(!extra(c))
				return 2;
				if(isconsonent(d))
				{
					wovel(c,0);
					return 3;
				}
				else
				{
					if(wovel(c,d))
					return 4;
					else
					return 2;
				}
			}
		}
		if(b=='n')
		{
			if(isconsonent(c)&&c!=0&&extra(c))
			{
				printf("%lc%lc",retIndicChar(35),retIndicChar(77));//p
				return 2;
			}
			else
			{
				printf("%lc",retIndicChar(35));
				if(!extra(c))
				return 2;
				if(isconsonent(d))
				{
					wovel(c,0);
					return 3;
				}
				else
				{
					if(wovel(c,d))
					return 4;
					else
					return 2;
				}
			}
		}
		else if(isconsonent(b)&&b!=0&&extra(b))
		{
			printf("%lc%lc",retIndicChar(40),retIndicChar(77));//p
			return 1;
		}
		else
		{
			printf("%lc",retIndicChar(40));
			if(!extra(b))
			return 1;
			if(isconsonent(c))
			{
				wovel(b,0);
				return 2;
			}
			else
			{
				if(wovel(b,c))
				return 3;
				else
				return 2;
			}
		}
	}
	else if(a=='m'||a=='y'||a=='r'||a=='l'||a=='w'||a=='v'||a=='h'||a=='f'||a=='q'||a=='z')
	{
		if(isconsonent(b)&&b!=0&&extra(b))
		{
			if(a=='m')
			printf("%lc%lc",retIndicChar(46),retIndicChar(77));//m
			if(a=='y')
			printf("%lc%lc",retIndicChar(47),retIndicChar(77));//m
			if(a=='r')
			printf("%lc%lc",retIndicChar(48),retIndicChar(77));//m
			if(a=='l')
			printf("%lc%lc",retIndicChar(50),retIndicChar(77));//m
			if(a=='h')
			printf("%lc%lc",retIndicChar(57),retIndicChar(77));//m
			if(a=='f')
			printf("%lc%lc",retIndicChar(94),retIndicChar(77));//m
			if(a=='q')
			printf("%lc%lc",retIndicChar(88),retIndicChar(77));//m
			if(a=='z')
			printf("%lc%lc",retIndicChar(91),retIndicChar(77));//m
			if(a=='w'||a=='v')
			printf("%lc%lc",retIndicChar(53),retIndicChar(77));//m
			return 1;
		}
		else
		{
			if(a=='m')
			printf("%lc",retIndicChar(46));//m
			if(a=='y')
			printf("%lc",retIndicChar(47));//m
			if(a=='r')
			printf("%lc",retIndicChar(48));//m
			if(a=='l')
			printf("%lc",retIndicChar(50));//m
			if(a=='h')
			printf("%lc",retIndicChar(57));//m
			if(a=='f')
			printf("%lc",retIndicChar(94));//m
			if(a=='q')
			printf("%lc",retIndicChar(88));//m
			if(a=='z')
			printf("%lc",retIndicChar(91));//m
			if(a=='w'||a=='v')
			printf("%lc",retIndicChar(53));//m
			if(!extra(b))
			return 1;
			if(isconsonent(c))
			{
				wovel(b,0);
				return 2;
			}
			else
			{
				if(wovel(b,c))
				return 3;
				else
				return 2;
			}
		}
	}
	else if(a=='c')
	{
		if(b=='h')
		{
			if(c=='h')
			{
				
				if(isconsonent(d)&&d!=0&&extra(d))
				{
					printf("%lc%lc",retIndicChar(27),retIndicChar(77));//m
					return 3;
				}
				else
				{
					printf("%lc",retIndicChar(27));
					if(!extra(d))
					return 3;
					if(isconsonent(e))
					{
						
						wovel(d,0);
						return 4;
					}
					else
					{
						if(wovel(d,e))
						return 5;
						else
						return 4;
					}
					
				}
				
			}
			else if(isconsonent(c)&&c!=0&&extra(c))
			{
				printf("%lc%lc",retIndicChar(26),retIndicChar(77));//m
				return 2;
			}
			else
			{
				printf("%lc",retIndicChar(26));
				if(!extra(c))
				return 2;
				if(isconsonent(d))
				{
					wovel(c,0);
					return 3;
				}	
				else
				{
					if(wovel(c,d))
					return 4;
					else
					return 3;
				}
				
			}
		}
		else
		{
			return 1;
		}
		
	}
	else if(!isconsonent(a))
	{
		if(isconsonent(b))
		{
			swar(a,0);
			return 1;
		}
		else
		{
			swar(a,b);
			return 2;
		}
	}
	else if(a=='<')
	{
		if(c=='>')
		{
			if(b=='.')
			printf("%lc",retIndicChar(2));
			if(b==':')
			printf("%lc",retIndicChar(3));
			if(b=='r')
			printf("%lc",retIndicChar(68));
			if(b=='h')
			printf("%lc",retIndicChar(77));
			if(b=='n')
			printf("%lc",retIndicChar(60));
			if(!isconsonent(b))
			{
				wovel(b,0);
			}
			return 3;
		}
		else if(d=='>')
		{
			if(b=='('&&c=='.')
			printf("%lc",retIndicChar(1));
			if(b=='m'&&c=='u')
			printf("%lc",retIndicChar(73));
			if(b=='o'&&c=='m')
			printf("%lc",retIndicChar(80));
			if(b=='g'&&c=='y')
			{
				printf("ज्ञ");
			}
			if(b=='r'&&c=='i')
			{
				printf("ऋ");
			}
			if(!isconsonent(b)&&!isconsonent(c))
			{
				wovel(b,c);
			}
			
			return 4;
		
		}
		
		else
		{
			printf("code error in '< >'");
			exit(1);
		}	
	}
	else
	{
		printf("%c",a);
		return 1;
	}
	return 0;
}
void str_tolower(char *s)
{
    while(*s)
    {
        *s=tolower(*s);
        s++;
    }
}
wchar_t *retWord(char *word)
{
	int wordlen,i=0;
	wordlen=strlen(word);
	str_tolower(word);
	while(i<wordlen)
	{
		if(i+4<=wordlen)
		i=i+tackle(word[i],word[i+1],word[i+2],word[i+3],word[i+4]);
		else if(i+3<=wordlen)
		i=i+tackle(word[i],word[i+1],word[i+2],word[i+3],0);
		else if(i+2<=wordlen)
		i=i+tackle(word[i],word[i+1],word[i+2],0,0);
		else if(i+1<=wordlen)
		i=i+tackle(word[i],word[i+1],0,0,0);
		else
		i=i+tackle(word[i],0,0,0,0);
	}
	return 0;
}
