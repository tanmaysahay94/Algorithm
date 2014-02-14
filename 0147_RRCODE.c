#include<stdio.h>
#include<string.h>
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
	int t,n,k,a,p[1010],i;
	char o[5];
	t=read();
	while(t--)
	{
		n=read();k=read();a=read();
		for(i=0;i<n;i++)
			p[i]=read();
		scanf("\n%s",o);
		if(!strcmp("OR",o))
		{
			if(k)
				for(i=0;i<n;i++)
					a|=p[i];
		}
		else if(!strcmp("AND",o))
		{
			if(k)
				for(i=0;i<n;i++)
					a&=p[i];
		}
		else if(!strcmp("XOR",o))
		{
			if(k&1)
				for(i=0;i<n;i++)
					a^=p[i];
		}
		printf("%d\n",a);
	}
	return 0;
}
