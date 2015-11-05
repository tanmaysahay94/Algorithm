#include<stdio.h>
#include<string.h>
typedef struct user
{
	char name[30],vote;
}user;
int cmp(const void *a,const void *b)
{
	return strcmp((*(user*)a).name,(*(user*)b).name);
}
int main()
{
	int t,n,i,v;
	char dump;
	user u[100];
	scanf("%d",&t);
	while(t--)
	{
		v=0;
		scanf("%d",&n);
		scanf("%c",&dump);
		for(i=0;i<n;i++)
			scanf("%s %c",u[i].name,&u[i].vote);
		qsort(u,n,sizeof(user),cmp);
		for(i=0;i<n-1;i++)
			if(strcmp(u[i].name,u[i+1].name))
			{
				if(u[i].vote=='+')
					v++;
				else if(u[i].vote=='-')
					v--;
			}
		if(u[i].vote=='+')
			v++;
		else if(u[i].vote=='-')
			v--;
		printf("%d\n",v);
	}
	return 0;
}
