#include<stdio.h>
#include<string.h>
int my_strcmp(char *first,char *second)
{
	int k;
	while(*first!='\0'&&*second!='\0')
	{
		if(*first==*second)
		{
			first++;
			second++;
		}
		else if(*first<*second)
			return -1;
		else 
			return 1;
	}
	k=strlen(first)-strlen(second);
	if(k)
	{
		if(k<0)
			return -1;
		else
			return 1;
	}
	else
		return 0;
}
int main()
{
	char a[100],b[100];
	while(scanf("%s%s",a,b)!=EOF)
		printf("%d\n",my_strcmp(a,b));
	return 0;
}
