#include<stdio.h>
int main()
{
	int t,n,n4,n7;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n4=n-(n%7);			//now n4 is always a multiple of 7
		n7=n-n4;
		while(n7%4)			//while n7 is not a multiple of 4
		{
			n4-=7;			//n4 remains a multiple of 7
			n7=n-n4;
			if(n4<0)
				break;
		}
		if(n4<0)
			printf("-1\n");
		else
			printf("%d\n",n4);
	}
	return 0;
}
