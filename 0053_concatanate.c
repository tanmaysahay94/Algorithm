#include<stdio.h>
void strca(char *a,char *b)
{
	while(*a)
		a++;
	while(*a++=*b++);
}
int main()
{
	char a[100],b[100];
	while(scanf("%s%s",a,b)!=EOF)
	{
		strca(a,b);
		printf("%s\n",a);
	}
	return 0;
}
