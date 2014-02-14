#include<stdio.h>
inline int read()
{
	int n=0;
	char c;
	while((c=getchar_unlocked())<'0');
	n+=(c-'0');
	while((c=getchar_unlocked())>='0')
		n=n*10+(c-'0');
	return n;
}
int main()
{
	int t,n,x,l,f,time,wait,i;
	t=read();
	while(t--)
	{
		n=read();
		time=0;
		for(i=0;i<n;i++)
		{
			x=read();
			l=read();
			f=read();
			if(time<x)
				time=x;
			else if(time>x)
			{
				wait=(time-x)/f;
				if((time-x)%f)
					wait++;
				time=x+wait*f;		//basically, Euclid division algorithm.
			}
			time+=l;
		}
		printf("%d\n",time);
	}
	return 0;
}
