#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct word
{
	char string[30];
	int frequency;
}word;
int cmp(const void *a,const void *b)
{
		return strcmp((*(word*)a).string,(*(word*)b).string);
}
int cmpNum(const void *a,const void *b)
{
		return (*(word*)b).frequency-(*(word*)a).frequency;
}
int main()
{
	int t,i,j,lenText=0,wc=0,wl,flag[500000]={0};
	char c,text[500000];
	word array[20000];
	scanf("%c",&c);
	while(c!='\n')
	{
		text[lenText++]=c;
		scanf("%c",&c);
	}
	text[lenText]='\0';
	t=strlen(text);
	i=1;
	flag[0]=1;
	while(i<t)
	{
		if(((text[i]>='a'&&text[i]<='z')||(text[i]>='A'&&text[i]<='Z'))&&text[i-1]==' ')
			flag[i]=1;
		i++;
	}
	for(i=0;i<t;i++)
		if(flag[i])
		{
			wl=0;
			j=i;
			while((text[j]>='a'&&text[j]<='z')||(text[j]>='A'&&text[j]<='Z'))
			{
				text[j]=tolower(text[j]);
				array[wc].string[wl++]=text[j];
				j++;
			}
			array[wc].string[wl]='\0';
			//strlwr(array[wc].string);
			wc++;
			wl=0;
		}
	qsort(array,wc,sizeof(word),cmp);
	word finalList[20000];
	int finalCount=0,fr=1;
	for(i=0;i<wc-1;i++)
	{
		if(!strcmp(array[i].string,array[i+1].string))
			fr++;
		else
		{
			strcpy(finalList[finalCount].string,array[i].string);
			finalList[finalCount].frequency=fr;
			fr=1;
			finalCount++;
		}
	}
	strcpy(finalList[finalCount].string,array[i].string);
	if(strcmp(array[wc-1].string,array[wc-2].string))
		finalList[finalCount].frequency=1;
	else
		finalList[finalCount].frequency=fr;
	finalCount++;
	qsort(finalList,finalCount,sizeof(word),cmpNum);
	for(i=0;i<finalCount;i++)
		printf("%s %d\n",finalList[i].string,finalList[i].frequency);
	return 0;
}
