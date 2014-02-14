#include<stdio.h>
int C(int n,int r)
{
	if(n==r||!r)
		return 1;
	else
		return C(n-1,r)+C(n-1,r-1);
}
int main()
{
	int x,n,seat,available,compartment,c,b,ways=0;
	char a[60];
	scanf("%d%d",&x,&n);
	while(n--)
	{
		scanf("%s",a);
		if(x<=6)
		{
			for(compartment=0;compartment<9;compartment++)
			{
				available=0;
				c=4*compartment;
				for(seat=c;seat<=c+3;seat++)
					available+=(a[seat]=='0');
				b=53-2*compartment;
				for(seat=b;seat>b-2;seat--)
					available+=(a[seat]=='0');
				if(available>=x)
					ways+=C(available,x);
			}
		}
	}
	printf("%d\n",ways);
	return 0;
} 
