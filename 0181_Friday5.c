#include<stdio.h>
#include<string.h>
int main()
{
	char input,search[6000],para[6000];
	int f,start,paraLen=0,count=0,j;
	scanf("%s%c%c",search,&input,&input);
	while(input!='\n')
	{
		para[paraLen++]=input;
		scanf("%c",&input);
	}
	para[paraLen]='\0';
	int searchLen=strlen(search);
	for(start=0;start<=paraLen-searchLen;start++)
	{
		f=1;
		for(j=start;j<start+searchLen;j++)
			if(para[j]!=search[j-start])
			{
				f=0;
				break;
			}
		count+=f;
	}
	printf("%d\n",count);
	return 0;
}
