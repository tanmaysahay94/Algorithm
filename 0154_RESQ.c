#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==1)
			printf("0\n");
		else if(n==2)
			printf("1\n");
		else if(n==3)
			printf("2\n");
		else if(n==4)
			printf("0\n");
		else
		{
			s=sqrt(n);
			while(s)
			{
				if(!(n%s))
					break;
				s--;
			}
			printf("%d\n",n/s-s);
		}
	}
	return 0;
}
