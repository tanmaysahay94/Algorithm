#include<stdio.h>
#include<string.h>
int main()
{
	int t,i,s;
	char c[1000];
	scanf("%d",&t);
	while(t--)
	{
		s=0;
		scanf("%s",c);
		for(i=0;c[i];i++)
			s+=c[i];
		printf("%c\n",(char)(s/strlen(c)));
	}
	return 0;
}
