#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,map[26],count;
	char d,string[400],input;
	scanf("%d%c",&t,&d);
	while(t--)
	{
		gets(string);
		for(i=0;i<26;i++)
			map[i]=0;
		for(i=0;string[i];i++)
		{
			if(string[i]>='a'&&string[i]<='z')
				map[string[i]-'a']=1;
			else if(string[i]>='A'&&string[i]<='Z')
				map[string[i]-'A']=1;
		}
		for(i=0;i<26;i++)
			if(!map[i])
			{
				printf("%c",i+'a');
				count++;
			}
		if(!count)
			printf("~");
		printf("\n");
	}
	return 0;
}
