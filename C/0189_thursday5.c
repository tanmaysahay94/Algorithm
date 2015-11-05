#include<stdio.h>
#include<string.h>
int main()
{
	int i,start,j,tSize=0,flag[50000]={0},f=0;
	char word[50000],text[50000],c;
	scanf("%s%c%c",word,&c,&c);
	while(c!='\n')
	{
		text[tSize++]=c;
		scanf("%c",&c);
	}
	int wSize=strlen(word);
	for(start=0;start<=tSize-wSize;start++)
	{
		f=1;
		for(j=start;j<start+wSize;j++)
		{
			if(text[j]!=word[j-start])
			{
				f=0;
				break;
			}
		}
		if(f)
			flag[start]=1;
	}
	i=0;
	while(i<tSize)
	{
		if(!flag[i])
		{
			printf("%c",text[i]);
			i++;
		}
		else
			i+=wSize;
	}
	printf("\n");
	return 0;
}
