#include<stdio.h>
int main()
{
	int t,i,c;
	char n[100007],dump;
	scanf("%d%c",&t,&dump);
	while(t--)
	{
		c=0;
		scanf("%s",n);
		for(i=0;n[i];i++)
			if(!(n[i]=='4'||n[i]=='7'))
				c++;
		printf("%d\n",c);
	}
	return 0;
}
