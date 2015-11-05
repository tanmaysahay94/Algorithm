#include<stdio.h>
#include<string.h>
int main()
{
	int t,n,i,count;
	char c,dir[40][10],rd[40][100],temp[100];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		count=0;
		scanf("%s on ",dir[0]);
		scanf("%c",&c);
		while(c!='\n')
		{
			rd[n-1][count++]=c;
			scanf("%c",&c);
		}
		rd[n-1][count]='\0';
		for(i=1;i<n;i++)
		{
			count=0;
			scanf("%s on ",temp);
			if(!strcmp(temp,"Right"))
				strcpy(dir[n-i],"Left");
			else if(!strcmp(temp,"Left"))
				strcpy(dir[n-i],"Right");
			scanf("%c",&c);
			while(c!='\n')
			{
				rd[n-i-1][count++]=c;
				scanf("%c",&c);
			}
			rd[n-i-1][count]='\0';
		}
		for(i=0;i<n;i++)
			printf("%s on %s\n",dir[i],rd[i]);
	}
	return 0;
}
