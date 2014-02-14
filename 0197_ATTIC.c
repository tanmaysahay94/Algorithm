#include<stdio.h>
int main()
{
	int t,c,d,m;
	char dump,f;
	scanf("%d%c",&t,&dump);
	while(t--)
	{
		m=c=d=0;
		scanf("%c",&f);
		while(f=='.'||f=='#')
		{
			if(f=='.')
				c++;
			else
			{
				if(m<c)
				{
					m=c;
					d++;
				}
				c=0;
			}
			scanf("%c",&f);
			if(f=='\n'||f=='\t'||f==' ')
			{
				if(m<c)
				{
					m=c;
					d++;
				}
				c=0;
			}
		}
		printf("%d\n",d);
	}
	return 0;
}
