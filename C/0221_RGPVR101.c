#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	int lenS,t,i,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		lenS=strlen(s);
		mid=lenS/2;
		for(i=mid-1;i>=0;i--)
			printf("%c",s[i]);
		for(i=lenS-1;i>=mid;i--)
			printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
