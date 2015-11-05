#include<stdio.h>
int my_strcmp(char*s,char*t)
{
	while(*s&&*t)
	{
		if(*s>*t)
			return 1;
		else if(*s<*t)
			return -1;
		s++;
		t++;
	}
	if(*s)
		return 1;
	else if(*t)
		return -1;
	else
		return 0;
}
int main()
{
	char a[10000],b[10000];
	while(scanf("%s%s",a,b))
		printf("%d\n",my_strcmp(a,b));
	return 0;
}
