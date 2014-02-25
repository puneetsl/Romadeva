/*
Copyright (C) 2009  Puneet Singh

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

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
    r=malloc(file_length(f)+1);
    fread(r,file_length(f),1,f);
    rewind(f);
    r[strlen(r)-1]=0;
    return r;
}
int total_Lines(FILE *f)
{
    int line=0,i,t;
    t=file_length(f);
    fseek(f,0,0);
    for(i=0;i<t;i++)
    {
    	if(fgetc(f)=='\n')
    	line++;
    }
    
    return line+1;
}
char *flineParser(FILE *f,int lineNo)
{
    char *fileContents;
    char *retLine;
    int k=0,i,j=0,curLine=1,lineLength=0;
    fileContents=readfilestr(f);
    for (i=0;i<strlen(fileContents);i++)
    {
        if (fileContents[i]=='\n')
            curLine+=1;
        if (lineNo==curLine)
        {
            if (j==0)
            {
                j=i;

            }
            lineLength+=1;
        }
    }

    if (lineNo==1)
        j=j-2;
    retLine=malloc(lineLength+1);
    for (i=j+1;i<lineLength+j;i++)
    {
        retLine[k]=fileContents[i];
        k+=1;
    }
    if (lineNo==1)
    {
    retLine[k]=fileContents[i];
    retLine[k+1]=0;
    }
    else
    retLine[k]=0;
    //printf("this is in fun]%s",retLine);
    return retLine;
}
char* optimizeStr(char *str)//remove white spaces
{
    char *temp;
    int i=0,j=0;
    int space=0,enter=0,tab=0;
    temp=malloc(strlen(str));
    while (1)
    {
        if (i==strlen(str)+1)
        {
            break;
        }
        if ((str[i-1]==' '||str[i-1]=='\t'||str[i-1]=='\n')&&i>1&&(str[i]==' '||str[i]=='\t'))
        {
            i++;
            continue;
        }
        if (str[i]=='\t'&&(str[i-1]!=' '||str[i-1]!='\t'||str[i-1]!='\n'))
        {
            temp[j]=' ';
            i++;
            j++;
            continue;
        }

        if (str[i]==' '&&(str[i-1]!=' '||str[i-1]!='\t'||str[i-1]!='\n'))
        {
            temp[j]=' ';
            i++;
            j++;
            continue;
        }

        temp[j]= str[i];
        i++;
        j++;
    }
    temp[j]=0;
    return temp;
}
char* commentRemover(char *str)
{
    char *temp;
    int i=0,j=0;
    int slash=0,slashstar=0,tab=0;
    temp=malloc(strlen(str));
    while (1)
    {
        if (i==strlen(str)+1)
        {
            break;
        }

        if (str[i]=='/')
        {
            if (str[i+1]=='/')
            {
                while (str[i]!='\n')
                {
                    i++;
                }
            }
            if (str[i+1]=='*')
            {
                while (1)
                {
                    if (str[i]=='*'&&str[i+1]=='/')
                    {
                        i=i+2;
                        break;
                    }

                    i++;
                }
            }

        }
        temp[j]=str[i];
        i++;
        j++;
    }

    temp[j]=0;
    return temp;
}
char *uselessLineRemover(char *str)
{
    char *temp;
    int i=0,j=0;
    temp=malloc(strlen(str));
    while (1)
    {
        if (i==strlen(str)+1)
        {
            break;
        }
        if (str[i]=='\n'&&(str[i-1]=='\n'||i==0))
        {
            i++;
            continue;
        }
        temp[j]=str[i];
        i++;
        j++;
    }
    temp[j]=0;
    return temp;
}
char *wordParse(char *str,int wordNo,char c)
{
    char *retWord;
    int k=0,i=0,j=0,curWord=1,wordLength=0;
    while (i<strlen(str)+1)
    {

        if (str[i]==c)
        {
            curWord++;
            i++;
        }
        if (curWord==wordNo)
        {
            k=i;//stamp the char number
            while (str[i]!=c&&str[i]!=0)
            {
                wordLength++;
                i++;
            }
            retWord=malloc(wordLength+1);
            if (i!=k)
                i=k;
            while (str[i]!=c&&str[i]!='\0')
            {
                retWord[j]=str[i];
                j++;
                i++;
                retWord[j]=0;


            }
            break;
        }
        i++;
    }
    return retWord;
}
int countWords(char *str,char c)
{
    int i=0,j=0;
    while (i!=(strlen(str)+1))
    {
        if (str[i]==c)
            j++;
        i++;
    }
    return j+1;
}
char **strParser(char *str,char c)
{
    //this function will parse string and even will remove white spaces i.e. ' ','\n','\t'
    int i=0,j=0,words;
    char **retstr,*tempword;
    words=countWords(str,c);
    retstr=malloc(words);
    for (i=1;i<=words;i++)
    {
        tempword=wordParse(str,i,c);
        retstr[i-1]=malloc(strlen(tempword)+1);
        strcpy(retstr[i-1],tempword);

    }
    return retstr;
}
char *strInBetween(char *in,char start,char end){
    int i=0,j=0,flag=0;
    char *temp;


    while(i!=strlen(in)||in[i]!='\0')
    {

        if(in[i-1]==start)
        {
            flag=1;
        }
        if(flag==1)
        {
            j++;
        }
        if(in[i+1]==end&&flag==1)
        {
            break;
        }
        i++;
    }
    temp=malloc(j);
    i=j=flag=0;
    while(i!=strlen(in)||in[i]!='\0')
    {

        if(in[i-1]==start)
        {
            flag=1;
        }
        if(flag==1)
        {
            temp[j]=in[i];
            j++;
        }
        if(in[i+1]==end&&flag==1)
        {
            temp[j]='\0';
            return temp;
        }
        i++;
    }

}
int strCheck(char *in,char *ch){
    int i=0,j=0,flag=0;
    char *temp;


    while(i!=strlen(in)||in[i]!='\0')
    {
        if(in[i]==ch[j])
        {flag=1;}
        if(flag==1)
        {
            flag=0;
            if(j==(strlen(ch)-1)||ch[j]=='\0')
            return 1;
            if(in[i]!=ch[j])
            return 0;

            j++;
        }
        i++;
    }
    return 0;
}
char *btrFlineParser(FILE *f,int lineNo)
{
    char *retLine;
    int k=0,i,j=0,curLine=1,lineLength=0,flen;
   fseek(f,0,0);
   flen=file_length(f);
   for (i=0;i<flen;i++)
    {
        if (fgetc(f)=='\n')
            curLine+=1;
        if (lineNo==curLine)
        {
            if (j==0)
            {
                j=i;

            }
            lineLength+=1;
        }
    }

    if (lineNo==1)
        j=j-2;
    retLine=malloc(lineLength+1);
    for (i=j+1;i<lineLength+j;i++)
    {
        fseek(f,0,0);
        fseek(f,i,0);
        retLine[k]=fgetc(f);
        k+=1;
    }
    if (lineNo==1)
    {
    retLine[k]=fgetc(f);
    retLine[k+1]=0;
    }
    else
    retLine[k]=0;
    //printf("this is in fun]%s",retLine);
    return retLine;
}

