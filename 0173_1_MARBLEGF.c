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
	int n,q,i,s,t;
	char instruction;
	n=read();q=read();
	n++;
	int a,h[n];
	h[0]=0;
	for(i=1;i<n;i++)
	{
		a=read();
		h[i]=h[i-1]+a;
	}
	while(q--)
	{
		scanf("%c",&instruction);
		s=read();t=read();
		if(instruction=='S')
			printf("%d\n",h[++t]-h[s]);
		else if(instruction=='G')
			for(i=++s;i<n;i++)
				h[i]+=t;
		else if(instruction=='T')
			for(i=++s;i<n;i++)
				h[i]-=t;
	}
	return 0;
} 
