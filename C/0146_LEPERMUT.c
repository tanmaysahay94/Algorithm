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
	int t,n,a[110],i,j,localInv,totalInv;
	t=read();
	while(t--)
	{
		localInv=totalInv=0;
		n=read();
		a[0]=read();
		for(i=1;i<n;i++)
		{
			a[i]=read();
			if(a[i]<a[i-1])
				localInv++;
		}
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(a[i]>a[j])
					totalInv++;
		if(localInv==totalInv)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
