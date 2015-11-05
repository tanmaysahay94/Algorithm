#include<stdio.h>
inline int read()
{
	char c;
	int n=0;
	while((c=getchar_unlocked())<'0');
	n+=(c-'0');
	while((c=getchar_unlocked())>='0')
		n=n*10+(c-'0');
	return n;
}
int main()
{
	int t,g,i,n,q;
	t=read();
	while(t--)
	{
		g=read();
		while(g--)
		{
			i=read();n=read();q=read();
			if(n%2&&i!=q)
				printf("%d\n",n/2+1);
			else
				printf("%d\n",n/2);
		}
	}
	return 0;
}
