#include<stdio.h>
inline int read()
{
	int n=0;
	char c;
	while((c=getchar_unlocked())<'0');
	n+=c-'0';
	while((c=getchar_unlocked())>='0')
		n=(n<<3)+(n<<1)+c-'0';
	return n;
}
int main()
{
	int n,q,s,t,i,out;
	char instruction;
	n=read();q=read();
	int a[n],total=0;
	for(i=0;i<n;i++)
	{
		*(a+i)=read();
		total+=a[i];
	}
	while(q--)
	{
		out=0;
		scanf("%c",&instruction);
		s=read();t=read();
		if(instruction=='G')
		{
			total+=t;
			a[s]+=t;
		}
		else if(instruction=='T')
		{
			total-=t;
			a[s]-=t;
		}
		else if(instruction=='S')
		{
			if(t-s+1<=n/2)
				for(i=t;i>=s;--i)
					out+=a[i];
			else
			{
				out=total;
				for(i=s-1;i>=0;--i)
					out-=a[i];
				for(i=n-1;i>t;--i)
					out-=a[i];
			}
			printf("%d\n",out);
		}
	}
	return 0;
}
