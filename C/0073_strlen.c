#include<stdio.h>
int my_strlen(char*w)
{
	int n=0;
	while(*w++)
		n++;
	return n;
}
int main()
{
	char w[10000];
	scanf("%s",w);
	printf("%d\n",my_strlen(w));
	return 0;
}
